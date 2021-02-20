package com.company;

import java.util.Random;

public class PasswordMaker {
    private static int MAGIC_NUMBER = 13;
    private final String MAGIC_STRING = "skdjdhjfiojsdfqweaspm";
    private String name;

    private static PasswordMaker instance = null;
    private static int contor = 0;
    private PasswordMaker() {}

    private PasswordMaker(String name){
        this.name = name;
    }

    public static PasswordMaker getInstance(String name) {
        contor++;
        if(instance == null) {
            instance = new PasswordMaker(name);
        }
        return instance;
    }

    String getPassword(){
        RandomStringGenerator random = new RandomStringGenerator(MAGIC_NUMBER, MAGIC_STRING);
        Random rand = new Random();
        return random.next() + Integer.toString(name.length()) + Integer.toString(rand.nextInt(101));
    }
}
