package com.apd.tema2.intersections;

import com.apd.tema2.entities.Car;
import com.apd.tema2.entities.Intersection;

import java.util.concurrent.BrokenBarrierException;
import java.util.concurrent.CyclicBarrier;
import java.util.concurrent.Semaphore;

public class SimpleMaintenance implements Intersection {
    private static int n;
    public static CyclicBarrier barrier;
    public static Semaphore semaphore1;
    public static Semaphore semaphore2;
    @Override
    public void setN(int n) {
        this.n = n;
    }

    @Override
    public void setT(int T) {

    }

    public static void resolve(Car car) throws InterruptedException, BrokenBarrierException {
        System.out.println("Car " + car.getId() + " from side number " + car.getStartDirection() +
                " has reached the bottleneck");
        if (car.getStartDirection() == 0) { // lane-ul 0
            semaphore1.acquire(); // incearca sa treaca de semaforul de pe lane-ul 0
        } else { // lane-ul 1
            semaphore2.acquire(); // incearca sa treaca de semaforul de pe lane-ul 1
        }

        System.out.println("Car " + car.getId() + " from side number " + car.getStartDirection() +
                " has passed the bottleneck");

        barrier.await(); // se asteapta masinile care au intrat in bottleneck
        if (car.getStartDirection() == 0) { // lane-ul 0
            // masinile care au venit de pe 0 dau acum release pe 1 pentru a trece masinile din celalalt sens
            semaphore2.release();
        } else { // lane-ul 1
            // masinile care au venit de pe 1 dau acum release pe 0 pentru a trece masinile din celalalt sens
            semaphore1.release();
        }
    }
}
