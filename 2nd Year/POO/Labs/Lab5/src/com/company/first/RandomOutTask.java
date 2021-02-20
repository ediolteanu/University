package com.company.first;

import java.util.Random;

public class RandomOutTask implements Task {
    private int number;
    public RandomOutTask(){
        Random gen = new Random();
        number = gen.nextInt();
    }
    @Override
    public void execute() {
        System.out.println(number);
    }
}
