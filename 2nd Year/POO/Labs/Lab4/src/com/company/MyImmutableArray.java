package com.company;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class MyImmutableArray {
    private final ArrayList<Integer> immutableArray;

    public MyImmutableArray(ArrayList<Integer> immutableArray) {
        this.immutableArray = new ArrayList<Integer>();
        this.immutableArray.addAll(immutableArray);
    }

    public List<Integer> getArray(){
        return (List<Integer>) Collections.unmodifiableList(this.immutableArray);
    }

    public String toString(){
        return "MyImmutableArray{" + "immutableArray" + immutableArray + "}";
    }
}

