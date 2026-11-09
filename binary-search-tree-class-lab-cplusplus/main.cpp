// Provided test and demo harness for the Binary Search Tree Lab.
//
// This file is shared by the starter and the solution:
//   make run-starter    builds main.cpp with bst_starter.cpp
//   make run-solution   builds main.cpp with bst_solution.cpp
//
// Do not change the public interface in bst.h; these tests rely on it.

#include <cassert>
#include <cstddef>
#include <iostream>
#include <vector>

#include "bst.h"

void printVector(const std::vector<int> &values)
{
    for (std::size_t i = 0; i < values.size(); ++i)
    {
        if (i > 0)
        {
            std::cout << " ";
        }

        std::cout << values[i];
    }

    std::cout << std::endl;
}

void testInsertAndSearch()
{
    std::cout << "\n===== Testing Insertion and Search =====" << std::endl;

    BinarySearchTree tree;

    assert(tree.empty());
    assert(tree.size() == 0);
    assert(tree.height() == 0);
    assert(tree.isValidBST());

    assert(tree.insert(50));
    assert(tree.insert(30));
    assert(tree.insert(70));
    assert(tree.insert(20));
    assert(tree.insert(40));
    assert(tree.insert(60));
    assert(tree.insert(80));

    assert(!tree.empty());
    assert(tree.size() == 7);
    assert(tree.height() == 3);
    assert(tree.isValidBST());

    assert(tree.contains(50));
    assert(tree.contains(20));
    assert(tree.contains(80));
    assert(!tree.contains(10));
    assert(!tree.contains(100));

    // Duplicate keys are ignored.
    assert(!tree.insert(40));
    assert(tree.size() == 7);

    std::cout << "All insertion and search tests passed!" << std::endl;
}

void testMinimumAndMaximum()
{
    std::cout << "\n===== Testing Minimum and Maximum =====" << std::endl;

    BinarySearchTree tree;

    bool threw = false;

    try
    {
        tree.minimum();
    }
    catch (const std::runtime_error &)
    {
        threw = true;
    }

    assert(threw);

    int keys[] = {50, 30, 70, 20, 40, 60, 80};

    for (int key : keys)
    {
        tree.insert(key);
    }

    assert(tree.minimum() == 20);
    assert(tree.maximum() == 80);

    std::cout << "All minimum and maximum tests passed!" << std::endl;
}

void testTraversals()
{
    std::cout << "\n===== Testing Traversals =====" << std::endl;

    BinarySearchTree tree;
    int keys[] = {50, 30, 70, 20, 40, 60, 80};

    for (int key : keys)
    {
        tree.insert(key);
    }

    std::vector<int> expectedInorder = {20, 30, 40, 50, 60, 70, 80};
    std::vector<int> expectedPreorder = {50, 30, 20, 40, 70, 60, 80};
    std::vector<int> expectedPostorder = {20, 40, 30, 60, 80, 70, 50};

    assert(tree.inorder() == expectedInorder);
    assert(tree.preorder() == expectedPreorder);
    assert(tree.postorder() == expectedPostorder);

    std::cout << "All traversal tests passed!" << std::endl;
}

void testDeletion()
{
    std::cout << "\n===== Testing Deletion =====" << std::endl;

    BinarySearchTree tree;
    int keys[] = {50, 30, 70, 20, 40, 60, 80};

    for (int key : keys)
    {
        tree.insert(key);
    }

    // Remove a leaf.
    assert(tree.remove(20));
    assert(!tree.contains(20));
    assert(tree.size() == 6);
    assert(tree.isValidBST());

    // Remove a node with one child (30 now has only its right child, 40).
    assert(tree.remove(30));
    assert(!tree.contains(30));
    assert(tree.size() == 5);
    assert(tree.isValidBST());

    // Remove a node with two children (the root).
    assert(tree.remove(50));
    assert(!tree.contains(50));
    assert(tree.size() == 4);
    assert(tree.isValidBST());

    // Remove a key that is not present.
    assert(!tree.remove(999));
    assert(tree.size() == 4);

    // Empty the tree one key at a time.
    while (!tree.empty())
    {
        assert(tree.remove(tree.inorder().front()));
        assert(tree.isValidBST());
    }

    assert(tree.size() == 0);
    assert(tree.height() == 0);
    assert(!tree.remove(1));

    std::cout << "All deletion tests passed!" << std::endl;
}

void testDegenerateTree()
{
    std::cout << "\n===== Testing a Degenerate (Unbalanced) Tree =====" << std::endl;

    BinarySearchTree tree;

    // Ascending insertion is the worst case for an unbalanced BST: every new
    // key becomes the right child of the previous key, producing a chain.
    for (int key = 1; key <= 100; ++key)
    {
        assert(tree.insert(key));
    }

    assert(tree.size() == 100);
    assert(tree.height() == 100); // A chain, not a log-height tree.
    assert(tree.isValidBST());

    for (int key = 1; key <= 100; ++key)
    {
        assert(tree.contains(key));
    }

    std::cout << "Height after inserting 1..100 in order: " << tree.height() << std::endl;
    std::cout << "This is the worst case that self-balancing trees prevent." << std::endl;
    std::cout << "All degenerate tree tests passed!" << std::endl;
}

void demoBalancedTree()
{
    std::cout << "\n===== Demo: A Balanced Shape =====" << std::endl;

    BinarySearchTree tree;
    int keys[] = {50, 30, 70, 20, 40, 60, 80};

    for (int key : keys)
    {
        tree.insert(key);
    }

    std::cout << "Tree after inserting 50, 30, 70, 20, 40, 60, 80:" << std::endl;
    tree.printTree();

    std::cout << "\nInorder:     ";
    printVector(tree.inorder());
    std::cout << "Preorder:    ";
    printVector(tree.preorder());
    std::cout << "Postorder:   ";
    printVector(tree.postorder());

    std::cout << "Height: " << tree.height() << std::endl;
    std::cout << "Size:   " << tree.size() << std::endl;
    std::cout << "Minimum: " << tree.minimum() << std::endl;
    std::cout << "Maximum: " << tree.maximum() << std::endl;
    std::cout << "Valid BST: " << (tree.isValidBST() ? "yes" : "no") << std::endl;

    std::cout << "\nRemoving 30 (a node with one child)..." << std::endl;
    tree.remove(30);
    tree.printTree();

    std::cout << "\nRemoving 70 (a node with two children)..." << std::endl;
    tree.remove(70);
    tree.printTree();

    std::cout << "Valid BST after deletions: " << (tree.isValidBST() ? "yes" : "no") << std::endl;
}

void demoDegenerateTree()
{
    std::cout << "\n===== Demo: Sorted Insertions Create a Chain =====" << std::endl;

    BinarySearchTree tree;

    for (int key = 1; key <= 10; ++key)
    {
        tree.insert(key);
    }

    std::cout << "Tree after inserting 1..10 in ascending order:" << std::endl;
    tree.printTree();

    std::cout << "Height: " << tree.height() << " for " << tree.size()
              << " keys (O(n), not O(log n))." << std::endl;
    std::cout << "This is why self-balancing trees exist." << std::endl;
}

int main()
{
    std::cout << "========================================" << std::endl;
    std::cout << "       BINARY SEARCH TREE LAB" << std::endl;
    std::cout << "========================================" << std::endl;

    // Run the test suite.
    testInsertAndSearch();
    testMinimumAndMaximum();
    testTraversals();
    testDeletion();
    testDegenerateTree();

    // Run the demos.
    demoBalancedTree();
    demoDegenerateTree();

    std::cout << "\n========================================" << std::endl;
    std::cout << "All tests passed!" << std::endl;

    return 0;
}
