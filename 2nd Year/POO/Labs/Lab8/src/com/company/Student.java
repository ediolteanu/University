package com.company;

import java.lang.*;
import java.util.Objects;

public class Student implements Comparable<Student> {
    private long id;
    private String name;
    private String surname;
    private double averageGrade;

    public Student(long id, String name, String surname, double averageGrade) {
        this.id = id;
        this.name = name;
        this.surname = surname;
        this.averageGrade = averageGrade;
    }

    public long getId() {
        return this.id;
    }

    public void setId(long id) {
        this.id = id;
    }

    public String getName() {
        return this.name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getSurname() {
        return this.surname;
    }

    public void setSurname(String surname) {
        this.surname = surname;
    }

    public double getAverageGrade() {
        return this.averageGrade;
    }

    public void setAverageGrade(double averageGrade) {
        this.averageGrade = averageGrade;
    }

    @Override
    public int compareTo(Student o) {
        if (this.averageGrade > o.averageGrade) {
            return 1;
        } else if (this.averageGrade == o.averageGrade) {
            if (this.surname.compareTo(o.surname) != 0) {
                return this.surname.compareTo(o.surname);
            } else {
                return this.name.compareTo(o.name);
            }
        } else {
            return -1;
        }
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Student student = (Student) o;
        return id == student.id &&
                Double.compare(student.averageGrade, averageGrade) == 0 &&
                Objects.equals(name, student.name) &&
                Objects.equals(surname, student.surname);
    }

    @Override
    public int hashCode() {
        return Objects.hash(id, name, surname, averageGrade);
    }

    @Override
    public String toString() {
        return averageGrade + " " + name + " " + surname + " " + id;
    }
}