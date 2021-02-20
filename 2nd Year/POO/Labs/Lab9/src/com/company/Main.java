package com.company;

import java.util.ArrayList;
import java.util.Collection;
import java.util.List;

public class Main {

    public static void main(String[] args) {
        MyHashMap<Integer, Catalog> catalog = new MyHashMap<>();
        catalog.put(1, new Catalog("Alex", 9.9));
        catalog.put(2, new Catalog("Luci", 10));
        catalog.put(3, new Catalog("Edi", 9.0));

        for (int i = 1; i <= 3; i++) {
            System.out.println(catalog.get(i).hashCode() + " " + catalog.get(i).getName()
                    + " " + catalog.get(i).getGrade());
        }

        List<Sumabil> list = new ArrayList<>();

        MyVector3 v1 = new MyVector3(1.23, 2.34, 0.564);
        MyVector3 v2 = new MyVector3(0.99, 0.85, 2.34);
        MyVector3 v3 = new MyVector3(6.23, 2.123, 0.22);

        list.add(v1);
        list.add(v2);
        list.add(v3);

        computeSum(list);
        System.out.println(computeSum(list));
    }

    public static <T extends Sumabil> MyVector3 computeSum(Collection<T> collection) {
        MyVector3 v2 = new MyVector3();
        for (T t : collection) {
            v2.addValue((MyVector3) t);
        }
        return v2;
    }
}
