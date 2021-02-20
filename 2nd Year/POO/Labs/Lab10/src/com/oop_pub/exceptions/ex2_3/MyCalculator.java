package com.oop_pub.exceptions.ex2_3;

import java.util.Collection;

public class MyCalculator implements Calculator {

    @Override
    public Double add(Double nr1, Double nr2) {
        if (nr1 == null || nr2 == null) {
            throw new NullParameterException();
        }
        if (nr1 == Double.POSITIVE_INFINITY || nr2 == Double.POSITIVE_INFINITY) {
            throw new OverflowException();
        }
        if (nr1 == Double.NEGATIVE_INFINITY || nr2 == Double.NEGATIVE_INFINITY) {
            throw new UnderflowException();
        }
        return nr1 + nr2;
    }

    @Override
    public Double divide(Double nr1, Double nr2) {
        if (nr1 == null || nr2 == null) {
            throw new NullParameterException();
        }
        return nr1 / nr2;
    }

    @Override
    public Double average(Collection<Double> numbers) {
        double sum = 0;
        for (Double nr : numbers) {
            if (nr == null) {
                throw new NullParameterException();
            }
            if (nr == Double.NEGATIVE_INFINITY) {
                throw new UnderflowException();
            }
            if (nr == Double.POSITIVE_INFINITY) {
                throw new OverflowException();
            }
            sum += nr;
        }
        return sum / numbers.size();
    }
}
