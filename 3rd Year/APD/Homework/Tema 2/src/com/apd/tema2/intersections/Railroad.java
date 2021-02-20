package com.apd.tema2.intersections;

import com.apd.tema2.Main;
import com.apd.tema2.entities.Car;
import com.apd.tema2.entities.Intersection;

import java.util.concurrent.BrokenBarrierException;
import java.util.concurrent.CyclicBarrier;
import java.util.concurrent.Semaphore;
import java.util.concurrent.atomic.AtomicInteger;

public class Railroad implements Intersection {
    public static CyclicBarrier barrier;
    public static Semaphore[] semaphores;
    public static AtomicInteger order;

    @Override
    public void setN(int n) {

    }

    @Override
    public void setT(int T) {

    }


    public static void resolve(Car car) throws BrokenBarrierException, InterruptedException {
        System.out.println("Car " + car.getId() + " from side number " + car.getStartDirection()
                + " has stopped by the railroad");
        car.setOrder(order.getAndAdd(1));
        barrier.await(); // asteapta sa ajunga toate masinile la bariera

        if (car.getOrder() == 0) {
            System.out.println("The train has passed, cars can now proceed");
        }
        barrier.await(); // toate masinile asteapta sa treaca bariera
        semaphores[car.getOrder()].acquire(); // masina curenta incearca sa dea acquire
        System.out.println("Car " + car.getId() + " from side number " + car.getStartDirection()
                + " has started driving");
        // daca este ultima masina din ordine nu mai da release, in rest da release pentru semaforul asignat
        // urmatoarei masini din ordine
        if (car.getOrder() != Main.carsNo - 1) {
            semaphores[car.getOrder() + 1].release();
        }

    }
}
