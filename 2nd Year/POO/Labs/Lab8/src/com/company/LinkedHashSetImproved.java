package com.company;

import java.util.*;

public class LinkedHashSetImproved extends TreeSet<Integer> {
    @Override
    public boolean add(Integer integer) {
        if (integer % 2 == 0) {
            return super.add(integer);
        }
        return false;
    }

    @Override
    public boolean addAll(Collection<? extends Integer> c) {
        ArrayList<Integer> list = new ArrayList<>();
        for (Integer integer : c) {
            if (integer % 2 == 0) {
                list.add(integer);
            }
        }
        return super.addAll(list);
    }
}
