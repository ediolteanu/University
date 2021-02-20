package task2;

import java.util.ArrayList;

public class Course {
    private String title, description;
    //for pentru fiecare
    private ArrayList<Student> students = new ArrayList<Student>();

    public void add(Student st){
        students.add(st);
    }
    public ArrayList<Student> filterYear(int year){
        ArrayList<Student> st2 = new ArrayList<Student>();
        for(Student i : this.students) {
            if(i.getYear() == year){
                st2.add(i);
            }
        }
        return st2;
    }


}
