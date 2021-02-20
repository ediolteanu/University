package BinarySearch;


import java.util.ArrayList;
import java.util.concurrent.CyclicBarrier;

public class Main {
    public static final int N = 16;
    public static final int P = 4;
    static int[] arr = {1, 1, 2, 3, 5, 5, 6, 6, 7, 7, 7, 8, 8, 9, 9, 9};
    public static CyclicBarrier barrier;

    public static void main(String[] args) {
        Thread threads[] = new Thread[P];
        ArrayList<Integer> interval = new ArrayList<>();
        ArrayList<Boolean> found = new ArrayList<>();
        interval.add(0, 0);
        interval.add(1, N - 1);
        found.add(0, false);
        barrier = new CyclicBarrier(P);
        for (int i = 0; i < P; i++)
            threads[i] = new Thread(new BinarySearch(arr, i, N - 1, P, interval, found, 3));
        for (int i = 0; i < P; i++)
            threads[i].start();

        for (int i = 0; i < P; i++) {
            try {
                threads[i].join();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}
