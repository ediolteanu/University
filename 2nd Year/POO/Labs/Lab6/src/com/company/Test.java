package com.company;

//interface Engine {
//    public int getFuelCapacity();
//}

//class Car {
//    static class OttoEngine implements Engine {
//        private int fuelCapacity;
//
//        public OttoEngine(int fuelCapacity) {
//            this.fuelCapacity = fuelCapacity;
//        }
//
//        public int getFuelCapacity() {
//            return fuelCapacity;
//        }
//    }
//
//    public OttoEngine getEngine() {
//        OttoEngine engine = new OttoEngine(11);
//        return engine;
//    }
//}

//class Car {
//    public Engine getEngine(int fuelCapacity) {
//        return new Engine () {
//            private int fuelCapacity = 11;
//
//            public int getFuelCapacity() {
//                return fuelCapacity;
//            }
//        };
//    }
//}

//class Car {
//    public Engine getEngine() {
//        class OttoEngine implements Engine {
//            private int fuelCapacity = 11;
//
//            public int getFuelCapacity() {
//                return fuelCapacity;
//            }
//        }
//
//        return new OttoEngine();
//    }
//}
//class Car {
//    public Engine getEngine(int fuelCapacity) {
//        if (fuelCapacity == 11) {
//            class OttoEngine implements Engine {
//                private int fuelCapacity = 11;
//
//                public int getFuelCapacity() {
//                    return fuelCapacity;
//                }
//            }
//
//            return new OttoEngine();
//        }
//
//        return null;
//    }
//}

//public class Test {
//    public static void main(String[] args) {
//        Car car = new Car();
//
//        Car firstEngine = car.getEngine();
//        Car.OttoEngine secondEngine = new Car.OttoEngine(10);
//
//        System.out.println(firstEngine.getFuelCapacity());
//        System.out.println(secondEngine.getFuelCapacity());
//
////        Engine firstEngine = car.getEngine(10);
////        Engine secondEngine = car.getEngine(11);
////
////        System.out.println(firstEngine.getFuelCapacity());
////        System.out.println(secondEngine.getFuelCapacity());
//
//}
//}

class Car {
    class Engine {
        public void getFuelCapacity() {
            System.out.println("I am a generic Engine");
        }
    }
}

class OttoEngine extends Car.Engine {
//    OttoEngine() {
//    } // EROARE, avem nevoie de o legatura la obiectul clasei exterioare

    OttoEngine(Car car) { // OK
        car.super();
    }
}

public class Test {
    public static void main(String[] args) {
        Car car = new Car();
        OttoEngine ottoEngine = new OttoEngine(car);
        ottoEngine.getFuelCapacity();
    }

}