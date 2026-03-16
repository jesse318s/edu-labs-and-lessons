/**
 * Clean Code Demonstration - Refactored Main Class
 * This class demonstrates fundamental programming concepts using clean code
 * principles
 * 
 * @author Workshop Instructor
 * @version 2.0 - Refactored for Clean Code Workshop
 */
public class CleanMain {

    /**
     * Entry point for the clean code demonstration
     * Each method call demonstrates a specific programming concept
     */
    public static void main(String[] args) {
        demonstrateBasicOperations();

        demonstrateDataStructures();

        demonstrateControlFlow();

        demonstrateFunctionalProgramming();

        demonstrateObjectOrientedProgramming();
    }

    /**
     * Demonstrates variable declaration and basic arithmetic operations
     */
    private static void demonstrateBasicOperations() {
        System.out.println("=== Basic Operations Demo ===");

        // Variable declaration with meaningful names
        int firstOperand = 1;
        int secondOperand = 2;

        // Basic arithmetic operations
        System.out.println("Sum: " + add(firstOperand, secondOperand));
        System.out.println("Difference: " + subtract(firstOperand, secondOperand));

        System.out.println();
    }

    /**
     * Demonstrates data types and array manipulation
     */
    private static void demonstrateDataStructures() {
        System.out.println("=== Data Structures Demo ===");

        // Array declaration with descriptive name
        int[] sampleNumbers = { 1, 2, 3, 4, 5 };

        // Type conversion demonstration
        String firstElementAsString = convertFirstElementToString(sampleNumbers);
        System.out.println("First element as string: " + firstElementAsString);

        System.out.println();
    }

    /**
     * Demonstrates conditional statements and loops
     */
    private static void demonstrateControlFlow() {
        System.out.println("=== Control Flow Demo ===");

        int firstNumber = 1;
        int secondNumber = 2;

        // Conditional logic with meaningful comparison
        demonstrateConditionalLogic(firstNumber, secondNumber);

        // Loop demonstration
        demonstrateCountdownLoop();

        System.out.println();
    }

    /**
     * Demonstrates functional programming with pure functions
     */
    private static void demonstrateFunctionalProgramming() {
        System.out.println("=== Functional Programming Demo ===");

        int operandOne = 1;
        int operandTwo = 2;

        // Pure function calls
        System.out.println("Function result 1: " + add(operandOne, operandTwo));
        System.out.println("Function result 2: " + add(1, 2));

        System.out.println();
    }

    /**
     * Demonstrates object-oriented programming principles
     */
    private static void demonstrateObjectOrientedProgramming() {
        System.out.println("=== Object-Oriented Programming Demo ===");

        // Object creation and method calls
        Greeting firstGreeting = new Greeting();
        firstGreeting.displayMessage();
        firstGreeting.showSpecialStatus();

        Greeting secondGreeting = new Greeting();
        secondGreeting.setSpecialStatus(false);
        secondGreeting.showSpecialStatus();

        // Static method call
        Greeting.displayObjectCount();

        System.out.println();
    }

    // ===============================
    // UTILITY METHODS
    // ===============================

    /**
     * Adds two integers and returns the result
     * This is a pure function with no side effects
     * 
     * @param firstNumber  the first integer to add
     * @param secondNumber the second integer to add
     * @return the sum of the two integers
     */
    public static int add(int firstNumber, int secondNumber) {
        return firstNumber + secondNumber;
    }

    /**
     * Subtracts the second number from the first
     * 
     * @param minuend    the number to subtract from
     * @param subtrahend the number to subtract
     * @return the difference between the two numbers
     */
    public static int subtract(int minuend, int subtrahend) {
        return minuend - subtrahend;
    }

    /**
     * Converts the first element of an integer array to a string
     * 
     * @param numbers array of integers
     * @return string representation of the first element
     */
    private static String convertFirstElementToString(int[] numbers) {
        if (numbers.length == 0)
            return "Array is empty";

        return Integer.toString(numbers[0]);
    }

    /**
     * Demonstrates conditional logic with meaningful variable names
     * 
     * @param firstValue  first integer for comparison
     * @param secondValue second integer for comparison
     */
    private static void demonstrateConditionalLogic(int firstValue, int secondValue) {
        int sum = add(firstValue, secondValue);
        final int EXPECTED_SUM = 3;

        if (sum == EXPECTED_SUM) {
            System.out.println("Sum equals expected value: " + EXPECTED_SUM);
        } else {
            System.out.println("Sum does not equal expected value: " + EXPECTED_SUM);
        }
    }

    /**
     * Demonstrates a while loop with clear variable naming
     */
    private static void demonstrateCountdownLoop() {
        final int STARTING_COUNT = 5;

        System.out.println("Countdown sequence:");
        for (int currentNumber = STARTING_COUNT; currentNumber > 0; currentNumber--) {
            System.out.println("T-minus: " + currentNumber);
        }
        System.out.println("Blast off! 🚀");
    }

    // ===============================
    // INNER CLASSES FOR OOP DEMO
    // ===============================

    /**
     * Abstract base class demonstrating inheritance and abstraction
     */
    abstract static class Messenger {
        protected abstract void showSpecialStatus();
    }

    /**
     * Concrete implementation demonstrating encapsulation, inheritance, and
     * polymorphism
     * Final class prevents further inheritance
     */
    public static final class Greeting extends Messenger {
        private static int objectCount = 0;
        private boolean isSpecial = true;
        public static final String DEFAULT_MESSAGE = "Hello, World!";

        /**
         * Constructor that increments the object counter
         */
        public Greeting() {
            objectCount++;
        }

        /**
         * Sets the object counter to a new value
         * 
         * @param newCount the new count value
         */
        public static void setObjectCount(int newCount) {
            objectCount = newCount;
        }

        /**
         * Displays the current object count
         */
        public static void displayObjectCount() {
            System.out.println("Number of Greeting objects created: " + objectCount);
        }

        /**
         * Sets the special status of this greeting
         * 
         * @param specialStatus true if this greeting is special, false otherwise
         */
        public void setSpecialStatus(boolean specialStatus) {
            this.isSpecial = specialStatus;
        }

        /**
         * Displays the special status of this greeting
         * Overrides the abstract method from parent class
         */
        @Override
        public void showSpecialStatus() {
            System.out.println("Special status: " + isSpecial);
        }

        /**
         * Displays the greeting message if this is a Greeting instance
         * Demonstrates instanceof usage and polymorphism
         */
        public void displayMessage() {
            if (this instanceof Greeting) {
                System.out.println(DEFAULT_MESSAGE);
            }
        }
    }
}
