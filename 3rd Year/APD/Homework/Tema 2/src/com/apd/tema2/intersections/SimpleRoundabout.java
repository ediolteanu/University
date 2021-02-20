package com.apd.tema2.intersections;

import com.apd.tema2.Main;
import com.apd.tema2.entities.Car;
import com.apd.tema2.entities.Intersection;

import java.util.concurrent.BrokenBarrierException;
import java.util.concurrent.CyclicBarrier;
import java.util.concurrent.Semaphore;

import static java.lang.Thread.sleep;

public class SimpleRoundabout implements Intersection {
    private int n;
    private static int T;
    public static CyclicBarrier barrier;
    public static Semaphore semaphore;

    public static void resolve(Car car) throws BrokenBarrierException, InterruptedException {
        System.out.println("Car " + car.getId() + " has reached the roundabout, now waiting...");
        barrier.await(); // asteapta ca toate masinile sa ajunga la sens
        semaphore.acquire(); // rezerva locul in sensul giratoriu, daca permits = 0 asteapta.
        System.out.println("Car " + car.getId() + " has entered the roundabout");
        sleep(car.getWaitingTime());
        System.out.println("Car " + car.getId() + " has exited the roundabout after " + T / 1000 + " seconds");
        semaphore.release(); // elibereaza locul din sens, astfel masinile care asteapta pot trece de acquire
    }

    @Override
    public void setN(int n) {
        this.n = n;
    }

    @Override
    public void setT(int T) {
        this.T = T;
    }
}
