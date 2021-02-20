package com.apd.tema2.intersections;

import com.apd.tema2.entities.Car;
import com.apd.tema2.entities.Intersection;

import java.util.concurrent.Semaphore;

import static java.lang.Thread.sleep;


public class PriorityIntersection implements Intersection {
    private static int noHPcars;
    private static int noLPcars;
    public static Semaphore semaphore;
    @Override
    public void setN(int noHPcars) {
        this.noHPcars = noHPcars;
    }

    @Override
    public void setT(int noLPcars) {
        this.noLPcars = noLPcars;
    }

    public static void resolve(Car car) throws InterruptedException {
        if (car.getPriority() == 1) {
            System.out.println("Car " + car.getId() + " with low priority is trying to enter the intersection...");
            semaphore.acquire(noHPcars); // poate intra doar daca intersectia e goala
            System.out.println("Car " + car.getId() + " with low priority has entered the intersection");
            semaphore.release(noHPcars); // elibereaza intersectia
        } else {
            System.out.println("Car " + car.getId() + " with high priority has entered the intersection");
            // isi revendica prezenta in intersectia si deoarece numarul de permits maxim  este egal cu cel cu care
            // masinile cu low priority trebuie sa dea acquire le blocheaza pe acestea
            semaphore.acquire();

            sleep(2000);
            System.out.println("Car " + car.getId() + " with high priority has exited the intersection");
            semaphore.release(); // iese din intersectie


        }
    }
}
