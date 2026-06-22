public class OopDemo {
    public static void main(String[] args) {
        // CLASSES & OBJECTS
        System.out.println("=== Classes & Objects ===");

        Car myCar = new Car("Toyota", "Camry", 2022, 4);
        Motorcycle myBike = new Motorcycle("Harley", "Street 750", 2023);

        myCar.displayInfo();
        myCar.honk();

        myBike.displayInfo();
        myBike.honk();

        // ENCAPSULATION
        System.out.println("\n=== Encapsulation ===");

        System.out.println("Make: " + myCar.getMake());
        System.out.println("Model: " + myCar.getModel());
        System.out.println("Year: " + myCar.getYear());

        myCar.accelerate(30);
        System.out.println("Speed after accelerating: " + myCar.getSpeed() + " mph");

        myCar.accelerate(20);
        System.out.println("Speed after more acceleration: " + myCar.getSpeed() + " mph");

        myCar.brake(15);
        System.out.println("Speed after braking: " + myCar.getSpeed() + " mph");

        // INHERITANCE
        System.out.println("\n=== Inheritance ===");

        System.out.println("Car extends Vehicle and adds numDoors field");
        System.out.println("Motorcycle extends Vehicle");

        myCar.honk();
        myBike.honk();

        // POLYMORPHISM
        System.out.println("\n=== Polymorphism ===");

        Vehicle[] vehicles = { myCar, myBike };

        for (Vehicle v : vehicles) {
            v.displayInfo();
            v.honk();
            System.out.println();
        }

        System.out.println("myCar instanceof Car: " + (myCar instanceof Car));
        System.out.println("myCar instanceof Vehicle: " + (myCar instanceof Vehicle));
        System.out.println("myBike instanceof Motorcycle: " + (myBike instanceof Motorcycle));

        // ABSTRACTION
        System.out.println("\n=== Abstraction ===");

        // Cannot instantiate abstract Vehicle directly
        // Vehicle v = new Vehicle(...); // Compile error

        Maintainable maintainableCar = myCar;
        System.out.println("Maintenance schedule: " + maintainableCar.getMaintenanceSchedule());

        // STATIC MEMBERS
        System.out.println("\n=== Static Members ===");

        System.out.println("Total vehicles created: " + Vehicle.getVehicleCount());
        System.out.println("Number of wheels on a car: " + Car.NUM_WHEELS);
    }

    // Abstract class - cannot be instantiated
    abstract static class Vehicle {
        private String make;
        private String model;
        private int year;
        private int speed;

        private static int vehicleCount = 0;

        public Vehicle(String make, String model, int year) {
            this.make = make;
            this.model = model;
            this.year = year;
            this.speed = 0;
            vehicleCount++;
        }

        public String getMake() {
            return make;
        }

        public void setMake(String make) {
            this.make = make;
        }

        public String getModel() {
            return model;
        }

        public void setModel(String model) {
            this.model = model;
        }

        public int getYear() {
            return year;
        }

        public void setYear(int year) {
            this.year = year;
        }

        public int getSpeed() {
            return speed;
        }

        public void accelerate(int amount) {
            this.speed += amount;
        }

        public void brake(int amount) {
            this.speed = Math.max(0, this.speed - amount);
        }

        public void displayInfo() {
            System.out.println(year + " " + make + " " + model + " (Speed: " + speed + " mph)");
        }

        public abstract void honk();

        public static int getVehicleCount() {
            return vehicleCount;
        }

        public static void resetVehicleCount() {
            vehicleCount = 0;
        }
    }

    // Interface - defines a contract
    interface Maintainable {
        String getMaintenanceSchedule();
    }

    // Car extends Vehicle and implements Maintainable
    static class Car extends Vehicle implements Maintainable {
        public static final int NUM_WHEELS = 4;

        private int numDoors;

        public Car(String make, String model, int year, int numDoors) {
            super(make, model, year);
            this.numDoors = numDoors;
        }

        @Override
        public void honk() {
            System.out.println("Beep beep!");
        }

        @Override
        public String getMaintenanceSchedule() {
            return "Every 6 months or 5,000 miles";
        }

        @Override
        public void displayInfo() {
            super.displayInfo();
            System.out.println("  Type: Car, Doors: " + numDoors + ", Wheels: " + NUM_WHEELS);
        }
    }

    // Motorcycle extends Vehicle
    static class Motorcycle extends Vehicle {
        public Motorcycle(String make, String model, int year) {
            super(make, model, year);
        }

        @Override
        public void honk() {
            System.out.println("Honk honk!");
        }

        @Override
        public void displayInfo() {
            super.displayInfo();
            System.out.println("  Type: Motorcycle");
        }
    }
}
