package task2;

public class Student {
    private String name;
    private int year;

    Student(String name, int year){
        this.name = name;
        this.year = year;
    }

    public int getYear(){
        return this.year;
    }
    @Override
    public String toString() {
        return "Student{" +
                "name='" + name + '\'' +
                ", year=" + year +
                '}';
    }
}
