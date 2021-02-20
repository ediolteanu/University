package com.company;

import java.util.ArrayList;

class Main {
    public static void main(String []args) {
        String name = "edi";
        PasswordMaker pass = PasswordMaker.getInstance(name);
        System.out.println(pass.getPassword());

        ArrayList<Integer> al = new ArrayList<>();
        al.add(1);
        al.add(3);
        al.add(5);

        MyImmutableArray imar = new MyImmutableArray(al);
        imar.getArray();

    }
}