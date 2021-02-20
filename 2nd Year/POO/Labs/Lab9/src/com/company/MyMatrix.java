package com.company;

public class MyMatrix implements Sumabil<MyMatrix> {
    private int[][] matrix = new int[4][4];

    public int[][] getMatrix() {
        return matrix;
    }

    public void setMatrix(int[][] matrix) {
        this.matrix = matrix;
    }

    @Override
    public void addValue(MyMatrix value) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                matrix[i][j] += value.getMatrix()[i][j];
            }
        }
    }
}
