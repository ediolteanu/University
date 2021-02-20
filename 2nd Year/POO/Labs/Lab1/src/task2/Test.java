package task2;

import java.util.ArrayList;
import java.util.Arrays;

public class Test {
    public static void main(String[] args) {
        /*int firstArg = 0;
        if (args.length > 0) {
            try {
                firstArg = Integer.parseInt(args[0]);
            } catch (NumberFormatException e) {
                System.err.println("Argument" + args[0] + " must be an integer.");
                System.exit(1);
            }
        }*/

        Course c = new Course();
        Student s1 = new Student("Alex", 2);
        Student s2 = new Student("Luci", 3);
        Student s3 = new Student("Ade", 3);
        Student s4 = new Student("Eu", 2);
        Student s5 = new Student("Alex", 2);

        System.out.println(s1.equals(s5));

        c.add(s1);
        c.add(s2);
        c.add(s3);
        c.add(s4);
        ArrayList<Student> st = c.filterYear(2);
        System.out.println(Arrays.toString(st.toArray()));
    }
}
