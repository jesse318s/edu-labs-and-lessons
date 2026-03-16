#include <iostream>
#include <cassert>
#include "red_black_tree.h"
#include "red_black_tree.cpp"

void testRedBlackTreeInsertion()
{
    std::cout << "\n===== Testing Red-Black Tree Insertion =====" << std::endl;

    RedBlackTree<int> rbt;

    // Insert some values
    rbt.insert(10);
    rbt.insert(20);
    rbt.insert(5);
    rbt.insert(15);
    rbt.insert(30);

    std::cout << "Tree after insertions:" << std::endl;
    rbt.printTree();

    // Verify tree properties
    assert(rbt.search(10) == true);
    assert(rbt.search(20) == true);
    assert(rbt.search(5) == true);
    assert(rbt.search(15) == true);
    assert(rbt.search(30) == true);
    assert(rbt.search(100) == false);

    std::cout << "Min value: " << rbt.getMinimum() << std::endl;
    std::cout << "Max value: " << rbt.getMaximum() << std::endl;
    std::cout << "Black height: " << rbt.getBlackHeight() << std::endl;

    std::cout << "Inorder traversal: ";
    rbt.inorder();
    std::cout << "Preorder traversal: ";
    rbt.preorder();
    std::cout << "Postorder traversal: ";
    rbt.postorder();
}

void testRedBlackTreeDeletion()
{
    std::cout << "\n===== Testing Red-Black Tree Deletion =====" << std::endl;

    RedBlackTree<int> rbt;

    // Insert values
    int values[] = {50, 30, 70, 20, 40, 60, 80};
    for (int val : values)
    {
        rbt.insert(val);
    }

    std::cout << "Tree before deletion:" << std::endl;
    rbt.printTree();
    std::cout << "Inorder traversal before deletion: ";
    rbt.inorder();

    // Test removal
    rbt.remove(20); // Remove a leaf node
    std::cout << "\nAfter removing 20 (leaf node):" << std::endl;
    rbt.printTree();

    rbt.remove(30); // Remove a node with one child
    std::cout << "\nAfter removing 30 (node with one child):" << std::endl;
    rbt.printTree();

    rbt.remove(50); // Remove root node with two children
    std::cout << "\nAfter removing 50 (node with two children):" << std::endl;
    rbt.printTree();

    // Verify tree properties after deletion
    assert(rbt.search(20) == false);
    assert(rbt.search(30) == false);
    assert(rbt.search(50) == false);
    assert(rbt.search(40) == true);
    assert(rbt.search(60) == true);
    assert(rbt.search(70) == true);
    assert(rbt.search(80) == true);

    std::cout << "Inorder traversal after deletion: ";
    rbt.inorder();
    std::cout << "Black height after deletion: " << rbt.getBlackHeight() << std::endl;
}

void testLargeRedBlackTree()
{
    std::cout << "\n===== Testing Large Red-Black Tree =====" << std::endl;

    RedBlackTree<int> rbt;
    const int NUM_ELEMENTS = 100;

    // Insert values in ascending order (worst case for BST)
    std::cout << "Inserting " << NUM_ELEMENTS << " elements in ascending order..." << std::endl;
    for (int i = 1; i <= NUM_ELEMENTS; i++)
    {
        rbt.insert(i);
    }

    // Verify black height is logarithmic in the number of nodes
    int blackHeight = rbt.getBlackHeight();
    std::cout << "Black height of tree with " << NUM_ELEMENTS << " elements: " << blackHeight << std::endl;

    // Check that all elements are searchable
    for (int i = 1; i <= NUM_ELEMENTS; i++)
    {
        assert(rbt.search(i) == true);
    }

    // Remove some elements
    for (int i = 1; i <= NUM_ELEMENTS; i += 10)
    {
        rbt.remove(i);
    }

    // Verify removed elements are no longer in the tree
    for (int i = 1; i <= NUM_ELEMENTS; i += 10)
    {
        assert(rbt.search(i) == false);
    }

    std::cout << "All large tree tests passed!" << std::endl;
}

int main()
{
    std::cout << "========================================" << std::endl;
    std::cout << "       RED-BLACK TREE LAB" << std::endl;
    std::cout << "========================================" << std::endl;

    // Run tests
    testRedBlackTreeInsertion();
    testRedBlackTreeDeletion();
    testLargeRedBlackTree();

    std::cout << "\n========================================" << std::endl;

    // Interactive demo
    std::cout << "\nInteractive Red-Black Tree Demo" << std::endl;
    RedBlackTree<int> interactiveTree;

    std::cout << "\nEntering demo values: 41, 38, 31, 12, 19, 8" << std::endl;
    int demoValues[] = {41, 38, 31, 12, 19, 8};
    for (int val : demoValues)
    {
        interactiveTree.insert(val);
        std::cout << "\nAfter inserting " << val << ":" << std::endl;
        interactiveTree.printTree();
    }

    std::cout << "\nTraversals:" << std::endl;
    std::cout << "Inorder: ";
    interactiveTree.inorder();
    std::cout << "Preorder: ";
    interactiveTree.preorder();
    std::cout << "Postorder: ";
    interactiveTree.postorder();

    return 0;
}