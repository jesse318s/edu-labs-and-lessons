/**
 * Space Complexity Lab
 * 
 * This lab explores the concept of space complexity in algorithms,
 * providing examples and exercises to understand memory usage patterns.
 */

#include <iostream>
#include <vector>
#include <string>

// Function declarations
void explainSpaceComplexity();
void demonstrateConstantSpace();
void demonstrateLinearSpace(int n);
void demonstrateQuadraticSpace(int n);
int fibonacciRecursive(int n);
int fibonacciIterative(int n);
void compareSpaceComplexity();
void runExercises();
void testSolutions();

int main() {
    std::cout << "=== SPACE COMPLEXITY LAB ===" << std::endl << std::endl;
    
    explainSpaceComplexity();
    
    std::cout << "\n=== EXAMPLES ===" << std::endl;
    demonstrateConstantSpace();
    demonstrateLinearSpace(5);
    demonstrateQuadraticSpace(3);
    compareSpaceComplexity();
    
    std::cout << "\n=== EXERCISES ===" << std::endl;
    runExercises();
    
    std::cout << "\n=== TESTING SOLUTIONS ===" << std::endl;
    testSolutions();
    
    return 0;
}

/**
 * Provides a clear explanation of space complexity concepts
 */
void explainSpaceComplexity() {
    std::cout << "UNDERSTANDING SPACE COMPLEXITY" << std::endl;
    std::cout << "-----------------------------" << std::endl;
    std::cout << "Space complexity measures the amount of memory an algorithm uses" << std::endl;
    std::cout << "relative to its input size. It helps us understand how memory usage" << std::endl;
    std::cout << "scales as the input grows larger." << std::endl << std::endl;
    
    std::cout << "Common space complexity notations:" << std::endl;
    std::cout << "- O(1): Constant space - memory usage doesn't change with input size" << std::endl;
    std::cout << "- O(log n): Logarithmic space - memory grows logarithmically with input" << std::endl;
    std::cout << "- O(n): Linear space - memory grows proportionally to input size" << std::endl;
    std::cout << "- O(n²): Quadratic space - memory grows as square of input size" << std::endl;
    std::cout << "- O(2^n): Exponential space - memory doubles with each input increment" << std::endl << std::endl;
    
    std::cout << "When analyzing space complexity, we consider:" << std::endl;
    std::cout << "1. Variables and data structures declared in the algorithm" << std::endl;
    std::cout << "2. Call stack space for recursive functions" << std::endl;
    std::cout << "3. Auxiliary space (temporary space used during execution)" << std::endl;
}

/**
 * Demonstrates O(1) constant space complexity
 */
void demonstrateConstantSpace() {
    std::cout << "\nO(1) CONSTANT SPACE EXAMPLE:" << std::endl;
    std::cout << "----------------------------" << std::endl;
    
    int a = 5;
    int b = 10;
    int sum = a + b;
    
    std::cout << "int a = 5;" << std::endl;
    std::cout << "int b = 10;" << std::endl;
    std::cout << "int sum = a + b; // sum = " << sum << std::endl << std::endl;
    
    std::cout << "Space complexity: O(1)" << std::endl;
    std::cout << "Explanation: This function uses a fixed amount of memory" << std::endl;
    std::cout << "regardless of any input size. We're only creating three" << std::endl;
    std::cout << "integer variables that occupy constant space." << std::endl;
}

/**
 * Demonstrates O(n) linear space complexity
 * @param n The size parameter determining space usage
 */
void demonstrateLinearSpace(int n) {
    std::cout << "\nO(n) LINEAR SPACE EXAMPLE (n = " << n << "):" << std::endl;
    std::cout << "----------------------------" << std::endl;
    
    std::cout << "std::vector<int> numbers(n);" << std::endl;
    std::vector<int> numbers(n);
    
    std::cout << "Creating array of size " << n << std::endl;
    for (int i = 0; i < n; i++) {
        numbers[i] = i * 2;
        std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;
    }
    
    std::cout << "\nSpace complexity: O(n)" << std::endl;
    std::cout << "Explanation: The memory used by the vector grows linearly" << std::endl;
    std::cout << "with the input size n. If we double n, we double the memory used." << std::endl;
}

/**
 * Demonstrates O(n²) quadratic space complexity
 * @param n The size parameter determining space usage
 */
void demonstrateQuadraticSpace(int n) {
    std::cout << "\nO(n^2) QUADRATIC SPACE EXAMPLE (n = " << n << "):" << std::endl;
    std::cout << "-------------------------------" << std::endl;
    
    std::cout << "std::vector<std::vector<int>> matrix(n, std::vector<int>(n));" << std::endl;
    std::vector<std::vector<int>> matrix(n, std::vector<int>(n));
    
    std::cout << "Creating " << n << "x" << n << " matrix:" << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = i * n + j;
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    
    std::cout << "\nSpace complexity: O(n^2)" << std::endl;
    std::cout << "Explanation: The memory used by the matrix grows quadratically" << std::endl;
    std::cout << "with the input size n. If we double n, we quadruple the memory used." << std::endl;
}

/**
 * Recursive implementation of Fibonacci number calculation
 * Space complexity: O(n) due to call stack
 * @param n The position in the Fibonacci sequence
 * @return The Fibonacci number at position n
 */
int fibonacciRecursive(int n) {
    // Base cases
    if (n <= 0) return 0;
    if (n == 1) return 1;
    
    // Recursive case
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

/**
 * Iterative implementation of Fibonacci number calculation
 * Space complexity: O(1)
 * @param n The position in the Fibonacci sequence
 * @return The Fibonacci number at position n
 */
int fibonacciIterative(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    
    int prev = 0;
    int current = 1;
    int next;
    
    for (int i = 2; i <= n; i++) {
        next = prev + current;
        prev = current;
        current = next;
    }
    
    return current;
}

/**
 * Compares space complexity of different implementations
 */
void compareSpaceComplexity() {
    std::cout << "\nCOMPARING IMPLEMENTATIONS WITH DIFFERENT SPACE COMPLEXITIES:" << std::endl;
    std::cout << "------------------------------------------------------" << std::endl;
    
    int n = 10;
    
    std::cout << "Calculating Fibonacci(" << n << ") using two different approaches:" << std::endl;
    
    std::cout << "\n1. Recursive implementation (space complexity: O(n))" << std::endl;
    std::cout << "   Result: " << fibonacciRecursive(n) << std::endl;
    std::cout << "   This uses O(n) space due to the call stack depth" << std::endl;
    
    std::cout << "\n2. Iterative implementation (space complexity: O(1))" << std::endl;
    std::cout << "   Result: " << fibonacciIterative(n) << std::endl;
    std::cout << "   This uses O(1) space as it only needs three variables" << std::endl;
    
    std::cout << "\nObservation: Both implementations produce the same result," << std::endl;
    std::cout << "but with different memory efficiency patterns." << std::endl;
}

/**
 * Exercise 1: Analyze the space complexity
 * Students should determine the space complexity of this function
 */
int sumArray(const std::vector<int>& arr) {
    int sum = 0;
    for (int num : arr) {
        sum += num;
    }
    return sum;
}

/**
 * Exercise 2: Analyze the space complexity
 * Students should determine the space complexity of this function
 */
std::vector<int> generateSequence(int n) {
    std::vector<int> result;
    for (int i = 0; i < n; i++) {
        result.push_back(i * i);
    }
    return result;
}

/**
 * Exercise 3: Analyze and improve space complexity
 * Students should identify the inefficient space usage and improve it
 */
int findMax(const std::vector<int>& arr) {
    // Inefficient approach for demonstration
    std::vector<int> copy = arr;
    int max = copy[0];
    for (int i = 1; i < copy.size(); i++) {
        if (copy[i] > max) {
            max = copy[i];
        }
    }
    return max;
}

/**
 * Runs the lab exercises for students
 */
void runExercises() {
    std::cout << "EXERCISE 1: Analyze the space complexity of sumArray()" << std::endl;
    std::cout << "```cpp" << std::endl;
    std::cout << "int sumArray(const std::vector<int>& arr) {" << std::endl;
    std::cout << "    int sum = 0;" << std::endl;
    std::cout << "    for (int num : arr) {" << std::endl;
    std::cout << "        sum += num;" << std::endl;
    std::cout << "    }" << std::endl;
    std::cout << "    return sum;" << std::endl;
    std::cout << "}" << std::endl;
    std::cout << "```" << std::endl;
    std::cout << "What is the space complexity? Explain your reasoning." << std::endl;
    
    std::cout << "\nEXERCISE 2: Analyze the space complexity of generateSequence()" << std::endl;
    std::cout << "```cpp" << std::endl;
    std::cout << "std::vector<int> generateSequence(int n) {" << std::endl;
    std::cout << "    std::vector<int> result;" << std::endl;
    std::cout << "    for (int i = 0; i < n; i++) {" << std::endl;
    std::cout << "        result.push_back(i * i);" << std::endl;
    std::cout << "    }" << std::endl;
    std::cout << "    return result;" << std::endl;
    std::cout << "}" << std::endl;
    std::cout << "```" << std::endl;
    std::cout << "What is the space complexity? Explain your reasoning." << std::endl;
    
    std::cout << "\nEXERCISE 3: Improve the space complexity of findMax()" << std::endl;
    std::cout << "```cpp" << std::endl;
    std::cout << "int findMax(const std::vector<int>& arr) {" << std::endl;
    std::cout << "    // Inefficient approach for demonstration" << std::endl;
    std::cout << "    std::vector<int> copy = arr;" << std::endl;
    std::cout << "    int max = copy[0];" << std::endl;
    std::cout << "    for (int i = 1; i < copy.size(); i++) {" << std::endl;
    std::cout << "        if (copy[i] > max) {" << std::endl;
    std::cout << "            max = copy[i];" << std::endl;
    std::cout << "        }" << std::endl;
    std::cout << "    }" << std::endl;
    std::cout << "    return max;" << std::endl;
    std::cout << "}" << std::endl;
    std::cout << "```" << std::endl;
    std::cout << "1. What is the current space complexity?" << std::endl;
    std::cout << "2. Rewrite the function to improve its space efficiency." << std::endl;
}

/**
 * Tests the space complexity exercises with sample solutions
 */
void testSolutions() {
    // Test Exercise 1
    std::cout << "EXERCISE 1 SOLUTION:" << std::endl;
    std::cout << "The space complexity of sumArray() is O(1)." << std::endl;
    std::cout << "It only uses a single variable 'sum' regardless of input size." << std::endl;
    
    // Test Exercise 2
    std::cout << "\nEXERCISE 2 SOLUTION:" << std::endl;
    std::cout << "The space complexity of generateSequence() is O(n)." << std::endl;
    std::cout << "It creates a vector that grows linearly with the input size n." << std::endl;
    
    // Test Exercise 3
    std::cout << "\nEXERCISE 3 SOLUTION:" << std::endl;
    std::cout << "Current space complexity: O(n) due to the unnecessary array copy." << std::endl;
    std::cout << "Improved version (O(1) space):" << std::endl;
    std::cout << "```cpp" << std::endl;
    std::cout << "int findMaxImproved(const std::vector<int>& arr) {" << std::endl;
    std::cout << "    if (arr.empty()) {" << std::endl;
    std::cout << "        throw std::invalid_argument(\"Array is empty\");" << std::endl;
    std::cout << "    }" << std::endl;
    std::cout << "    int max = arr[0];" << std::endl;
    std::cout << "    for (int i = 1; i < arr.size(); i++) {" << std::endl;
    std::cout << "        if (arr[i] > max) {" << std::endl;
    std::cout << "            max = arr[i];" << std::endl;
    std::cout << "        }" << std::endl;
    std::cout << "    }" << std::endl;
    std::cout << "    return max;" << std::endl;
    std::cout << "}" << std::endl;
    std::cout << "```" << std::endl;
    
    std::cout << "\nCONCLUSION:" << std::endl;
    std::cout << "Understanding space complexity helps you write more memory-efficient code." << std::endl;
    std::cout << "Always consider whether you can reduce memory usage, especially for large inputs." << std::endl;
}