package com.company;

public interface Sumabil<T extends Sumabil> {
    void addValue(T value);
}
