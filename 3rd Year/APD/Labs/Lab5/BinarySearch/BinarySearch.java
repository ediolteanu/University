package BinarySearch;

import java.util.ArrayList;
import java.util.concurrent.BrokenBarrierException;

public class BinarySearch implements Runnable {
    int arr[], x, id, P, N;
    ArrayList<Integer> interval;
    ArrayList<Boolean> found;

    BinarySearch(int arr[], int id, int N, int P, ArrayList<Integer> interval, ArrayList<Boolean> found, int x) {
        this.arr = arr;
        this.id = id;
        this.N = N;
        this.interval = interval;
        this.found = found;
        this.x = x;
        this.P = P;
    }

    @Override
    public void run() {
        int start = this.interval.get(0) + this.id * (this.interval.get(1) - this.interval.get(0)) / P;
        int end = this.interval.get(0) + (this.id + 1) * (this.interval.get(1) - this.interval.get(0)) / P;
        while (this.interval.get(0) < this.interval.get(1) && !found.get(0)) {
            if ((arr[start] < x) && (arr[end] > x)) {
                this.interval.set(0, start);
                this.interval.set(1, end);
            }

            if (arr[start] == x) {
                found.set(0, true);
                System.out.println("Elementul " + x + " este pe pozitia " + start + "!");
                break;
            }

            if (arr[end] == x) {
                found.set(0, true);
                System.out.println("Elementul " + x + " este pe pozitia " + end + "!");
                break;
            }

            try {
                Main.barrier.await();

            } catch (InterruptedException | BrokenBarrierException e) {
                e.printStackTrace();
            }

            start = this.interval.get(0) + this.id * (this.interval.get(1) - this.interval.get(0)) / P;
            end = this.interval.get(0) + (this.id + 1) * (this.interval.get(1) - this.interval.get(0)) / P;


        }
    }
}
