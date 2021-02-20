import java.io.*;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Stack;

public class Interpreter {
    public static ArrayList<Integer> instructions;
    public static HashMap<Character, Integer> decoder;
    public static int ignore = 0;
    public static boolean syntactic_error = false;

    public static void reader(String filename) throws IOException {
        instructions = new ArrayList<>();
        decoder = new HashMap<>();
        BufferedReader reader = new BufferedReader(new FileReader(filename));
        int c;
        int total = 0;
        int count = 4;
        int decode_counter = 0;
        int element = 0;
        while ((c = reader.read()) != -1) {
            total += 1;
            count -= 1;
            char character = (char) c;

            if (decoder.containsKey(character)) {
                element += decoder.get(character) * Math.pow(3, count);
            } else {
                decoder.put(character, decode_counter);
                element += decode_counter * Math.pow(3, count);
                decode_counter++;
            }

            if (count == 0) {
                decoder.clear();
                count = 4;
                decode_counter = 0;
                instructions.add(element);
                element = 0;
            }
        }

        if (total % 4 != 0) {
            Main.err_instruction = instructions.size();
            syntactic_error = true;
        }
    }

    public static void execute(Integer instruction, Stack<BigInteger> stack) {
        if (ignore > 0 && instruction == 18) {
            ignore -= 1;
            return;
        }
        if (ignore != 0 && instruction != 12) return;
        switch (instruction) {
            case 1:
                Instructions.input(stack);
                break;
            case 3:
                Instructions.rot(stack);
                break;
            case 4:
                Instructions.swap(stack);
                break;
            case 5:
                Instructions.push(stack);
                break;
            case 9:
                Instructions.rrot(stack);
                break;
            case 10:
                Instructions.dup(stack);
                break;
            case 11:
                Instructions.add(stack);
                break;
            case 12:
                Instructions.lbrace(stack);
                break;
            case 13:
                Instructions.output(stack);
                break;
            case 14:
                Instructions.multiply(stack);
                break;
            case 15:
                Instructions.execute(stack);
                break;
            case 16:
                Instructions.negate(stack);
                break;
            case 17:
                Instructions.pop(stack);
                break;
            case 18:
                Instructions.rbrace();
                break;
            default:
                break;
        }
    }
}
