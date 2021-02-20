package com.company;

public class Baravelli extends CandyBox {
    private float height, radius;

    Baravelli(){
        this.radius = 0;
        this.height = 0;
    }

    Baravelli(String f, String o, float r, float h){
        super(f, o);
        radius = r;
        height = h;
    }

    public float getVolume(){
        return height * (float)Math.PI * (radius * radius);
    }

    public String toString(){
        return "The" + super.getOrigin() + " " + super.getFlavour() + " has a volume " +  getVolume();
    }

    public void printBaravelliDim(){
        System.out.println("height: "+ height + "\nradius: " + radius + "\n");
    }

    public void printDim(){
        System.out.println("height: "+ height + "\nradius: " + radius + "\n");
    }
}
