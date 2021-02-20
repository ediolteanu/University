package com.tema1.main;

import com.tema1.goods.Goods;
import com.tema1.goods.GoodsFactory;
import com.tema1.players.BasePlayer;
import com.tema1.players.BribedPlayer;
import com.tema1.players.GreedyPlayer;
import com.tema1.players.Player;

import java.util.ArrayList;

public final class Main {
    private Main() {
        // just to trick checkstyle
    }

    public static void main(final String[] args) {
        GameInputLoader gameInputLoader = new GameInputLoader(args[0], args[1]);
        GameInput gameInput = gameInputLoader.load();
        /*
        Creearea listei de jucatori.
         */
        ArrayList<Player> players = new ArrayList<>(gameInput.getPlayerNames().size());
        int orderNo = 0;
        for (String playerName : gameInput.getPlayerNames()) {
            switch (playerName) {
                case "basic":
                    players.add(new BasePlayer(orderNo));
                    orderNo++;
                    break;
                case "greedy":
                    players.add(new GreedyPlayer(orderNo));
                    orderNo++;
                    break;
                case "bribed":
                    players.add(new BribedPlayer(orderNo));
                    orderNo++;
                    break;
                default:
                    break;
            }

        }

        GoodsFactory goodsFactory = GoodsFactory.getInstance();
        /*
        Creearea pachetului de carti.
         */
        ArrayList<Goods> deck = new ArrayList<>(gameInput.getAssetIds().size());
        for (int goodId : gameInput.getAssetIds()) {
            deck.add(goodsFactory.getGoodsById(goodId));
        }
        /*
        Apelarea metodelor ce ruleaza intregul joc.
         */
        Game game = new Game(players, deck, gameInput.getRounds());

        game.startGame();
        game.addIllegalGoodsBonuses();
        game.sellGoods();
        game.addKingQueenBonuses(goodsFactory);
        game.createRanking();
    }
}
