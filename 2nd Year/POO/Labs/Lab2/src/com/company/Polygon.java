package com.company;

import java.util.ArrayList;

public class Polygon {
    private int n;
    private ArrayList<Point> coords;

    public Polygon(int n){
        this.n = n;
        this.coords = new ArrayList<Point>(n);
    }

    public Polygon(int[] vec){
        this(vec.length/2);
        for(int i = 0; i < vec.length; i += 2) {
            this.coords.add(new Point(vec[i], vec[i + 1]));
        }
    }
}
