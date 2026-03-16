/**
 * Programming and Clean Code Fundamentals - Practice Exercises
 * Focus: Learning good habits from the start
 * 
 * Instructions: Complete each exercise using clean code principles
 * Key habits: meaningful names, small functions, clear logic
 */
public class WorkshopExcercises {

    public static void main(String[] args) {
        System.out.println("Programming Fundamentals Practice Exercises\n");

        // Uncomment these as you complete each exercise
        // exercise1_VariableNaming();
        // exercise2_SimpleFunction();
        // exercise3_CleanConditionals();
        // exercise4_OrganizedLoops();
        // exercise5_BasicClass();
    }

    // ===============================
    // EXERCISE 1: MEANINGFUL VARIABLE NAMES
    // ===============================

    /**
     * EXERCISE 1: Fix the variable names to be meaningful
     * 
     * Learning Goal: Variables should clearly express their purpose
     * 
     * Current code uses generic names that tell us nothing about the data
     * Your task: Rename variables to show what they represent
     */
    public static void exercise1_VariableNaming() {
        // BAD CODE - Fix these variable names
        int x = 18; // This is someone's age
        String n = "John"; // This is a person's name
        double p = 25.99; // This is a product price
        boolean f = true; // This indicates if shipping is free

        // Calculate total with tax
        double t = 0.08; // This is the tax rate
        double total = p + (p * t);

        System.out.println(n + " (age " + x + ") bought item for $" + total);
        if (f)
            System.out.println("Free shipping applied!");

        // TODO: Rewrite above with meaningful variable names
        // Hint: age, customerName, productPrice, hasFreeShipping, taxRate
    }

    // ===============================
    // EXERCISE 2: CLEAN FUNCTION DESIGN
    // ===============================

    /**
     * EXERCISE 2: Create a well-designed function
     * 
     * Learning Goal: Functions should do one thing with a clear name
     * 
     * Write a function that calculates the area of a rectangle
     * Requirements:
     * - Use meaningful parameter names
     * - Add JavaDoc documentation
     * - Include a simple validation check
     * - Return the calculated area
     */

    // TODO: Write your calculateRectangleArea function here
    // Hint: Parameters should be length and width
    // Hint: Check for negative values

    public static void exercise2_SimpleFunction() {
        // Test your function here
        // double area = calculateRectangleArea(5.0, 3.0);
        // System.out.println("Rectangle area: " + area);
    }

    // ===============================
    // EXERCISE 3: CLEAN CONDITIONALS
    // ===============================

    /**
     * EXERCISE 3: Write readable conditional logic
     * 
     * Learning Goal: Use constants and clear logic structure
     * 
     * Create a method that determines a student's letter grade based on their score
     * Use constants for grade thresholds instead of magic numbers
     */
    public static void exercise3_CleanConditionals() {
        // TODO: Define constants for grade thresholds
        // final int A_GRADE = ?;
        // final int B_GRADE = ?;
        // etc.

        int studentScore = 87;

        // TODO: Write clean if-else logic to determine letter grade
        // Print the grade with an encouraging message

        // Test with different scores: 95, 87, 76, 65, 45
    }

    // ===============================
    // EXERCISE 4: ORGANIZED LOOPS
    // ===============================

    /**
     * EXERCISE 4: Write clean, purposeful loops
     * 
     * Learning Goal: Loop variables should have meaningful names
     * 
     * Task A: Write a loop to display multiplication table for a number
     * Task B: Write a loop to find the highest score in an array
     */
    public static void exercise4_OrganizedLoops() {
        // Task A: Multiplication table
        int multiplicationNumber = 7;

        // TODO: Write a loop that displays: "7 x 1 = 7", "7 x 2 = 14", etc.
        // Use meaningful variable names like currentMultiplier

        // Task B: Find highest score
        int[] testScores = { 78, 92, 85, 96, 73, 88 };

        // TODO: Write a loop to find and display the highest score
        // Use meaningful variable names like currentScore, highestScore
    }

    // ===============================
    // EXERCISE 5: BASIC CLEAN CLASS
    // ===============================

    /**
     * EXERCISE 5: Design a simple, clean class
     * 
     * Learning Goal: Classes should represent real-world entities clearly
     * 
     * Create a Book class with:
     * - Private fields: title, author, pageCount
     * - Constructor with meaningful parameters
     * - Getter methods with descriptive names
     * - A method to display book information
     * - A method to check if it's a "long book" (over 300 pages)
     */

    // TODO: Create your Book class here
    // Remember: private fields, public methods, meaningful names

    public static void exercise5_BasicClass() {
        // TODO: Test your Book class here
        // Create a book object and test all methods

        // Example:
        // Book myBook = new Book("Java Programming", "John Smith", 450);
        // myBook.displayBookInfo();
        // System.out.println("Is long book: " + myBook.isLongBook());
    }

    // ===============================
    // BONUS CHALLENGE: PUTTING IT ALL TOGETHER
    // ===============================

    /**
     * BONUS: Create a simple grade calculator program
     * 
     * Requirements:
     * - Use meaningful variable names throughout
     * - Break logic into small, focused methods
     * - Use constants for important values
     * - Create a Student class to hold student data
     * - Calculate and display final grades cleanly
     * 
     * This exercise combines all the clean code principles you've learned!
     */

    // TODO: Design your grade calculator system here
}

// ===============================
// SOLUTION HINTS AND TIPS
// ===============================

/*
 * VARIABLE NAMING TIPS:
 * - Use full words, avoid abbreviations
 * - Be specific: customerAge vs age
 * - Use verbs for booleans: isValid, hasPermission
 * - Use nouns for data: studentName, accountBalance
 * 
 * FUNCTION DESIGN TIPS:
 * - One function = one job
 * - Name describes what it does: calculateTax, validateInput
 * - Keep functions short (under 20 lines ideal)
 * - Document complex logic
 * 
 * CONDITIONAL TIPS:
 * - Use constants: final int PASSING_GRADE = 60;
 * - Make conditions readable: if (isStudentEligible())
 * - Provide meaningful feedback messages
 * 
 * LOOP TIPS:
 * - Descriptive counter names: currentDay vs i
 * - Clear loop purpose: for (String courseName : courseList)
 * - Extract complex loop bodies into methods
 * 
 * CLASS DESIGN TIPS:
 * - One class = one responsibility
 * - Private data, public behavior
 * - Meaningful method names: getStudentGPA() vs get()
 * - Constructor should initialize all important fields
 */
