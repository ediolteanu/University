package com.company;

import java.util.Objects;

public class Catalog {
    private String name;
    private double grade;

    public Catalog(String name, double grade) {
        this.name = name;
        this.grade = grade;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public double getGrade() {
        return grade;
    }

    public void setGrade(double grade) {
        this.grade = grade;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Catalog catalog = (Catalog) o;
        return Objects.equals(name, catalog.name) &&
                Objects.equals(grade, catalog.grade);
    }

    @Override
    public int hashCode() {
        return Objects.hash(name, grade);
    }
}
