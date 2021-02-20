package com.oop_pub.exceptions.ex2_3;

import java.util.ArrayList;
import java.util.List;

public class MainEx2 {
    public static void main(String[] args) {
        // TODO: Initialize the calculator
        MyCalculator calculator = new MyCalculator();

        System.out.println(calculator.add(2d, 3d));
        System.out.println(calculator.divide(9d, 4d));
        System.out.println(calculator.average(List.of(1d, 2d, 3d, 4d)));

        System.out.println(calculator.add(2d, null));
        System.out.println(calculator.add(2d, Double.NEGATIVE_INFINITY));
        System.out.println(calculator.add(2d, Double.POSITIVE_INFINITY));

        System.out.println(calculator.divide(2d, null));
        System.out.println(calculator.divide(2d, Double.NEGATIVE_INFINITY));
        System.out.println(calculator.divide(2d, Double.POSITIVE_INFINITY));

        List<Double> list = new ArrayList<>();
        list.add(2d);
        list.add(3d);
        list.add(Double.NEGATIVE_INFINITY);
        list.add(Double.POSITIVE_INFINITY);
        list.add(null);
        System.out.println(calculator.average(list));
        System.out.println(calculator.average(list));
        System.out.println(calculator.average(list));
    }
    // TODO: Test edge cases that would throw exceptions
}
