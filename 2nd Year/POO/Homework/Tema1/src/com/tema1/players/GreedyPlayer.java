package com.tema1.players;

import com.tema1.common.Constants;
import com.tema1.goods.Goods;
import com.tema1.goods.GoodsType;
import com.tema1.main.Game;

import java.util.ArrayList;

public class GreedyPlayer extends BasePlayer {
    public GreedyPlayer(final int index) {
        super(index);
    }
    /*
        @param Numarul de runde.
        Creeaza sacul dupa regulile din cerinta.
     */
    public final void createBag(final int roundNo) {
        super.createBag(roundNo);
        if ((roundNo % 2 == 0) && (getBag().size() != Constants.getMaxBagSize())) {
            int maxProfit = 0;
            int maxProfitGoodId = 0;
            int counter = 0;
            for (Goods card : getIndrawnCards()) {
                if ((card.getType() == GoodsType.Illegal) && (card.getProfit() > maxProfit)) {
                    maxProfit = card.getProfit();
                    maxProfitGoodId = counter;
                }
                counter++;
            }
            if (maxProfit != 0) {
                getBag().add(getIndrawnCards().get(maxProfitGoodId));
            }
        }
    }
    /*
        @param Lista de playeri si lista de carti din joc pentru accesare usoara.
        Inspecteaza toti sacii dupa regulile din cerinta pentru strategia Basic.
     */
    public final void inspectBags(final ArrayList<Player> players, final ArrayList<Goods> deck) {
        ArrayList<Goods> deck2 = new ArrayList<>(deck);
        for (Player player : players) {
            if (this.getCoins() < Constants.getMinCoins()) {
                player.getMerchantMarketStall().addAll(player.getBag());
                player.setBribe(0);
                player.getBag().clear();
                continue;
            }

            if (player.getBribe() > 0) {
                this.setCoins(this.getCoins() + player.getBribe());
                player.setCoins(player.getCoins() - player.getBribe());
                player.setBribe(0);
                player.getMerchantMarketStall().addAll(player.getBag());
                player.getBag().clear();
                continue;
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
                }
            }
        }
        Game.setDeck(deck2);
    }

    public final String toString() {
        return getOrderNo() + " GREEDY " + getScore();
    }
}
