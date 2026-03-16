/**
 * @author jes
 */
public class Main {
    /**
     * Fundamental Programming Concepts:
     * - Variable declaration
     * - Basic syntax
     * - Data types and structures
     * - Flow control structures (Conditionals and loops)
     * - Functional programming
     * - Object-oriented programming (OOP Principles: Inheritance, Polymorphism, Abstraction, Encapsulation)
     */
    public static void main(String[] args) {
        // Variable declaration
        int a = 1;
        int b = 2;

        // Basic syntax
        System.out.println(a + b);
        System.out.println(a - b);

        // Data types and structures
        String arrElem1;
        int[] arr = {1, 2, 3, 4, 5};

        arrElem1 = Integer.toString(arr[0]);

        // Flow control structures (Conditionals and loops)
        if ((a + b) == 3) {
            System.out.println("a + b is equal to 3");
        } else {
            System.out.println("a + b is not equal to 3");
        }


        int i = 5;

        while (i > 0) {
            System.out.println("i = " + i);
            i--;
        }

        // Functional programming
        System.out.println(add(a, b));
        System.out.println(add(1, 2));

        // Object-oriented programming (OOP Principles: Inheritance, Polymorphism, Abstraction, Encapsulation)
        HelloWorld helloWorld = new HelloWorld();
        helloWorld.greet();
        helloWorld.getIsSpecial();
        HelloWorld helloWorld2 = new HelloWorld();
        helloWorld2.setIsSpecial(false);
        helloWorld2.getIsSpecial();
        HelloWorld.getObjectCounter();
    }

    // pure function
    public static int add(int a, int b) {
        return a + b;
    }

    // abstract class
    abstract static class Hello {
        protected abstract void getIsSpecial();
    }

    // final class
    public static final class HelloWorld extends Hello {
        private static int objectCounter = 0;
        private boolean isSpecial = true;
        public static String message = "Hello, World!";

        public HelloWorld() {
            objectCounter++;
        }

        public static void setObjectCounter(int newObjectCounter) {
            objectCounter = newObjectCounter;
        }

        public static void getObjectCounter() {
            System.out.println("Number of HelloWorld objects: " + objectCounter);
        }

        public void setIsSpecial(boolean isSpecial) {
            this.isSpecial = isSpecial;
        }

        @Override
        public void getIsSpecial() {
            System.out.println("isSpecial: " + isSpecial);
        }

        public void greet() {
            if (this instanceof HelloWorld) System.out.println(message);
        }
    }
}