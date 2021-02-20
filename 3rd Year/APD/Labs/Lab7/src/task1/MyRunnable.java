package task1;

import java.util.ArrayList;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.atomic.AtomicInteger;

public class MyRunnable implements Runnable {
    int[][] graph;
    ExecutorService tpe;
    ArrayList<Integer> partialPath;
    int destination;
    AtomicInteger inQueue;

    public MyRunnable(int[][] graph, ExecutorService tpe, ArrayList<Integer> partialPath, int i, AtomicInteger inQueue) {
        this.graph = graph;
        this.tpe = tpe;
        this.partialPath = partialPath;
        this.destination = i;
        this.inQueue = inQueue;
    }

    @Override
    public void run() {
        if (partialPath.get(partialPath.size() - 1) == destination) {
            System.out.println(partialPath);
            int left = inQueue.decrementAndGet();
            if (left == 0) {
                tpe.shutdown();
            }
            return;
        }

        // se verifica nodurile pentru a evita ciclarea in graf
        int lastNodeInPath = partialPath.get(partialPath.size() - 1);

        for (int[] ints : graph) {
            if (ints[0] == lastNodeInPath) {
                if (partialPath.contains(ints[1]))
                    continue;
                ArrayList<Integer> newPartialPath = new ArrayList<>(partialPath);
                newPartialPath.add(ints[1]);
                //getPath(newPartialPath, destination);
                inQueue.incrementAndGet();
                tpe.submit(new MyRunnable(graph, tpe, newPartialPath, destination, inQueue));
            }
        }

        int left = inQueue.decrementAndGet();
        if (left == 0) {
            tpe.shutdown();
        }

    }
}
