// Completed reference implementation for the Binary Search Tree Lab.
//
// Students should attempt bst_starter.cpp first. This file is the solution and
// is linked by the "solution" target in the Makefile.

#include "bst.h"

#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <string>

// ---------------------------------------------------------------------------
// Construction and destruction
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

// ---------------------------------------------------------------------------
// Basic container information
// ---------------------------------------------------------------------------

std::size_t BinarySearchTree::size() const
{
    return count;
}

bool BinarySearchTree::empty() const
{
    return root == nullptr;
}

int BinarySearchTree::nodeHeight(const BSTNode *node)
{
    if (node == nullptr)
    {
        return 0;
    }

    return 1 + std::max(nodeHeight(node->left), nodeHeight(node->right));
}

int BinarySearchTree::height() const
{
    return nodeHeight(root);
}

// ---------------------------------------------------------------------------
// Search
// ---------------------------------------------------------------------------

bool BinarySearchTree::contains(int key) const
{
    const BSTNode *current = root;

    while (current != nullptr)
    {
        if (key < current->key)
        {
            current = current->left;
        }
        else if (key > current->key)
        {
            current = current->right;
        }
        else
        {
            return true;
        }
    }

    return false;
}

// ---------------------------------------------------------------------------
// Insertion
// ---------------------------------------------------------------------------

bool BinarySearchTree::insert(int key)
{
    bool inserted = false;
    root = insertHelper(root, key, inserted);

    if (inserted)
    {
        ++count;
    }

    return inserted;
}

BSTNode *BinarySearchTree::insertHelper(BSTNode *node, int key, bool &inserted)
{
    if (node == nullptr)
    {
        inserted = true;
        return new BSTNode(key);
    }

    if (key < node->key)
    {
        node->left = insertHelper(node->left, key, inserted);
    }
    else if (key > node->key)
    {
        node->right = insertHelper(node->right, key, inserted);
    }
    // Equal keys are ignored.

    return node;
}

// ---------------------------------------------------------------------------
// Deletion
// ---------------------------------------------------------------------------

bool BinarySearchTree::remove(int key)
{
    bool removed = false;
    root = removeHelper(root, key, removed);

    if (removed)
    {
        --count;
    }

    return removed;
}

BSTNode *BinarySearchTree::removeHelper(BSTNode *node, int key, bool &removed)
{
    if (node == nullptr)
    {
        return nullptr;
    }

    if (key < node->key)
    {
        node->left = removeHelper(node->left, key, removed);
        return node;
    }

    if (key > node->key)
    {
        node->right = removeHelper(node->right, key, removed);
        return node;
    }

    removed = true;

    // Case 1 and case 2: the node has at most one child.
    if (node->left == nullptr)
    {
        BSTNode *right = node->right;
        delete node;
        return right;
    }

    if (node->right == nullptr)
    {
        BSTNode *left = node->left;
        delete node;
        return left;
    }

    // Case 3: the node has two children. Copy the inorder successor's key into
    // this node, then delete the successor from the right subtree.
    const BSTNode *successor = findMin(node->right);
    node->key = successor->key;
    node->right = removeHelper(node->right, successor->key, removed);

    return node;
}

// ---------------------------------------------------------------------------
// Minimum and maximum
// ---------------------------------------------------------------------------

const BSTNode *BinarySearchTree::findMin(const BSTNode *node)
{
    while (node->left != nullptr)
    {
        node = node->left;
    }

    return node;
}

const BSTNode *BinarySearchTree::findMax(const BSTNode *node)
{
    while (node->right != nullptr)
    {
        node = node->right;
    }

    return node;
}

int BinarySearchTree::minimum() const
{
    if (root == nullptr)
    {
        throw std::runtime_error("Cannot find the minimum of an empty tree");
    }

    return findMin(root)->key;
}

int BinarySearchTree::maximum() const
{
    if (root == nullptr)
    {
        throw std::runtime_error("Cannot find the maximum of an empty tree");
    }

    return findMax(root)->key;
}

// ---------------------------------------------------------------------------
// Traversals
// ---------------------------------------------------------------------------

void BinarySearchTree::inorderHelper(const BSTNode *node, std::vector<int> &out)
{
    if (node == nullptr)
    {
        return;
    }

    inorderHelper(node->left, out);
    out.push_back(node->key);
    inorderHelper(node->right, out);
}

std::vector<int> BinarySearchTree::inorder() const
{
    std::vector<int> result;
    inorderHelper(root, result);
    return result;
}

void BinarySearchTree::preorderHelper(const BSTNode *node, std::vector<int> &out)
{
    if (node == nullptr)
    {
        return;
    }

    out.push_back(node->key);
    preorderHelper(node->left, out);
    preorderHelper(node->right, out);
}

std::vector<int> BinarySearchTree::preorder() const
{
    std::vector<int> result;
    preorderHelper(root, result);
    return result;
}

void BinarySearchTree::postorderHelper(const BSTNode *node, std::vector<int> &out)
{
    if (node == nullptr)
    {
        return;
    }

    postorderHelper(node->left, out);
    postorderHelper(node->right, out);
    out.push_back(node->key);
}

std::vector<int> BinarySearchTree::postorder() const
{
    std::vector<int> result;
    postorderHelper(root, result);
    return result;
}

// ---------------------------------------------------------------------------
// Validation and display
// ---------------------------------------------------------------------------

bool BinarySearchTree::validateHelper(const BSTNode *node, const int *low, const int *high)
{
    if (node == nullptr)
    {
        return true;
    }

    // Enforce strict ordering. Duplicate keys are not allowed.
    if (low != nullptr && !(*low < node->key))
    {
        return false;
    }

    if (high != nullptr && !(node->key < *high))
    {
        return false;
    }

    return validateHelper(node->left, low, &node->key) &&
           validateHelper(node->right, &node->key, high);
}

bool BinarySearchTree::isValidBST() const
{
    return validateHelper(root, nullptr, nullptr);
}

void BinarySearchTree::printHelper(const BSTNode *node, const std::string &indent, bool isRight)
{
    if (node == nullptr)
    {
        return;
    }

    std::cout << indent;

    std::string childIndent;

    if (isRight)
    {
        std::cout << "R----";
        childIndent = indent + "     ";
    }
    else
    {
        std::cout << "L----";
        childIndent = indent + "|    ";
    }

    std::cout << node->key << std::endl;

    printHelper(node->left, childIndent, false);
    printHelper(node->right, childIndent, true);
}

void BinarySearchTree::printTree() const
{
    if (root == nullptr)
    {
        std::cout << "Tree is empty" << std::endl;
        return;
    }

    printHelper(root, "", true);
}
