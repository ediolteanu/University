package com.apd.tema2.factory;

import com.apd.tema2.Main;
import com.apd.tema2.entities.Car;
import com.apd.tema2.entities.Intersection;
import com.apd.tema2.entities.Pedestrians;
import com.apd.tema2.entities.ReaderHandler;
import com.apd.tema2.intersections.*;

import javax.swing.*;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.PipedReader;
import java.util.ArrayList;
import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.CyclicBarrier;
import java.util.concurrent.Semaphore;
import java.util.concurrent.atomic.AtomicInteger;

/**
 * Returneaza sub forma unor clase anonime implementari pentru metoda de citire din fisier.
 */
public class ReaderHandlerFactory {

    public static ReaderHandler getHandler(String handlerType) {
        // simple semaphore intersection
        // max random N cars roundabout (s time to exit each of them)
        // roundabout with exactly one car from each lane simultaneously
        // roundabout with exactly X cars from each lane simultaneously
        // roundabout with at most X cars from each lane simultaneously
        // entering a road without any priority
        // crosswalk activated on at least a number of people (s time to finish all of them)
        // road in maintenance - 1 lane 2 ways, X cars at a time
        // road in maintenance - N lanes 2 ways, X cars at a time
        // railroad blockage for T seconds for all the cars
        // unmarked intersection
        // cars racing
        return switch (handlerType) {
            case "simple_semaphore" -> new ReaderHandler() {
                @Override
                public void handle(final String handlerType, final BufferedReader br) {
                    // Exemplu de utilizare:
                    Main.intersection = IntersectionFactory.getIntersection("simpleIntersection");
                    SimpleIntersection.barrier = new CyclicBarrier(Main.carsNo);
                }
            };
            case "simple_n_roundabout" -> new ReaderHandler() {
                @Override
                public void handle(final String handlerType, final BufferedReader br) throws IOException {
                    // To parse input line use:

                    Main.intersection = IntersectionFactory.getIntersection("simpleRoundabout");
                    String[] line = br.readLine().split(" ");
                    Main.intersection.setN(Integer.parseInt(line[0]));
                    Main.intersection.setT(Integer.parseInt(line[1]));
                    SimpleRoundabout.barrier = new CyclicBarrier(Main.carsNo);
                    SimpleRoundabout.semaphore = new Semaphore(Integer.parseInt(line[0]));
                }
            };
            case "simple_strict_1_car_roundabout" -> new ReaderHandler() {
                @Override
                public void handle(final String handlerType, final BufferedReader br) throws IOException {
                    Main.intersection = IntersectionFactory.getIntersection("simpleStrict1Roundabout");
                    String[] line = br.readLine().split(" ");
                    Main.intersection.setN(Integer.parseInt(line[0]));
                    Main.intersection.setT(Integer.parseInt(line[1]));
                    SimpleStrict1Roundabout.barrier = new CyclicBarrier(Integer.parseInt(line[0]));
                    SimpleStrict1Roundabout.semaphores = new Semaphore[Integer.parseInt(line[0]) + 1];
                    for (int i = 0; i <= Integer.parseInt(line[0]); i++) {
                        SimpleStrict1Roundabout.semaphores[i] = new Semaphore(1);
                    }
                }
            };
            case "simple_strict_x_car_roundabout" -> new ReaderHandler() {
                @Override
                public void handle(final String handlerType, final BufferedReader br) throws IOException {
                    Main.intersection = IntersectionFactory.getIntersection("simpleStrictXRoundabout");
                    String[] line = br.readLine().split(" ");
                    Main.intersection.setN(Integer.parseInt(line[0]));
                    Main.intersection.setT(Integer.parseInt(line[1]));
                    SimpleStrictXRoundabout.barrier = new CyclicBarrier(Main.carsNo);
                    SimpleStrictXRoundabout.semaphores = new Semaphore[Integer.parseInt(line[0]) + 1];
                    SimpleStrictXRoundabout.barrier2 = new CyclicBarrier(Integer.parseInt(line[2]) * Integer.parseInt(line[0]));
                    for (int i = 0; i <= Integer.parseInt(line[0]); i++) {
                        SimpleStrictXRoundabout.semaphores[i] = new Semaphore(Integer.parseInt(line[2]));
                    }
                }
            };
            case "simple_max_x_car_roundabout" -> new ReaderHandler() {
                @Override
                public void handle(final String handlerType, final BufferedReader br) throws IOException {
                    Main.intersection = IntersectionFactory.getIntersection("simpleMaxXRoundabout");
                    String[] line = br.readLine().split(" ");
                    Main.intersection.setN(Integer.parseInt(line[0]));
                    Main.intersection.setT(Integer.parseInt(line[1]));
                    SimpleMaxXRoundabout.semaphores = new Semaphore[Integer.parseInt(line[0]) + 1];
                    for (int i = 0; i <= Integer.parseInt(line[0]); i++) {
                        SimpleMaxXRoundabout.semaphores[i] = new Semaphore(Integer.parseInt(line[2]));
                    }
                }
            };
            case "priority_intersection" -> new ReaderHandler() {
                @Override
                public void handle(final String handlerType, final BufferedReader br) throws IOException {
                    Main.intersection = IntersectionFactory.getIntersection("priorityIntersection");
                    String[] line = br.readLine().split(" ");
                    Main.intersection.setN(Integer.parseInt(line[0]));
                    Main.intersection.setT(Integer.parseInt(line[1]));
                    PriorityIntersection.semaphore = new Semaphore(Integer.parseInt(line[0]));
                }
            };
            case "crosswalk" -> new ReaderHandler() {
                @Override
                public void handle(final String handlerType, final BufferedReader br) throws IOException {
                    Main.intersection = IntersectionFactory.getIntersection("crosswalk");
                    String[] line = br.readLine().split(" ");
                    Main.pedestrians = new Pedestrians(Integer.parseInt(line[0]), Integer.parseInt(line[1]));
                    Main.intersection.setN(Integer.parseInt(line[0]));
                    Main.intersection.setT(Integer.parseInt(line[1]));
                }
            };
            case "simple_maintenance" -> new ReaderHandler() {
                @Override
                public void handle(final String handlerType, final BufferedReader br) throws IOException {
                    Main.intersection = IntersectionFactory.getIntersection("simpleMaintenance");
                    String[] line = br.readLine().split(" ");
                    Main.intersection.setN(Integer.parseInt(line[0]));
                    SimpleMaintenance.semaphore1 = new Semaphore(Integer.parseInt(line[0]));
                    SimpleMaintenance.semaphore2 = new Semaphore(0);
                    SimpleMaintenance.barrier = new CyclicBarrier(Integer.parseInt(line[0]));
                }
            };
            case "complex_maintenance" -> new ReaderHandler() {
                @Override
                public void handle(final String handlerType, final BufferedReader br) throws IOException {
                    Main.intersection = IntersectionFactory.getIntersection("complexMaintenance");
                    String[] line = br.readLine().split(" ");
                    Main.intersection.setN(Integer.parseInt(line[0]));
                    Main.intersection.setT(Integer.parseInt(line[1]));
                    ComplexMaintenance.X = Integer.parseInt(line[2]);
                    ComplexMaintenance.barrier = new CyclicBarrier(Main.carsNo);
                    ComplexMaintenance.semaphores1 = new Semaphore[Integer.parseInt(line[1])];
                    ComplexMaintenance.semaphores2 = new Semaphore[Integer.parseInt(line[0])];
                    ComplexMaintenance.orders = new AtomicInteger[Integer.parseInt(line[1])];
                    for (int i = 0; i < Integer.parseInt(line[1]); i++) {
                        ComplexMaintenance.semaphores1[i] = new Semaphore(1);
                        ComplexMaintenance.orders[i] = new AtomicInteger(1);
                    }
                    for (int i = 0; i < Integer.parseInt(line[0]); i++) {
                        ComplexMaintenance.semaphores2[i] = new Semaphore(Integer.parseInt(line[2]));
                    }

                }
            };
            case "railroad" -> new ReaderHandler() {
                @Override
                public void handle(final String handlerType, final BufferedReader br) throws IOException {
                    Main.intersection = IntersectionFactory.getIntersection("railroad");
                    Railroad.barrier = new CyclicBarrier(Main.carsNo);
                    Railroad.semaphores = new Semaphore[Main.carsNo];
                    Railroad.semaphores[0] = new Semaphore(1);
                    for(int i = 1; i < Main.carsNo; i++) {
                        Railroad.semaphores[i] = new Semaphore(0);
                    }
                    Railroad.order = new AtomicInteger(0);

                }
            };
            default -> null;
        };
    }

}
