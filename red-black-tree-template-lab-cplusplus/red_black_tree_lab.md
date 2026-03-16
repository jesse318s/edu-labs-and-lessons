# Red-Black Tree Lab

## Overview

This lab explores Red-Black Trees, a type of self-balancing binary search tree that guarantees logarithmic height and efficient operations. Red-Black Trees are widely used in practice and are implemented in various standard libraries including C++ STL map, Java TreeMap, and many more.

## Red-Black Tree Properties

A Red-Black Tree is a binary search tree with the following properties:

1. Every node is either red or black.
2. The root is black.
3. Every leaf (NIL/NULL) is black.
4. If a node is red, both its children are black (no two adjacent red nodes).
5. For each node, all simple paths from the node to descendant leaves contain the same number of black nodes.

These properties ensure that the tree remains approximately balanced, with a height of O(log n), guaranteeing O(log n) time complexity for search, insertion, and deletion operations.

## Key Operations

### 1. Rotation Operations
- **Left Rotation**: A transformation that moves a node down and to the left in the tree.
- **Right Rotation**: A transformation that moves a node down and to the right in the tree.
- Rotations are used to maintain the Red-Black properties during insertion and deletion.

### 2. Insertion
- Insert a node as you would in a binary search tree (initially colored RED).
- Fix any violations of Red-Black properties that may occur.
- Common cases include:
  - Case 1: Uncle is RED
  - Case 2: Uncle is BLACK (triangle configuration)
  - Case 3: Uncle is BLACK (line configuration)

### 3. Deletion
- Delete a node as you would in a binary search tree.
- Fix any violations of Red-Black properties that may occur.
- More complex than insertion, with multiple cases to handle.

## Advantages of Red-Black Trees

- Guaranteed O(log n) time complexity for search, insert, and delete operations.
- Self-balancing without requiring explicit height information at each node.
- More efficient than AVL trees for insertion and deletion.
- Used in systems requiring reliable worst-case performance.

## Lab Exercises

### Exercise 1: Understanding Red-Black Properties
Analyze the implementation of the Red-Black Tree provided in this lab and explain how each of the five properties is maintained during insertion and deletion operations.

### Exercise 2: Visualization
Draw the Red-Black Tree state (with proper coloring) after each of the following operations:
1. Insert the following keys in order: 10, 20, 30, 40, 50
2. After inserting the above, delete 20 from the tree

### Exercise 3: Code Analysis
Review the provided Red-Black Tree implementation:
1. Identify where each of the Red-Black properties is enforced.
2. Explain the purpose of the sentinel node (TNULL) in the implementation.
3. Analyze the time complexity of the insertion and deletion operations.

### Exercise 4: Implementation Challenges
1. Add a method to verify that the tree satisfies all Red-Black properties.
2. Implement a method to count the total number of red and black nodes in the tree.
3. Write a function that returns the longest path (root to leaf) and shortest path in the tree and calculate their ratio.

### Exercise 5: Application
1. Design a symbol table implementation using a Red-Black Tree.
2. Compare the performance of your Red-Black Tree implementation with a standard library implementation (e.g., std::map) for a large dataset.

## Quiz Questions

1. What is the maximum possible height of a Red-Black Tree with n nodes?
   a) log₂(n)
   b) 2 * log₂(n)
   c) n/2
   d) n

2. If a Red-Black Tree has a black height of 3, what is the minimum number of nodes it can have?
   a) 7
   b) 8
   c) 15
   d) 16

3. What color is new node initially assigned during insertion in a Red-Black Tree?
   a) Black
   b) Red
   c) Depends on its parent
   d) Depends on its value

4. Which Red-Black Tree property ensures that the height of the tree is logarithmic?
   a) Property 1: Every node is either red or black
   b) Property 2: The root is black
   c) Property 4: If a node is red, both its children are black
   d) Property 5: All simple paths from a node to leaves contain the same number of black nodes

5. What is the primary advantage of a Red-Black Tree over an AVL tree?
   a) Red-Black Trees use less memory
   b) Red-Black Trees have faster search operations
   c) Red-Black Trees require fewer rotations during insertion and deletion
   d) Red-Black Trees can store more data

## Quiz Answers

1. b) 2 * log₂(n)
2. c) 15
3. b) Red
4. d) Property 5: All simple paths from a node to leaves contain the same number of black nodes
5. c) Red-Black Trees require fewer rotations during insertion and deletion