import java.io.IOException;
import java.math.BigInteger;
import java.util.Scanner;
import java.util.Stack;

public class Main {
    public static int base;
    public static Stack<BigInteger> stack;
    public static Scanner scanner;
    public static int program_counter;
    public static int nr_braces = 0;
    public static int err_instruction;

    public static void main(String[] args) throws IOException {
        base = 10;
        stack = new Stack<>();
        Interpreter.reader(args[0]);
        scanner = new Scanner(System.in);
        if (args.length == 2) {
            base = Integer.parseInt(args[1]);
        }

        if (!Interpreter.syntactic_error) {
            for (int i = 0; i < Interpreter.instructions.size(); i++) {
                if (Interpreter.instructions.get(i) == 12) nr_braces++;
                if (Interpreter.instructions.get(i) == 18) {
                    nr_braces--;
                    if (nr_braces == -1) {
                        err_instruction = i;
                    }
                }
            }
            if (nr_braces != 0) {
                if (nr_braces > 0) {
                    err_instruction = Interpreter.instructions.size();
                }
                Interpreter.syntactic_error = true;
            }
        }
        if (Interpreter.syntactic_error) {
            System.err.println("Error:" + err_instruction);
            System.exit(-1);
        } else {
            for (program_counter = 0; program_counter < Interpreter.instructions.size(); program_counter++) {
                Interpreter.execute(Interpreter.instructions.get(program_counter), stack);
                if (Instructions.execution_error) {
                    System.err.println("Exception:" + program_counter);
                    System.exit(-2);
                }
            }

        }

    }
}
