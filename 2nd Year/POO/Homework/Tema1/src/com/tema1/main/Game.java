package com.tema1.main;

import com.tema1.common.Constants;
import com.tema1.goods.Goods;
import com.tema1.goods.LegalGoods;
import com.tema1.goods.IllegalGoods;
import com.tema1.goods.GoodsFactory;
import com.tema1.goods.GoodsType;
import com.tema1.players.Player;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Map;

public class Game {
    private ArrayList<Player> players;
    private static ArrayList<Goods> deck;
    private int roundsNo;
    private int sheriffNo;

    Game(final ArrayList<Player> players, final ArrayList<Goods> deck2, final int roundNo) {
        this.players = players;
        deck = deck2;
        this.roundsNo = roundNo;
    }

    private int getRoundsNo() {
        return roundsNo;
    }

    private void setSheriffNo(final int sheriffNo) {
        this.sheriffNo = sheriffNo;
    }

    private int getSheriffNo() {
        return sheriffNo;
    }

    private ArrayList<Goods> getDeck() {
        return deck;
    }

    public static void setDeck(final ArrayList<Goods> deck2) {
        deck = deck2;
    }

    /*
    Adauga pe taraba bonusurile itemelor ilegale.
     */
    final void addIllegalGoodsBonuses() {
        for (Player player : players) {
            ArrayList<Goods> bonusGoods = new ArrayList<>();
            for (Goods good : player.getMerchantMarketStall()) {
                if (good.getType() == GoodsType.Illegal) {
                    IllegalGoods illegalGood = (IllegalGoods) good;
                    for (Goods key : illegalGood.getIllegalBonus().keySet()) {
                        for (int i = 0; i < illegalGood.getIllegalBonus().get(key); i++) {
                            bonusGoods.add(key);
                        }
                    }
                }
            }
            player.getMerchantMarketStall().addAll(bonusGoods);
            bonusGoods.clear();
        }
    }

    /*
    "Vinde" toate bunurile si adauga la scor profitul total.
     */
    final void sellGoods() {
        for (Player player : players) {
            int marketStallCoins = 0;
            for (Goods good : player.getMerchantMarketStall()) {
                marketStallCoins += good.getProfit();
            }
            player.setScore(player.getCoins() + marketStallCoins);
        }
    }
    /*
    Adauga la scor bonusul pentru kind si queen.
     */
    final void addKingQueenBonuses(final GoodsFactory goodsFactory) {
        for (int i = 0; i <= Constants.getLastLegalGoodId(); i++) {
            Map<Player, Integer> countGoods = new HashMap<>();
            for (Player player : players) {
                countGoods.put(player, player.countGoodsById(i));
            }

            int maxGoodsNoKing = 0;
            int maxGoodsNoQueen = 0;
            Player playerKing = null;
            Player playerQueen = null;
            for (Player key : players) {
                if (countGoods.get(key) == 0) {
                    continue;
                }
                if (maxGoodsNoKing < countGoods.get(key)) {
                    playerQueen = playerKing;
                    maxGoodsNoQueen = maxGoodsNoKing;
                    playerKing = key;
                    maxGoodsNoKing = countGoods.get(key);
                } else if (maxGoodsNoQueen < countGoods.get(key)) {
                    maxGoodsNoQueen = countGoods.get(key);
                    playerQueen = key;
                }
            }

            LegalGoods legalGood = (LegalGoods) goodsFactory.getGoodsById(i);
            if (playerKing != null) {
                playerKing.setScore(playerKing.getScore() + legalGood.getKingBonus());
            }
            if (playerQueen != null) {
                playerQueen.setScore(playerQueen.getScore() + legalGood.getQueenBonus());
            }

        }
    }
    /*
    Ruleaza jocul dupa runde si subsrunde.
     */
    final void startGame() {
        if (roundsNo > Constants.getMaxRounds()) {
            System.out.println("Number of rounds is higher than 5!");
            return;
        }

        if (players.size() > Constants.getMaxPlayers()) {
            System.out.println("Number of players is higher than 7!");
            return;
        }

        for (int i = 0; i < getRoundsNo(); i++) {
            for (int j = 0; j < players.size(); j++) {
                for (Player player : players) {
                    if (j == player.getOrderNo()) {
                        setSheriffNo(j);
                    } else {
                        player.getIndrawnCards().clear();
                        player.drawCards(getDeck());
                        player.createBag(i + 1);
                    }
                }
                players.get(getSheriffNo()).inspectBags(players, deck);

            }
        }
    }

    private static class PlayerComparator implements Comparator<Player> {
        @Override
        public int compare(final Player p1, final Player p2) {
            return p2.getScore() - p1.getScore();
        }
    }
    /*
    Creeaza si afiseaza clasamentul, comparant scorul jucatorilor.
     */
    final void createRanking() {
        PlayerComparator playerComparator = new PlayerComparator();
        players.sort(playerComparator);

        for (Player player : players) {
            System.out.println(player);
        }
    }
}
