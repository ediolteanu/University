package com.tema1.players;

import com.tema1.common.Constants;
import com.tema1.goods.Goods;
import com.tema1.goods.GoodsType;
import com.tema1.main.Game;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;



public class BasePlayer extends Player {
    public BasePlayer(final int index) {
        super(index);
    }

    /*
        @param Numarul de runde.
        Creeaza sacul dupa regulile din cerinta.
     */
    public void createBag(final int roundNo) {
        ArrayList<Goods> bag = getBag();
        ArrayList<Goods> indrawnCards = getIndrawnCards();

        Map<Goods, Integer> countGoods = new HashMap<>();

        for (Goods card : indrawnCards) {
            countGoods.put(card, countGoods.getOrDefault(card, 0) + 1);
        }

        int maxGoodsNo = 0;
        ArrayList<Goods> highestFrequencyGoods = new ArrayList<>();
        for (Goods key : countGoods.keySet()) {
            if (key.getType() == GoodsType.Legal) {
                if (maxGoodsNo <= countGoods.get(key)) {
                    maxGoodsNo = countGoods.get(key);
                }
            }
        }
        for (Goods key : countGoods.keySet()) {
            if (key.getType() == GoodsType.Legal) {
                if (countGoods.get(key) == maxGoodsNo) {
                    highestFrequencyGoods.add(key);
                    setDeclaredGood(key.getId());
                }
            }
        }
        if (highestFrequencyGoods.size() == 0) {
            int maxProfit = 0;
            int maxProfitGoodId = 0;
            int counter = 0;
            for (Goods card : indrawnCards) {
                if (card.getProfit() > maxProfit) {
                    maxProfit = card.getProfit();
                    maxProfitGoodId = counter;
                }
                counter++;
            }
            setDeclaredGood(0);
            bag.add(indrawnCards.get(maxProfitGoodId));
            indrawnCards.remove(maxProfitGoodId);
            setBag(bag);
            return;
        }

        if (highestFrequencyGoods.size() > 1) {
            int maxProfit = 0;
            ArrayList<Goods> maxProfitGoods = new ArrayList<>();
            for (Goods good : highestFrequencyGoods) {
                if (maxProfit <= good.getProfit()) {
                    maxProfit = good.getProfit();
                    setDeclaredGood(good.getId());
                }
            }
            for (Goods good : highestFrequencyGoods) {
                if (maxProfit == good.getProfit()) {
                    maxProfitGoods.add(good);
                }
            }
            if (maxProfitGoods.size() > 1) {
                int maxId = 0;
                for (Goods good : maxProfitGoods) {
                    if (maxId < good.getId()) {
                        maxId = good.getId();
                        setDeclaredGood(good.getId());
                    }
                }
            }
        }

        for (Goods card : indrawnCards) {
            if (bag.size() < Constants.getMaxCards()) {
                if (card.getId() == getDeclaredGood().getId()) {
                    bag.add(card);
                }
            } else {
                break;
            }
        }
        setBag(bag);
    }

    /*
        @param Lista de playeri si lista de carti din joc pentru accesare usoara.
        Inspecteaza toti sacii dupa regulile din cerinta pentru strategia Basic.
     */
    public void inspectBags(final ArrayList<Player> players, final ArrayList<Goods> deck) {
        ArrayList<Goods> deck2 = new ArrayList<>(deck);
        for (Player player : players) {
            player.setBribe(0);
            if (this.getCoins() < Constants.getMinCoins()) {
                player.getMerchantMarketStall().addAll(player.getBag());
                player.getBag().clear();
            }

            if (player.getOrderNo() != this.getOrderNo()) {
                ArrayList<Goods> confiscatedGoods = new ArrayList<>();
                for (Goods good : player.getBag()) {
                    if ((good.getType() == GoodsType.Illegal)
                            || (good.getId() != player.getDeclaredGood().getId())) {
                        confiscatedGoods.add(good);
                    }
                }
                if (confiscatedGoods.isEmpty()) {
                    this.setCoins(this.getCoins() - player.getBag().size()
                            * player.getDeclaredGood().getPenalty());
                    player.setCoins(player.getCoins() + player.getBag().size()
                            * player.getDeclaredGood().getPenalty());
                    player.getMerchantMarketStall().addAll(player.getBag());
                    player.getBag().clear();
                } else {
                    for (Goods good : confiscatedGoods) {
                        this.setCoins(this.getCoins() + good.getPenalty());
                        player.setCoins(player.getCoins() - good.getPenalty());
                    }
                    player.getBag().removeAll(confiscatedGoods);
                    player.getMerchantMarketStall().addAll(player.getBag());
                    player.getBag().clear();
                    deck2.addAll(confiscatedGoods);
                    confiscatedGoods.clear();
                }
            }
        }
        Game.setDeck(deck2);
    }

    /*
    @return Afisarea conform cerintei.
     */
    public String toString() {
        return getOrderNo() + " BASIC " + getScore();
    }
}

