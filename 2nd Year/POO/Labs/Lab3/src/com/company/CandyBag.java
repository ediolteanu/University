package com.company;

import java.util.ArrayList;

public class CandyBag {
    private ArrayList<CandyBox> cutie;

    CandyBag(){
        this.cutie = new ArrayList<>();
    }

    void addCandy(CandyBox c){
        cutie.add(c);
    }

    ArrayList<CandyBox> getCutie(){
        return this.cutie;
    }

    CandyBox getCandy(int i){
        return this.cutie.get(i);
    }

}
