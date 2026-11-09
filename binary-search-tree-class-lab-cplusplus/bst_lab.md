# Binary Search Tree Lab

## Overview

This lab explores the binary search tree (BST), a foundational ordered tree structure. A BST keeps its keys in sorted order while still allowing fast search, insertion, and deletion. When the tree stays roughly balanced, those operations run in O(log n) time.

This is a **writing lab**. The class interface and a full test harness are provided, but you implement the tree yourself in `bst_starter.cpp`. A completed reference implementation lives in `bst_solution.cpp` so you can check your work after you have made a serious attempt.

## Learning Objectives

By the end of this lab, students should be able to:

1. Explain the binary search tree ordering property and use it to trace a search.
2. Implement insertion, search, minimum, maximum, and all three deletion cases.
3. Perform and interpret inorder, preorder, and postorder traversals.
4. Verify that a binary tree satisfies the BST property using low and high bounds.
5. Analyze why an unbalanced BST degrades to O(n) and why that motivates self-balancing trees.

## Binary Search Tree Properties

A binary search tree is a binary tree with the following properties:

1. For every node, all keys in the left subtree are smaller than the node's key.
2. For every node, all keys in the right subtree are larger than the node's key.
3. Every left and right subtree is also a binary search tree.
4. In this implementation duplicate keys are not stored, so the ordering is strict.

The ordering property has an important consequence: an inorder traversal visits the keys in ascending order.

### Height Convention

This implementation measures height in nodes:

- An empty tree has height 0.
- A leaf has height 1.
- A node's height is 1 plus the larger of its children's heights.

Use this convention consistently when computing and reporting heights.

## Key Operations

### 1. Search

Search follows the ordering property:

1. Compare the target key with the current node.
2. Move left when the target is smaller.
3. Move right when the target is larger.
4. Stop when the key is found or the search reaches an empty subtree.

`contains()` returns `true` when the key is present and `false` otherwise.

### 2. Insertion

Insertion uses the same descent:

1. Descend from the root, moving left or right based on the new key.
2. When an empty child slot is reached, attach the new key there as a leaf.
3. If the key already exists, leave the tree unchanged.

`insert()` returns `true` when a key is added and `false` when the key already exists. Duplicates are ignored.

### 3. Deletion

Deletion has three cases:

1. The node has no children. Remove it directly.
2. The node has one child. Replace the node with that child.
3. The node has two children. Copy the key of the inorder successor (the smallest key in the right subtree) into the node, then delete the successor from the right subtree. The successor has no left child, so this final deletion falls into case 1 or case 2.

`remove()` returns `true` when a key is removed and `false` when the key is not present.

### 4. Minimum and Maximum

- The minimum key is the leftmost node.
- The maximum key is the rightmost node.

Both `minimum()` and `maximum()` throw `std::runtime_error` when the tree is empty.

### 5. Traversals

The class must provide three traversals:

- `inorder()` returns keys in ascending order.
- `preorder()` visits the node before its children.
- `postorder()` visits the node after its children.

Each traversal visits every node once, so all of them run in O(n) time.

### 6. Height

`height()` returns the height of the tree in nodes. The tree does not cache node heights, so `height()` walks the whole tree and runs in O(n) time.

## Complexity

| Operation | Average | Worst Case |
| --- | --- | --- |
| Search | O(log n) | O(n) |
| Insert | O(log n) | O(n) |
| Delete | O(log n) | O(n) |
| Minimum / Maximum | O(log n) | O(n) |
| Inorder traversal | O(n) | O(n) |
| Height | O(n) | O(n) |

The average column assumes a roughly balanced shape. The worst case occurs when the tree degenerates into a chain. For example, inserting `1, 2, 3, 4, 5, ...` in ascending order makes every new key the right child of the previous key, so the height becomes n and each operation walks the entire chain.

The tree stores n nodes, so it uses O(n) space. Recursive operations also use O(h) stack space, where h is the height.

## Binary Search Trees vs Self-Balancing Trees

A plain BST makes no promise about its shape, so its worst-case performance is no better than a linked list. A self-balancing tree fixes this by reorganizing itself during updates, keeping the height (and therefore the cost of search, insertion, and deletion) logarithmic.

This lab focuses only on the plain BST. Understanding its degenerate case is the motivation for studying balanced variants later.

## The Class You Will Complete

The interface is already written in `bst.h`. Do not change it; the provided tests in `main.cpp` depend on every method.

`bst.h` declares two things:

- `BSTNode` stores an `int` key and left and right child pointers.
- `BinarySearchTree` stores the root and the number of nodes, and declares the public operations below.

| Method | Expected behavior |
| --- | --- |
| `insert(int key)` | Add a key as a leaf. Return `false` if the key already exists. |
| `remove(int key)` | Delete a key using the three cases. Return `false` if it is missing. |
| `contains(int key)` | Return whether the key is present. |
| `minimum()` / `maximum()` | Return the smallest / largest key, or throw when empty. |
| `size()` / `empty()` | Return the node count / whether the tree has no nodes. |
| `height()` | Return the height in nodes (empty = 0, leaf = 1). |
| `inorder()` / `preorder()` / `postorder()` | Return keys in the matching order. |
| `isValidBST()` | Return whether the ordering property holds everywhere. |
| `printTree()` | Print an indented tree (format below). |

`bst.h` also declares a set of private helpers (`destroy`, `nodeHeight`, `findMin`, `findMax`, the traversal helpers, `validateHelper`, `printHelper`, and the recursive `insertHelper` / `removeHelper`). They are suggestions, not requirements: use them if they help, or add your own.

`printTree()` should print output in this format for the keys `50, 30, 70, 20, 40, 60, 80`:

```text
R----50
     L----30
     |    L----20
     |    R----40
     R----70
          L----60
          R----80
```

An empty tree should print exactly `Tree is empty`.

## Your Task

Now that you understand how a BST works, **write your own tree**. The explanation above tells you what each operation should do; the code is your job.

1. Open `bst_starter.cpp`. The constructors, destructor, `destroy()`, `size()`, and `empty()` are already implemented so you can focus on the algorithms.
2. Implement the TODO methods in this order:
   1. `contains()`
   2. `insert()`
   3. `inorder()`, `preorder()`, `postorder()`
   4. `minimum()`, `maximum()`
   5. `height()`
   6. `isValidBST()`
   7. `printTree()`
   8. `remove()`
3. Build and run your work after each step:
   ```bash
   make run
   ```
   The tests run as one suite, so an early run stops at the first unimplemented behavior. Treat that failing `assert` as your current checklist item; feel free to comment out later `test...()` calls in `main()` while you work.

Hints, not answers:

- Most operations are naturally recursive. A helper that takes a `BSTNode *` and returns the possibly-updated subtree root works well.
- For the two-child deletion case, find the minimum node in the right subtree, copy its key up, then delete that minimum key from the right subtree.
- Do not validate a BST by checking only each node against its immediate children. Pass a valid `low` and `high` range down the recursion, or compare against the previous key during an inorder walk.
- Keep `count` in sync with the number of actual nodes.

Acceptance criteria: every assertion in `main.cpp` passes, the demos print sensible trees, and `isValidBST()` still returns `true` after arbitrary insertions and deletions.

## Running the Lab

Build and run your implementation:

```bash
make        # compile main.cpp and bst_starter.cpp into program.exe
make run    # build and run the starter
make clean  # remove *.o and program.exe
```

If `make` is not available, compile directly:

```bash
g++ -g -Wall -std=c++11 main.cpp bst_starter.cpp -o program.exe
./program.exe
```

The reference solution is not part of the default build. To compile it separately:

```bash
g++ -g -Wall -std=c++11 main.cpp bst_solution.cpp -o bst_solution.exe
./bst_solution.exe
```

## Lab Exercises

### Exercise 1: Tracing Operations

Draw the tree after each operation and state the result.

1. Insert `50, 30, 70, 20, 40, 60, 80`. What is the height?
2. Delete `20`, then `30`, then `50`. Show the tree after each deletion and identify which deletion case applied.
3. Insert `10, 20, 30, 40, 50` in order into an empty BST. What is the height, and why?

Verify each result with `printTree()`, `height()`, and `isValidBST()`.

### Exercise 2: Validating the Ordering Property

A common mistake is to check only that `node->left->key < node->key < node->right->key` at each node. Explain why this is not enough by constructing a small tree that passes the local check but is not a valid BST. Then explain how a low/high range passed down the recursion avoids the problem.

### Exercise 3: Code Analysis

After your implementation passes, answer the following:

1. In the two-child deletion case, why is it safe to reuse the one-child deletion logic to remove the successor?
2. Why must `destroy()` free the children before the parent?
3. Why does `height()` run in O(n) while `contains()` runs in O(h)?
4. Why is the copy constructor deleted?

### Exercise 4: Implementation Challenges

1. Add a `countNodes()` method that returns the number of nodes without using the `count` member.
2. Add a `kthSmallest(int k)` method that returns the k-th smallest key.
3. Add a `successor(int key)` method that returns the next key in sorted order, or throws when there is none.
4. Add an `isBalanced()` method that returns `true` when every node's subtree heights differ by at most one.
5. Add a `rangeQuery(int low, int high)` method that returns all keys in the inclusive range `[low, high]`, pruning subtrees that cannot contain answers.

### Exercise 5: Performance and Analysis

1. Insert 10,000 keys in ascending order into a `BinarySearchTree` and record the height and the time needed for 1,000 searches. Then repeat the experiment with the keys inserted in random order and compare the two heights and search times.
2. Explain why insertion order changes the height of a plain BST so dramatically.
3. Based on the worst-case behavior you observed, explain why an application with strict performance guarantees might avoid a plain BST.

## Quiz Questions

1. What is the defining property of a binary search tree?
   a) Every node has exactly two children
   b) All keys in the left subtree are smaller than the node, and all keys in the right subtree are larger
   c) The tree is always balanced
   d) The root always stores the smallest key

2. Which traversal returns the keys of a BST in ascending order?
   a) Preorder
   b) Postorder
   c) Inorder
   d) Reverse inorder

3. When deleting a node with two children, which key is copied into the node in this implementation?
   a) Its left child's key
   b) Its right child's key
   c) The inorder successor's key
   d) The root's key

4. What is the worst-case height of a plain binary search tree with n nodes?
   a) O(1)
   b) O(log n)
   c) O(n)
   d) O(n log n)

5. Why is a self-balancing tree useful?
   a) It stores more keys than a plain BST
   b) It guarantees O(log n) search times even if data is inserted in sorted order
   c) It removes the need for a root node
   d) It makes inorder traversal unnecessary

## Quiz Answers

1. b) All keys in the left subtree are smaller than the node, and all keys in the right subtree are larger
2. c) Inorder
3. c) The inorder successor's key
4. c) O(n)
5. b) It guarantees O(log n) search times even if data is inserted in sorted order
