package com.apd.tema2.intersections;

import com.apd.tema2.Main;
import com.apd.tema2.entities.Car;
import com.apd.tema2.entities.Intersection;

import java.util.concurrent.Semaphore;

public class Crosswalk implements Intersection {
    private static int spawnTime;
    private static int minPietons;
    public static float startTime;
    public static Semaphore semaphore;
    @Override
    public void setN(int spawnTime) {
        this.spawnTime = spawnTime;
    }

    @Override
    public void setT(int noLPcars) {
        this.minPietons = minPietons;
    }


    public static void resolve(Car car) {
        boolean lastMessage = false;
        while (!Main.pedestrians.isFinished()) { // volatile finished ca sa se opreasca
            if (!Main.pedestrians.isPass()) { // verifica daca sa printeze red sau green
                if (!lastMessage) { // printeaza mesajul doar daca inainte era red
                    System.out.println("Car " + car.getId() + " has now green light");
                    lastMessage = true;
                }
            } else {
                if (lastMessage) { // printeaza mesajul doar daca inainte era green
                    System.out.println("Car " + car.getId() + " has now red light");
                    lastMessage = false;
                }
            }
        }

        if (!lastMessage) { // printeaza mesajul green in cazul in care am iesit din while cand ultimul mesaj era red
            System.out.println("Car " + car.getId() + " has now green light");
        }
    }
}
