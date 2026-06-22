# 15-Minute Java Classes & OOP Fundamentals Lecture

**Duration:** 15 minutes
**Goal:** Understand Java classes, objects, and the four pillars of OOP

---

## Section 1: What is a Class? (2 minutes)

### Classes = Blueprints, Objects = Instances

A **class** defines the structure and behavior of objects. An **object** is an instance created from that class.

```java
// Class definition (blueprint)
class Car {
    String make;        // Fields (state)
    String model;
    int year;

    void honk() {       // Method (behavior)
        System.out.println("Beep!");
    }
}

// Creating objects from the class
Car myCar = new Car();    // 'new' keyword creates an instance
myCar.make = "Toyota";    // Dot notation accesses members
myCar.honk();             // Calling a method
```

**Key Terms:**

- **Class:** Template defining state (fields) and behavior (methods)
- **Object:** Instance of a class with its own memory
- **Instantiation:** Creating an object using `new`

---

## Section 2: Constructors (2 minutes)

### Initializing objects

Constructors run automatically when `new` is called. They have the class name and no return type.

```java
class Car {
    String make;
    String model;
    int year;

    // Default constructor (provided by Java if none written)
    public Car() { }

    // Parameterized constructor
    public Car(String make, String model, int year) {
        this.make = make;   // 'this' distinguishes field from parameter
        this.model = model;
        this.year = year;
    }
}

// Using constructors
Car car1 = new Car();                        // Default
Car car2 = new Car("Toyota", "Camry", 2022); // Parameterized
```

**Key Points:**

- **`this`** refers to the current object instance
- If you define a constructor, the default one is not automatically provided
- Constructors can be overloaded (multiple versions with different parameters)

---

## Section 3: Encapsulation (2 minutes)

### Protecting data with access control

Encapsulation restricts direct access to internal state using **access modifiers** and **getters/setters**.

```java
class Car {
    private String make;   // Private: only accessible within this class
    private int speed;

    // Getter - controlled read access
    public String getMake() {
        return make;
    }

    // Setter - controlled write access (can add validation)
    public void setMake(String make) {
        this.make = make;
    }

    // Methods that safely modify state
    public void accelerate(int amount) {
        if (amount > 0) {
            this.speed += amount;
        }
    }
}

Car car = new Car();
car.make = "Toyota";           // Compile error! Private field
car.setMake("Toyota");         // Allowed through public setter
car.accelerate(30);            // Controlled state modification
```

**Access Modifiers:**

- `private` — Same class only
- `default` — Same package
- `protected` — Same package + subclasses
- `public` — Everywhere

---

## Section 4: Inheritance (3 minutes)

### Reusing code through parent-child relationships

Inheritance allows a subclass to reuse fields and methods from a parent class using `extends`.

```java
// Parent class (superclass)
abstract static class Vehicle {
    private String make;
    private String model;

    public Vehicle(String make, String model) {
        this.make = make;
        this.model = model;
    }

    public void displayInfo() {
        System.out.println(make + " " + model);
    }
}

// Child class (subclass) inherits from Vehicle
static class Car extends Vehicle {
    private int numDoors;

    public Car(String make, String model, int numDoors) {
        super(make, model);  // Calls parent constructor (MUST be first line)
        this.numDoors = numDoors;
    }

    @Override  // Optional annotation - tells compiler we're overriding
    public void displayInfo() {
        super.displayInfo();  // Calls parent's version
        System.out.println("Doors: " + numDoors);
    }
}
```

**Inheritance Rules:**

- Use `extends` for single inheritance
- `super()` must be first in child constructor
- `super.method()` calls parent's version
- `@Override` is recommended for clarity
- Private members are inherited but not directly accessible

---

## Section 5: Polymorphism (3 minutes)

### One interface, many forms

Polymorphism allows different object types to respond to the same method call in their own way.

```java
// Parent reference, child object
Vehicle[] vehicles = {
    new Car("Toyota", "Camry", 4),       // Car IS-A Vehicle
    new Motorcycle("Harley", "Street 750")  // Motorcycle IS-A Vehicle
};

// Polymorphic method call - correct honk() runs for each type
for (Vehicle v : vehicles) {
    v.displayInfo();   // Calls the overridden version
    v.honk();          // Each subclass provides its own implementation
}

// instanceof - check the actual runtime type
if (myCar instanceof Car) {
    System.out.println("This is a Car!");
}
```

**Types of Polymorphism:**

1. **Compile-time (overloading):** Same method name, different parameters
2. **Run-time (overriding):** Subclass provides own implementation

**Key Concept:** The method called depends on the object's **runtime type** (dynamic method dispatch).

---

## Section 6: Abstraction (2 minutes)

### Hiding complexity

Abstraction hides implementation details and exposes only essential features using **abstract classes** and **interfaces**.

```java
// Abstract class - can have both abstract and concrete methods
abstract static class Vehicle {
    public abstract void honk();  // No body - subclasses MUST implement

    public void displayInfo() {   // Concrete method with implementation
        System.out.println("Vehicle info");
    }
}

// Interface - 100% abstract contract (before Java 8)
interface Maintainable {
    String getMaintenanceSchedule();  // implicitly public abstract
}

// Class can extend ONE class and implement MANY interfaces
static class Car extends Vehicle implements Maintainable {
    @Override
    public void honk() { /* MUST implement */ }

    @Override
    public String getMaintenanceSchedule() { /* MUST implement */ }
}
```

**Abstract vs Interface:**

| Feature       | Abstract Class                | Interface                              |
| ------------- | ----------------------------- | -------------------------------------- |
| Instantiation | Cannot instantiate            | Cannot instantiate                     |
| Methods       | Abstract + concrete           | Abstract (default/static in Java 8+)   |
| Fields        | Any type                      | Constants only (`public static final`) |
| Inheritance   | `extends` (single)            | `implements` (multiple)                |
| Use case      | Related classes, shared state | Unrelated classes, shared behavior     |

---

## Section 7: Static Members (1 minute)

### Class-level members

Static members belong to the class, not individual objects. Access them via the class name.

```java
class Car {
    public static final int NUM_WHEELS = 4;  // Constant (shared, unchangeable)
    private static int carCount = 0;          // Shared counter

    public Car() {
        carCount++;  // Incremented for EVERY Car created
    }

    public static int getCarCount() {  // Static method - no 'this' allowed
        return carCount;  // Can only access static members
    }
}

// Usage - accessed via class name (not an instance)
System.out.println(Car.NUM_WHEELS);      // 4
System.out.println(Car.getCarCount());   // Access without an object
```

**Static Rules:**

- Static methods cannot access instance fields/methods (no `this`)
- Static fields are shared across all instances
- `static final` creates constants (`UPPER_SNAKE_CASE` naming)

---

## Summary (1 minute)

### The Four Pillars of OOP

| Pillar            | Purpose           | Java Mechanism              |
| ----------------- | ----------------- | --------------------------- |
| **Encapsulation** | Data protection   | `private` + getters/setters |
| **Inheritance**   | Code reuse        | `extends`, `super`          |
| **Polymorphism**  | Flexible behavior | Method overriding           |
| **Abstraction**   | Hide complexity   | `abstract`, `interface`     |

### Additional Concepts

- **Constructors** — Initialize objects with `this` and `super`
- **Static members** — Shared class-level fields/methods
- **`instanceof`** — Check runtime type

---

_See `OopDemo.java` for working examples of all concepts._
