package com.company;

public class MyVector3 implements Sumabil<MyVector3> {
    double[] vector = new double[3];

    public MyVector3(double v, double v1, double v2) {
        vector[0] = v;
        vector[1] = v1;
        vector[2] = v2;
    }
    public MyVector3(){
        vector[0] = 0;
        vector[1] = 0;
        vector[2] = 0;
    }

    public double[] getVector() {
        return vector;
    }

    @Override
    public void addValue(MyVector3 value) {
        for (int i = 0; i < 3; i++) {
            vector[i] += value.getVector()[i];
        }
    }
}
