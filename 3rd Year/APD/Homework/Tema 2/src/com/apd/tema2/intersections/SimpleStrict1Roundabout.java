package com.apd.tema2.intersections;

import com.apd.tema2.Main;
import com.apd.tema2.entities.Car;
import com.apd.tema2.entities.Intersection;

import java.util.ArrayList;
import java.util.concurrent.BrokenBarrierException;
import java.util.concurrent.CyclicBarrier;
import java.util.concurrent.Semaphore;

import static java.lang.Thread.sleep;

public class SimpleStrict1Roundabout implements Intersection {
    private static int n;
    private static int T;
    public static Semaphore[] semaphores;
    public static CyclicBarrier barrier;

    @Override
    public void setN(int n) {
        this.n = n;
    }

    @Override
    public void setT(int T) {
        this.T = T;
    }

    public static void resolve(Car car) throws InterruptedException, BrokenBarrierException {
        System.out.println("Car " + car.getId() + " has reached the roundabout");
        semaphores[car.getStartDirection()].acquire(); // se da acquire pe semaforul de pe lane-ul masinii
        barrier.await();
        System.out.println("Car " + car.getId() + " has entered the roundabout from lane " + car.getStartDirection());
        sleep(car.getWaitingTime());
        System.out.println("Car " + car.getId() + " has exited the roundabout after " + T / 1000 + " seconds");
        semaphores[car.getStartDirection()].release(); // se da release pe semaforul de pe lane-ul masinii
    }
}
