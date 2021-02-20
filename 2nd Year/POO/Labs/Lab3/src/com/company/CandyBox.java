package com.company;

import java.util.Objects;

public class CandyBox {
    private String flavour;
    private String origin;

    CandyBox() {
        this.flavour = null;
        this.origin = null;
    }

    CandyBox(String f, String o) {
        flavour = f;
        origin = o;
    }

    public String getOrigin() {
        return origin;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        CandyBox candyBox = (CandyBox) o;
        return Objects.equals(flavour, candyBox.flavour) &&
                Objects.equals(origin, candyBox.origin);
    }

    public String getFlavour() {
        return flavour;
    }

    public float getVolume() {
        return 0;
    }

    public String toString(){
        return "Flavour: " + flavour + "\nOrigin: " + origin + "\n";
    }

    public void printDim(){ ;}
}
