package com.apd.tema2.intersections;

import com.apd.tema2.entities.Car;
import com.apd.tema2.entities.Intersection;

import java.util.concurrent.BrokenBarrierException;
import java.util.concurrent.CyclicBarrier;
import java.util.concurrent.Semaphore;
import java.util.concurrent.atomic.AtomicInteger;

import static java.lang.Math.min;

public class ComplexMaintenance implements Intersection {
    private static int N;
    private static int M;
    public static int X;
    public static CyclicBarrier barrier;
    public static Semaphore[] semaphores1;
    public static Semaphore[] semaphores2;
    public static AtomicInteger[] orders;

    @Override
    public void setN(int N) {
        this.N = N;
    }

    @Override
    public void setT(int M) {
        this.M = M;
    }

    public static void resolve(Car car) throws BrokenBarrierException, InterruptedException {
        int start = (int) (car.getStartDirection() * (double) N / M);
        int end = (int) min((car.getStartDirection() + 1) * (double) N / M, N);
        System.out.println("Car " + car.getId() + " has come from the lane number " + car.getStartDirection());
        car.setOrder(orders[car.getStartDirection()].getAndAdd(1));
        barrier.await();
        semaphores1[car.getStartDirection()].acquire(car.getOrder());

        for (int i = start; i < end; i++) {
            semaphores2[i].acquire();
            System.out.println("Car " + car.getId() + " from lane " + car.getStartDirection() + " has entered lane number " + i);
            semaphores2[i].release();
        }
        //System.out.println("The initial lane " + car.getStartDirection() + " has been emptied and removed from the new lane queue");
        //System.out.println("The initial lane " + car.getStartDirection() + " has no permits and is moved to the back of the new lane queue");
//        for (int i = start; i < end; i++) {
//
//        }

        semaphores1[car.getStartDirection()].release(car.getOrder() + 1);
    }
}
