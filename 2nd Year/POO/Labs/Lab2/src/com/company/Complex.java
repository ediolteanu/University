package com.company;

public class Complex {
    private int real, imaginary;

    public Complex(int real, int imaginary){
        this.real = real;
        this.imaginary = imaginary;
    }

    public Complex(){
        this(0,0);
    }

    public Complex(Complex c){
        this.real = c.real;
        this.imaginary = c.imaginary;
    }

}
