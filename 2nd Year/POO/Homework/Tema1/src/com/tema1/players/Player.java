package com.tema1.players;

import com.tema1.common.Constants;
import com.tema1.goods.Goods;
import com.tema1.goods.GoodsFactory;
import com.tema1.main.Game;

import java.util.ArrayList;


public abstract class Player {
    private int coins;
    private int score;
    private int bribe;
    private ArrayList<Goods> bag;
    private ArrayList<Goods> merchantMarketStall;
    private Goods declaredGood;
    private ArrayList<Goods> indrawnCards;
    private int orderNo;

    Player(final int index) {
        coins = Constants.getStartCoins();
        bribe = Constants.getStartBribe();
        bag = new ArrayList<>();
        merchantMarketStall = new ArrayList<>();
        declaredGood = null;
        indrawnCards = new ArrayList<>();
        orderNo = index;
    }

    final void setBag(final ArrayList<Goods> bag) {
        this.bag = bag;
    }

    final void setBribe(final int bribe) {
        this.bribe = bribe;
    }

    final void setDeclaredGood(final int declaredGoodId) {
        declaredGood = GoodsFactory.getInstance().getGoodsById(declaredGoodId);
    }

    final ArrayList<Goods> getBag() {
        return bag;
    }

    final int getBribe() {
        return bribe;
    }

    public final int getCoins() {
        return coins;
    }

    final void setCoins(final int coins) {
        this.coins = coins;
    }

    public final int getScore() {
        return score;
    }

    public final void setScore(final int score) {
        this.score = score;
    }

    public final int getOrderNo() {
        return orderNo;
    }

    public final ArrayList<Goods> getMerchantMarketStall() {
        return merchantMarketStall;
    }

    final Goods getDeclaredGood() {
        return declaredGood;
    }

    public final ArrayList<Goods> getIndrawnCards() {
        return indrawnCards;
    }

    /*
    Extrage numarul de carti specificat din pachet.
     */
    public final void drawCards(final ArrayList<Goods> deck) {
        ArrayList<Goods> deck2 = new ArrayList<>(deck);
        for (int i = 0; i < Constants.getMaxCards(); i++) {
            if (!deck2.isEmpty()) {
                indrawnCards.add(deck2.get(0));
                deck2.remove(0);
            }
        }
        Game.setDeck(deck2);
    }
    /*
    @return numarul de bunuri de tipul
     */
    public final int countGoodsById(final int goodId) {
        int counter = 0;
        for (Goods good : merchantMarketStall) {
            if (good.getId() == goodId) {
                counter++;
            }
        }
        return counter;
    }

    public void createBag(final int roundNo) {
    }

    public void inspectBags(final ArrayList<Player> players, final ArrayList<Goods> deck) {
    }


}
