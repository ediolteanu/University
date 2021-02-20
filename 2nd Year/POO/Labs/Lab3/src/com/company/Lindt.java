package com.company;

public class Lindt extends CandyBox {
    private float lenght, width, height;

    Lindt(){
        this.lenght = 0;
        this.width = 0;
        this.height = 0;
    }

    Lindt(String f, String o, float l, float w, float h){
        super(f, o);
        lenght = l;
        width = w;
        height = h;
    }

    public float getVolume(){
        return lenght * width * height;
    }

    public String toString(){
        return "The" + super.getOrigin() + " " + super.getFlavour() + " has a volume " +  getVolume();
    }

    public void printLindtDim(){
        System.out.println("lenght: "+ lenght + "\nwidth: " + width + "\nheight: " + height + "\n");
    }

    public void printDim(){
        System.out.println("lenght: "+ lenght + "\nwidth: " + width + "\nheight: " + height + "\n");
    }
}
