# AVL Tree Lab

## Overview

This lab explores AVL Trees, a type of self-balancing binary search tree invented by Georgy Adelson-Velsky and Evgenii Landis in 1962. An AVL tree keeps its height logarithmic by enforcing a strict balance condition at every node. This guarantees O(log n) time complexity for search, insertion, and deletion, even when keys arrive in sorted order.

The implementation for this lab is written in Python and is split across `avl_tree.py`, `main.py`, and `test_avl_tree.py`.

## Learning Objectives

By the end of this lab, students should be able to:

1. Explain the AVL balance property and calculate balance factors.
2. Trace left, right, left-right, and right-left rotations.
3. Implement insertion and deletion while restoring the AVL property.
4. Verify that a binary tree satisfies both BST ordering and AVL balancing rules.
5. Compare AVL trees with red-black trees and choose an appropriate structure for a problem.

## AVL Tree Properties

An AVL tree is a binary search tree with the following properties:

1. For every node, all keys in the left subtree are smaller than the node's key.
2. For every node, all keys in the right subtree are larger than the node's key.
3. For every node, the height of its left and right subtrees differs by at most one.
4. Every subtree of an AVL tree is also an AVL tree.

The balance factor of a node is defined as:

```text
balance factor = height(left subtree) - height(right subtree)
```

A node is balanced when its balance factor is -1, 0, or 1. A balance factor of 2 or -2 means the subtree must be rotated.

### Height Convention

This implementation measures height in nodes:

- An empty tree has height 0.
- A leaf has height 1.
- A node's height is 1 plus the larger of its children's heights.

Some textbooks measure height in edges instead. The balancing logic is the same, but the numeric heights differ by one. Pick one convention and use it consistently.

## Key Operations

### 1. Rotation Operations

Rotations rearrange a small part of the tree without changing the inorder sequence. They are the only structural changes needed to restore balance.

| Case | Shape After Insertion | Rotation Used |
| --- | --- | --- |
| Left-Left (LL) | New key is in the left subtree of the left child | Single right rotation |
| Right-Right (RR) | New key is in the right subtree of the right child | Single left rotation |
| Left-Right (LR) | New key is in the right subtree of the left child | Left rotation on the child, then right rotation on the node |
| Right-Left (RL) | New key is in the left subtree of the right child | Right rotation on the child, then left rotation on the node |

Example of a left rotation around node `x`:

```text
    x                y
     \              / \
      y     --->   x   z
     / \            \
    z   ...          z
```

Example of a right rotation around node `y`:

```text
      y              x
     /              / \
    x      --->    z   y
   / \                /
  z   ...            ...
```

### 2. Insertion

Insertion follows the normal binary search tree process:

1. Descend from the root, moving left or right based on the new key.
2. Insert the new key as a leaf with height 1.
3. On the way back up the recursion, update each node's height.
4. Calculate the balance factor.
5. If the balance factor is outside the range [-1, 1], apply the appropriate rotation.

In this implementation, duplicate keys are ignored. `insert()` returns `True` when a key is added and `False` when the key already exists.

### 3. Deletion

Deletion has three basic cases:

1. The node has no children. Remove it directly.
2. The node has one child. Replace the node with its child.
3. The node has two children. Copy the key of the inorder successor into the node, then delete the successor from the right subtree.

After the key is removed, heights are updated and rotations are applied on the way back up the recursion. `delete()` returns `True` when a key is removed and `False` when the key is not present.

### 4. Search

Search is the same as in an ordinary binary search tree:

1. Compare the target key with the current node.
2. Move left when the target is smaller.
3. Move right when the target is larger.
4. Stop when the key is found or the search reaches an empty subtree.

Because the tree stays balanced, the search path is O(log n) in the worst case.

### 5. Traversals

The implementation provides four traversals:

- `inorder()` returns keys in ascending order.
- `preorder()` visits the node before its children.
- `postorder()` visits the node after its children.
- `level_order()` returns keys by level using a queue.

The tree also supports Python's container syntax:

```python
from avl_tree import AVLTree

tree = AVLTree()

for key in (30, 20, 10, 25, 40):
    tree.insert(key)

print(len(tree))          # 5
print(10 in tree)         # True
print(list(tree))         # [10, 20, 25, 30, 40]
print(tree.height)        # 3
print(tree.is_valid_avl())  # True
```

## Implementation Notes

`avl_tree.py` contains two classes:

- `AVLNode` stores a key, left and right child references, and a cached height.
- `AVLTree` stores the root and size and provides insertion, deletion, search, traversal, validation, and display methods.

Important helper methods:

| Method | Purpose |
| --- | --- |
| `_node_height()` | Returns 0 for `None` and the stored height otherwise |
| `_update_height()` | Recomputes a node's height from its children |
| `_balance_factor()` | Computes left height minus right height |
| `_rotate_left()` | Performs a single left rotation |
| `_rotate_right()` | Performs a single right rotation |
| `_rebalance()` | Chooses the correct rotation for a node |
| `is_valid_avl()` | Checks BST ordering, cached heights, and balance factors |
| `print_tree()` | Prints an indented tree with heights and balance factors |

`print_tree()` shows output in this format:

```text
R----20 (h=3, bf=0)
     L----10 (h=2, bf=0)
     |    L----5 (h=1, bf=0)
     |    R----15 (h=1, bf=0)
     R----30 (h=2, bf=0)
          L----25 (h=1, bf=0)
          R----35 (h=1, bf=0)
```

## Complexity

| Operation | Average | Worst Case |
| --- | --- | --- |
| Search | O(log n) | O(log n) |
| Insert | O(log n) | O(log n) |
| Delete | O(log n) | O(log n) |
| Inorder traversal | O(n) | O(n) |

Each rotation takes constant time, and at most O(log n) nodes are visited along the path from the root to the modified location.

## AVL Trees vs Red-Black Trees

Both AVL trees and red-black trees guarantee O(log n) operations, but they balance differently.

- AVL trees enforce a stricter balance condition, so they are usually shorter and faster for lookups.
- Red-black trees allow more imbalance, so they usually require fewer rotations during insertion and deletion.
- AVL trees are a good choice when searches dominate and updates are relatively rare.
- Red-black trees are a good choice for write-heavy applications and are used in many standard libraries.

## Running the Lab

Run the example from this folder:

```bash
python main.py
```

Run the unit tests with `unittest`:

```bash
python -m unittest test_avl_tree.py -v
```

The tests cover insertion, search, duplicate handling, all four rotation cases, deletion cases, traversals, validation, and display output.

## Lab Exercises

### Exercise 1: Rotation Tracing

Draw the AVL tree after each insertion for the following sequences. Identify every rotation that occurs and state whether it is LL, RR, LR, or RL.

1. Insert `30, 20, 10, 40, 50, 25`.
2. Insert `50, 40, 30, 20, 10, 5`.
3. Insert `10, 20, 30, 40, 50, 60`.

Verify each result with `print_tree()` and `is_valid_avl()`.

### Exercise 2: Understanding the Balance Factor

1. Explain why the balance factor can never be greater than 2 or less than -2 immediately after a single insertion.
2. Explain why a balance factor of 2 requires a rotation, while a balance factor of 1 or -1 does not.
3. Modify `print_tree()` to print only nodes whose balance factor is not zero.

### Exercise 3: Code Analysis

Review `avl_tree.py` and answer the following:

1. Why does `_rebalance()` call `_update_height()` before calculating the balance factor?
2. Why must the lower node be updated before the upper node inside `_rotate_left()` and `_rotate_right()`?
3. In `_delete()`, why is the recursion repeated after copying the inorder successor's key?
4. Why does `is_valid_avl()` check both the BST ordering and the cached heights?

### Exercise 4: Implementation Challenges

1. Add a `count_nodes()` method that returns the number of nodes without using `len()` or `self._size`.
2. Add a `node_count_by_level()` method that returns a list containing the number of nodes at each level.
3. Add a `successor(key)` method that returns the next key in sorted order, or `None` if the key is the maximum.
4. Add an `is_perfect()` method that returns `True` only when every internal node has two children and all leaves are at the same depth.
5. Add a `range_query(low, high)` method that returns all keys in the inclusive range `[low, high]`, pruning subtrees that cannot contain answers.

### Exercise 5: Application and Performance

1. Insert 10,000 keys in ascending order into both an `AVLTree` and an unbalanced `BinarySearchTree` that you write yourself. Compare the heights and the time needed for 1,000 searches.
2. Explain which structure you would choose for a read-heavy application and which you would choose for a write-heavy application.

## Quiz Questions

1. What is the balance factor of a node in an AVL tree?
   a) height(left subtree) + height(right subtree)
   b) height(left subtree) - height(right subtree)
   c) number of nodes in the left subtree minus number of nodes in the right subtree
   d) the depth of the node from the root

2. Which rotation is required when a new key is inserted into the right subtree of a node's left child and that insertion makes the node left-heavy?
   a) Single left rotation
   b) Single right rotation
   c) Left-right double rotation
   d) Right-left double rotation

3. What is the worst-case height of an AVL tree with n nodes?
   a) O(1)
   b) O(log n)
   c) O(n)
   d) O(n log n)

4. After inserting a key, which nodes may need their heights and balance factors updated?
   a) Only the new leaf
   b) Only the root
   c) The new leaf's ancestors up to the root
   d) Every node in the tree

5. Which statement best describes the trade-off between AVL trees and red-black trees?
   a) AVL trees always use less memory than red-black trees
   b) AVL trees are more strictly balanced and usually faster for lookups, while red-black trees usually require fewer rotations for updates
   c) Red-black trees guarantee O(log n) operations, while AVL trees do not
   d) AVL trees cannot support deletion

## Quiz Answers

1. b) height(left subtree) - height(right subtree)
2. c) Left-right double rotation
3. b) O(log n)
4. c) The new leaf's ancestors up to the root
5. b) AVL trees are more strictly balanced and usually faster for lookups, while red-black trees usually require fewer rotations for updates
