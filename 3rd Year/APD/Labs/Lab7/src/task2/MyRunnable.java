package task2;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.atomic.AtomicInteger;

public class MyRunnable implements Runnable {
    int[] colors;
    AtomicInteger inQueue;
    ExecutorService tpe;
    int step;

    public MyRunnable(int[] colors, AtomicInteger inQueue, ExecutorService tpe, int step) {
        this.colors = colors;
        this.inQueue = inQueue;
        this.tpe = tpe;
        this.step = step;
    }

    private static boolean verifyColors(int[] colors, int step) {
        for (int i = 0; i < step; i++) {
            if (colors[i] == colors[step] && isEdge(i, step))
                return false;
        }
        return true;
    }

    private static boolean isEdge(int a, int b) {
        for (int[] ints : Main.graph) {
            if (ints[0] == a && ints[1] == b)
                return true;
        }
        return false;
    }

    static void printColors(int[] colors) {
        StringBuilder aux = new StringBuilder();
        for (int color : colors) {
            aux.append(color).append(" ");
        }
        System.out.println(aux);
    }

    @Override
    public void run() {
        if (step == Main.N) {
            printColors(colors);
            int left = inQueue.decrementAndGet();
            if (left == 0) {
                tpe.shutdown();
            }
            return;
        }

        // for the node at position step try all possible colors
        for (int i = 0; i < Main.COLORS; i++) {
            int[] newColors = colors.clone();
            newColors[step] = i;
            if (verifyColors(newColors, step)) {
                //colorGraph(newColors, step + 1);
                inQueue.incrementAndGet();
                tpe.submit(new MyRunnable(newColors, inQueue, tpe, step + 1));
            }
        }
        int left = inQueue.decrementAndGet();
        if (left == 0) {
            tpe.shutdown();
        }
    }
}
