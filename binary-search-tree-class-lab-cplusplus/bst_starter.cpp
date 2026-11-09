// Starter implementation for the Binary Search Tree Lab.
//
// Your job is to complete every TODO below. The public interface in bst.h is
// already provided, and the tests in main.cpp describe the expected behavior.
//
// Work through the methods in this order:
//   1. contains()
//   2. insert()
//   3. inorder(), preorder(), postorder()
//   4. minimum(), maximum()
//   5. height()
//   6. isValidBST()
//   7. printTree()
//   8. remove()
//
// The constructors, destructor, destroy(), size(), and empty() are already
// implemented so you can focus on the tree algorithms.

#include "bst.h"

#include <iostream>
#include <stdexcept>

// ---------------------------------------------------------------------------
// Provided boilerplate
// ---------------------------------------------------------------------------

BinarySearchTree::BinarySearchTree() : root(nullptr), count(0) {}

BinarySearchTree::~BinarySearchTree()
{
    destroy(root);
}

void BinarySearchTree::destroy(BSTNode *node)
{
    if (node == nullptr)
    {
        return;
    }

    destroy(node->left);
    destroy(node->right);
    delete node;
}

std::size_t BinarySearchTree::size() const
{
    return count;
}

bool BinarySearchTree::empty() const
{
    return root == nullptr;
}

// ---------------------------------------------------------------------------
// TODO: implement the methods below
// ---------------------------------------------------------------------------

bool BinarySearchTree::insert(int key)
{
    // TODO: insert key as a leaf using the BST ordering property.
    // Ignore duplicate keys and update count when a new key is added.
    (void)key;
    return false;
}

bool BinarySearchTree::remove(int key)
{
    // TODO: remove key using the three deletion cases described in the lab.
    // Update count when a key is removed.
    (void)key;
    return false;
}

bool BinarySearchTree::contains(int key) const
{
    // TODO: walk left when key is smaller and right when key is larger.
    (void)key;
    return false;
}

int BinarySearchTree::minimum() const
{
    // TODO: return the leftmost key. Throw std::runtime_error if empty.
    return 0;
}

int BinarySearchTree::maximum() const
{
    // TODO: return the rightmost key. Throw std::runtime_error if empty.
    return 0;
}

int BinarySearchTree::height() const
{
    // TODO: return the height of the tree in nodes.
    return 0;
}

std::vector<int> BinarySearchTree::inorder() const
{
    // TODO: left, node, right.
    return std::vector<int>();
}

std::vector<int> BinarySearchTree::preorder() const
{
    // TODO: node, left, right.
    return std::vector<int>();
}

std::vector<int> BinarySearchTree::postorder() const
{
    // TODO: left, right, node.
    return std::vector<int>();
}

bool BinarySearchTree::isValidBST() const
{
    // TODO: verify the ordering property using low and high bounds.
    return false;
}

void BinarySearchTree::printTree() const
{
    // TODO: print "Tree is empty" for an empty tree, otherwise print an
    // indented tree using the R---- and L---- markers shown in the lab.
}
