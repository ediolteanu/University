package com.company;

import java.util.*;

public class Main {

    public static void main(String[] args) {
        // write your code here
        Student student1 = new Student(0, "Alecxs", "Careia", 9.75);
        Student student2 = new Student(1, "Luk", "George", 10);
        Student student3 = new Student(2, "Edward", "TheConfessor", 9.75);
        Student student4 = new Student(3, "Alecxs", "Carenuia", 9.75);
        Student student5 = new Student(4, "Luck", "Prostu", 10);

        ArrayList<Student> list = new ArrayList<>();
        list.add(student1);
        list.add(student2);
        list.add(student3);
        list.add(student4);
        list.add(student5);

        list.sort(Student::compareTo);
        //System.out.println(list);
        PriorityQueue<Student> priorityQueue = new PriorityQueue<Student>(Comparator.comparingLong(Student::getId));
        priorityQueue.addAll(list);
        System.out.println(priorityQueue);

        HashMap<Student, LinkedList<String>> hashMap = new HashMap<>();
        LinkedList<String> mat1 = new LinkedList<>();
        mat1.add("Mate");
        mat1.add("Info");
        mat1.add("Fizica");
        LinkedList<String> mat2 = new LinkedList<>();
        mat2.add("Biologie");
        mat2.add("Chimie");
        mat2.add("Fizica");
        LinkedList<String> mat3 = new LinkedList<>();
        mat3.add("IOCLA");
        mat3.add("POO");
        mat3.add("AA");
        LinkedList<String> mat4 = new LinkedList<>();
        mat4.add("Romana");
        mat4.add("Istorie");
        mat4.add("Geografie");
        LinkedList<String> mat5 = new LinkedList<>();
        mat5.add("English");
        mat5.add("Francais");
        mat5.add("Espanol");
        hashMap.put(student1, mat1);
        hashMap.put(student2, mat2);
        hashMap.put(student3, mat3);
        hashMap.put(student4, mat4);
        hashMap.put(student5, mat5);

        Set<Map.Entry<Student, LinkedList<String>>> s = hashMap.entrySet();
        for (Map.Entry<Student, LinkedList<String>> it : s) {
            System.out.println(it.getKey() + " : " + it.getValue());
        }

        LinkedHashSetImproved linkedHashSetImproved = new LinkedHashSetImproved();
        linkedHashSetImproved.add(0);
        linkedHashSetImproved.add(1);
        linkedHashSetImproved.add(2);
        linkedHashSetImproved.add(3);

        ArrayList<Integer> numbers = new ArrayList<>();
        numbers.add(23);
        numbers.add(32);
        numbers.add(55);
        numbers.add(90);

        linkedHashSetImproved.addAll(numbers);

        for (Integer integer : linkedHashSetImproved) {
            System.out.println(integer);
        }
    }
}
