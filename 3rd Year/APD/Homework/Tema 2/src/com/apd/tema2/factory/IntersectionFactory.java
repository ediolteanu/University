package com.apd.tema2.factory;

import com.apd.tema2.entities.Intersection;
import com.apd.tema2.intersections.*;

import java.util.HashMap;
import java.util.Map;

/**
 * Prototype Factory: va puteti crea cate o instanta din fiecare tip de implementare de Intersection.
 */
public class IntersectionFactory {
    private static Map<String, Intersection> cache = new HashMap<>();

    static {
        cache.put("simpleIntersection", new SimpleIntersection());
        cache.put("simpleRoundabout", new SimpleRoundabout());
        cache.put("simpleStrict1Roundabout", new SimpleStrict1Roundabout());
        cache.put("simpleStrictXRoundabout", new SimpleStrictXRoundabout());
        cache.put("simpleMaxXRoundabout", new SimpleMaxXRoundabout());
        cache.put("priorityIntersection", new PriorityIntersection());
        cache.put("crosswalk", new Crosswalk());
        cache.put("simpleMaintenance", new SimpleMaintenance());
        cache.put("complexMaintenance", new ComplexMaintenance());
        cache.put("railroad", new Railroad());
    }

    public static Intersection getIntersection(String handlerType) {
        return cache.get(handlerType);
    }

}
