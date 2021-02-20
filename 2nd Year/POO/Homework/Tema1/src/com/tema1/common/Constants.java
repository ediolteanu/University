package com.tema1.common;

public final class Constants {
    private static final int START_COINS = 80;
    private static final int MAX_BAG_SIZE = 8;
    private static final int MAX_CARDS = 10;
    private static final int START_BRIBE = 0;
    private static final int MAX_ROUNDS = 5;
    private static final int MAX_PLAYERS = 7;
    private static final int MIN_COINS = 16;
    private static final int MIN_BRIBE_COINS = 5;
    private static final int LAST_LEGAL_GOOD_ID = 9;
    private static final int MIN_BRIBE = 5;
    private static final int MAX_BRIBE = 10;

    private Constants() {
        //just to trick checkstyle
    }

    public static int getMinBribeCoins() {
        return MIN_BRIBE_COINS;
    }

    public static int getMinBribe() {
        return MIN_BRIBE;
    }

    public static int getMaxBribe() {
        return MAX_BRIBE;
    }

    public static int getLastLegalGoodId() {
        return LAST_LEGAL_GOOD_ID;
    }

    public static int getMinCoins() {
        return MIN_COINS;
    }

    public static int getMaxPlayers() {
        return MAX_PLAYERS;
    }

    public static int getMaxRounds() {
        return MAX_ROUNDS;
    }

    public static int getStartBribe() {
        return START_BRIBE;
    }

    public static int getStartCoins() {
        return START_COINS;
    }

    public static int getMaxBagSize() {
        return MAX_BAG_SIZE;
    }

    public static int getMaxCards() {
        return MAX_CARDS;
    }
}
