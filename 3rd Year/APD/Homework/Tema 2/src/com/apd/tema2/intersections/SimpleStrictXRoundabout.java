package com.apd.tema2.intersections;

import com.apd.tema2.entities.Car;
import com.apd.tema2.entities.Intersection;

import javax.swing.*;
import java.util.concurrent.BrokenBarrierException;
import java.util.concurrent.CyclicBarrier;
import java.util.concurrent.Semaphore;

import static java.lang.Thread.onSpinWait;
import static java.lang.Thread.sleep;

public class SimpleStrictXRoundabout implements Intersection {
    private static int n;
    private static int T;
    public static Semaphore[] semaphores;
    public static CyclicBarrier barrier;
    public static CyclicBarrier barrier2;
    @Override
    public void setN(int n) {
        this.n = n;
    }

    @Override
    public void setT(int T) {
        this.T = T;
    }

    public static void resolve(Car car) throws InterruptedException, BrokenBarrierException {
        System.out.println("Car " + car.getId() + " has reached the roundabout, now waiting...");
        barrier.await(); // asteapta sa ajunga toate masinile la rond
        semaphores[car.getStartDirection()].acquire(); // intra primele x masini de pe fiecare sens
        System.out.println("Car " + car.getId() + " was selected to enter the roundabout from lane " + car.getStartDirection());
        barrier2.await(); // asteapta sa fie selecate toate cele x masini de pe fiecare sens
        System.out.println("Car " + car.getId() + " has entered the roundabout from lane " + car.getStartDirection());
        barrier2.await(); // asteapta sa intre cele x masini de pe fiecare sens
        sleep(car.getWaitingTime());
        System.out.println("Car " + car.getId() + " has exited the roundabout after " + T / 1000 + " seconds");
        barrier2.await(); // asteapta sa iasa cele x masini de pe fiecare sens
        semaphores[car.getStartDirection()].release(); // se elibereaza sens-ul pentru a intra urmatoarele x masini
    }
}
