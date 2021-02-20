package com.apd.tema2.intersections;

import com.apd.tema2.entities.Car;
import com.apd.tema2.entities.Intersection;

import java.util.concurrent.BrokenBarrierException;
import java.util.concurrent.CyclicBarrier;
import java.util.concurrent.Semaphore;

import static java.lang.Thread.sleep;

public class SimpleMaxXRoundabout implements Intersection {
    private static int n;
    private static int T;
    public static Semaphore[] semaphores;

    @Override
    public void setN(int n) {
        this.n = n;
    }

    @Override
    public void setT(int T) {
        this.T = T;
    }


    public static void resolve(Car car) throws BrokenBarrierException, InterruptedException {
        System.out.println("Car " + car.getId() + " has reached the roundabout from lane " + car.getStartDirection());
        semaphores[car.getStartDirection()].acquire(); // intra in sens maxim x masini pe un lane
        System.out.println("Car " + car.getId() + " has entered the roundabout from lane " + car.getStartDirection());
        sleep(car.getWaitingTime());
        System.out.println("Car " + car.getId() + " has exited the roundabout after " + T / 1000 + " seconds");
        semaphores[car.getStartDirection()].release(); // ies din sens masinile care au intrat
    }
}
