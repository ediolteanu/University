package com.company;


import java.util.Collections;
import java.util.HashMap;

public class MyHashMap<Integer, T> {
    private HashMap<Integer, T> collection = new HashMap<>();

    public void put(Integer key, T value) {
        this.collection.put(key, value);
    }

    public T get(Integer key) {
        return this.collection.get(key);
    }
}
