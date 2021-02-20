import java.math.BigInteger;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Stack;

public class Instructions {
    public static Stack<Integer> lbraces = new Stack<>();
    public static ArrayList<Integer> rbraces = new ArrayList<>();

    public static boolean execution_error = false;

    public static void input(Stack<BigInteger> stack) {
        BigInteger number;
        String str = Main.scanner.next();
        if (Main.base <= 10) {
            for (int i = 0; i < str.length(); i++) {
                if (i == 0 && str.charAt(i) == 45) continue;
                if ((str.charAt(i) > Main.base + 47) || (str.charAt(i) < Main.base + 38)) {
                    execution_error = true;
                    break;
                }
            }
            if (!execution_error) {
                number = new BigInteger(str, Main.base);
                String convert = number.toString(10);
                number = new BigInteger(convert);
                stack.push(number);
            }
        }
        else {
            for (int i = 0; i < str.length(); i++) {
                if (str.charAt(i) > Main.base + 54) {
                    execution_error = true;
                    break;
                }
            }
            if (!execution_error) {
                number = new BigInteger(str, Main.base);
                String convert = number.toString(10);
                number = new BigInteger(convert);
                stack.push(number);
            }
        }
    }

    public static void rot(Stack<BigInteger> stack) {
        BigInteger number;
        if (!stack.isEmpty()) {
            number = stack.pop();
            stack.add(0, number);
        } else {
            execution_error = true;
        }

    }

    public static void swap(Stack<BigInteger> stack) {
        BigInteger number1, number2;
        if (stack.size() >= 2) {
            number1 = stack.pop();
            number2 = stack.pop();
            stack.push(number1);
            stack.push(number2);
        } else {
            execution_error = true;
        }

    }

    public static void push(Stack<BigInteger> stack) {
        stack.push(BigInteger.valueOf(1));
    }

    public static void rrot(Stack<BigInteger> stack) {
        BigInteger number;
        if (!stack.isEmpty()) {
            number = stack.firstElement();
            stack.remove(0);
            stack.push(number);
        } else {
            execution_error = true;
        }
    }

    public static void dup(Stack<BigInteger> stack) {
        if (!stack.isEmpty()) {
            stack.push(stack.peek());
        } else {
            execution_error = true;
        }
    }

    public static void add(Stack<BigInteger> stack) {
        BigInteger number1, number2;
        if (stack.size() >= 2) {
            number1 = stack.pop();
            number2 = stack.pop();
            stack.push(number1.add(number2));
        } else {
            execution_error = true;
        }
    }

    public static void lbrace(Stack<BigInteger> stack) {
        if (!stack.empty()) {
            if (stack.peek().equals(BigInteger.valueOf(0))) {
                if (!rbraces.isEmpty()) {
                    Main.program_counter = rbraces.get(0);
                    rbraces.remove(0);
                } else {
                    Interpreter.ignore += 1;
                }
            } else {
                if (!rbraces.isEmpty()) {
                    rbraces.remove(0);
                }
                lbraces.push(Main.program_counter);
            }
        } else {
            execution_error = true;
        }
    }

    public static void output(Stack<BigInteger> stack) {
        if (!stack.isEmpty()) {
            BigInteger value = stack.pop();
            System.out.println(value.toString(Main.base).toUpperCase());
        } else {
            execution_error = true;
        }
    }


    public static void multiply(Stack<BigInteger> stack) {
        BigInteger number1, number2;
        if (stack.size() >= 2) {
            number1 = stack.pop();
            number2 = stack.pop();
            stack.push(number1.multiply(number2));
        } else {
            execution_error = true;
        }
    }

    public static void execute(Stack<BigInteger> stack) {
        BigInteger number1, number2, number3, number4;
        int instruction = 0;
        int decoder_count = 0;
        if (stack.size() >= 4) {
            number1 = stack.pop();
            number2 = stack.pop();
            number3 = stack.pop();
            number4 = stack.pop();
            HashMap<BigInteger, Integer> decoder = new HashMap<>();
            decoder.put(number1, decoder_count);
            if (!decoder.containsKey(number2)) {
                decoder_count++;
                decoder.put(number2, decoder_count);
            }
            instruction += Math.pow(3, 2) * decoder.get(number2);
            if (!decoder.containsKey(number3)) {
                decoder_count++;
                decoder.put(number3, decoder_count);
            }
            instruction += Math.pow(3, 1) * decoder.get(number3);
            if (!decoder.containsKey(number4)) {
                decoder_count++;
                decoder.put(number4, decoder_count);
            }
            instruction += Math.pow(3, 0) * decoder.get(number4);

            if (instruction == 12 || instruction == 18) {
                execution_error = true;
            } else {
                Interpreter.execute(instruction, stack);
            }
        } else {
            execution_error = true;
        }
    }

    public static void negate(Stack<BigInteger> stack) {
        BigInteger number;
        if (!stack.isEmpty()) {
            number = stack.pop();
            stack.push(number.negate());
        } else {
            execution_error = true;
        }
    }

    public static void pop(Stack<BigInteger> stack) {
        if (!stack.isEmpty()) {
            stack.pop();
        } else {
            execution_error = true;
        }
    }

    public static void rbrace() {
        rbraces.add(Main.program_counter);
        if (!lbraces.isEmpty()) {
            Main.program_counter = lbraces.pop() - 1;
        }
    }

}
