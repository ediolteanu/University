package com.company;

public class ChocArmor extends CandyBox {
    private float length;

    ChocArmor(){
        length = 0;
    }

    ChocArmor(String f, String o, float l){
        super(f, o);
        length = l;
    }

    public float getVolume(){
        return length * length * length;
    }

    public String toString(){
        return "The" + super.getOrigin() + " " + super.getFlavour() + " has a volume " +  getVolume();
    }

    public void printChocArmorDim(){
        System.out.println("lenght: " + length + "\n");
    }

    public void printDim(){
        System.out.println("lenght: " + length + "\n");
    }
}
