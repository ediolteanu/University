package com.apd.tema2.intersections;

import com.apd.tema2.entities.Car;
import com.apd.tema2.entities.Intersection;

import java.util.concurrent.BrokenBarrierException;
import java.util.concurrent.CyclicBarrier;


import static java.lang.Thread.sleep;

public class SimpleIntersection implements Intersection {
    // Define your variables here.
    public static CyclicBarrier barrier;

    public static void resolve(Car car) throws InterruptedException, BrokenBarrierException {
        System.out.println("Car " + car.getId() + " has reached the semaphore, now waiting...");
        barrier.await(); // asteapta sa ajunga toate thread-urile la semafor
        sleep(car.getWaitingTime());
        System.out.println("Car " + car.getId() + " has waited enough, now driving...");
    }

    @Override
    public void setN(int n) {}

    @Override
    public void setT(int T) {}
}
