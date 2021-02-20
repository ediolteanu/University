package com.company;

public class Point {
    private float x, y;

    public Point(float x, float y){
        this.x = x;
        this.y= y;

    }
    public void changeChords(float a, float b){
        x = a;
        y = b;
    }
    public void show(){
        System.out.println("(" + x + "," + y + ")");
    }
}
