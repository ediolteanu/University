package com.company;

public class Area {
    private CandyBag sacu;
    private int number;
    private String street;

    public Area() {
        sacu = new CandyBag();
        number = 0;
        street = null;
    }

    public Area(CandyBag sacu, int number, String street) {
        this.sacu = sacu;
        this.number = number;
        this.street = street;
    }

    public void getBirthdayCard(){
        System.out.println("Adresa:" + street + " " + number + "\nLa multi ani!\n");
        for (CandyBox candy : sacu.getCutie()) {
            /*if(candy instanceof Lindt){
                ((Lindt) candy).printLindtDim();
            }

            if(candy instanceof Baravelli){
                ((Baravelli) candy).printBaravelliDim();
            }

            if(candy instanceof ChocArmor){
                ((ChocArmor) candy).printChocArmorDim();
            }*/
            System.out.println(candy);
            candy.printDim();
        }

    }
}
