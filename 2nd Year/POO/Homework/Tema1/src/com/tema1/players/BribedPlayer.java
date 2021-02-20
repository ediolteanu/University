package com.tema1.players;

import com.tema1.common.Constants;
import com.tema1.goods.Goods;
import com.tema1.goods.GoodsType;

import java.util.ArrayList;

public class BribedPlayer extends BasePlayer {
    public BribedPlayer(final int index) {
        super(index);
    }
    /*
    @return Numarul de iteme ilegale din sac.
     */
    private int getIllegalGoodsNo(final ArrayList<Goods> bag) {
        int counter = 0;
        for (Goods good : bag) {
            if (good.getType() == GoodsType.Illegal) {
                counter++;
            }
        }
        return counter;
    }
    /*
        @param Numarul de runde.
        Creeaza sacul dupa regulile din cerinta.
     */
    public final void createBag(final int roundNo) {
        if ((getIllegalGoodsNo(getIndrawnCards()) > 0)
                && (getCoins() > Constants.getMinBribeCoins())) {
            int maxPenalty = 0;
            ArrayList<Goods> bag = getBag();
            ArrayList<Goods> indrawnCards = getIndrawnCards();

            while ((bag.size() < Constants.getMaxBagSize()) && (getIndrawnCards().size() > 0)) {
                int maxProfit = 0;
                int maxProfitGoodId = 0;
                for (Goods good : indrawnCards) {
                    if (maxProfit < good.getProfit()) {
                        maxProfit = good.getProfit();
                        maxProfitGoodId = good.getId();
                    } else if (maxProfit == good.getProfit()) {
                        if (good.getId() > maxProfitGoodId) {
                            maxProfitGoodId = good.getId();
                        }
                    }
                }

                for (Goods good : indrawnCards) {
                    if (good.getId() == maxProfitGoodId) {
                        bag.add(good);
                        indrawnCards.remove(good);
                        maxPenalty += good.getPenalty();
                        if (maxPenalty >= getCoins()) {
                            bag.remove(good);
                            maxPenalty -= good.getPenalty();
                        }
                        break;
                    }
                }
            }
            if (getIllegalGoodsNo(bag) <= 2) {
                setBribe(Constants.getMinBribe());
            } else {
                setBribe(Constants.getMaxBribe());
            }
            setDeclaredGood(0);
            setBag(bag);
        } else {
            super.createBag(roundNo);
        }
    }
    /*
    @return Lista de Integeri reprezentand id-ul jucatorilor care trebuie inspectati.
     */
    private ArrayList<Integer> getPlayersToInspect(final ArrayList<Player> players) {
        ArrayList<Integer> toBeInspected = new ArrayList<>();
        if (this.getOrderNo() == 0) {
            toBeInspected.add(players.size() - 1);
            toBeInspected.add(this.getOrderNo() + 1);
        } else if (this.getOrderNo() == (players.size() - 1)) {
            toBeInspected.add(this.getOrderNo() - 1);
            toBeInspected.add(0);
        } else {
            toBeInspected.add(this.getOrderNo() - 1);
            toBeInspected.add(this.getOrderNo() + 1);
        }
        return toBeInspected;
    }
    /*
        @param Lista de playeri si lista de carti din joc pentru accesare usoara.
        Inspecteaza toti sacii dupa regulile din cerinta pentru strategia Basic.
     */
    public final void inspectBags(final ArrayList<Player> players, final ArrayList<Goods> deck) {
        ArrayList<Integer> toBeInspected;
        toBeInspected = getPlayersToInspect(players);
        ArrayList<Player> playersToBeInspected = new ArrayList<>();
        ArrayList<Player> playersToGetBribeFrom = new ArrayList<>(players);

        for (Integer index : toBeInspected) {
            for (Player player : players) {
                if (player.getOrderNo() == index) {
                    playersToBeInspected.add(player);
                }
            }
        }
        for (Player player : players) {
            for (Integer index : toBeInspected) {
                if (player.getOrderNo() == index) {
                    playersToGetBribeFrom.remove(player);
                }
                if (player.getOrderNo() == this.getOrderNo()) {
                    playersToGetBribeFrom.remove(player);
                }
            }
        }

        super.inspectBags(playersToBeInspected, deck);

        for (Player player : playersToGetBribeFrom) {
            if (player.getBribe() > 0) {
                this.setCoins(this.getCoins() + player.getBribe());
                player.setCoins(player.getCoins() - player.getBribe());
                player.setBribe(0);
                player.getMerchantMarketStall().addAll(player.getBag());
                player.getBag().clear();
            } else {
                player.getMerchantMarketStall().addAll(player.getBag());
                player.getBag().clear();
            }
        }
    }

    public final String toString() {
        return getOrderNo() + " BRIBED " + getScore();
    }
}
