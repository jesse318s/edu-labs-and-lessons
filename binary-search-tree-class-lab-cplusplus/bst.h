#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <cstddef>
#include <string>
#include <vector>

// A single node in a binary search tree.
struct BSTNode
{
    int key;
    BSTNode *left;
    BSTNode *right;

    explicit BSTNode(int value) : key(value), left(nullptr), right(nullptr) {}
};

// A basic (unbalanced) binary search tree of int keys.
//
// The tree stores unique keys. Duplicate keys are ignored. Height is measured
// in nodes: an empty tree has height 0, and a leaf has height 1.
//
// Students implement this class in bst_starter.cpp. A completed reference
// implementation is provided in bst_solution.cpp.
class BinarySearchTree
{
public:
    BinarySearchTree();
    ~BinarySearchTree();

    // The tree owns raw pointers, so copying is disabled to avoid double frees.
    BinarySearchTree(const BinarySearchTree &other) = delete;
    BinarySearchTree &operator=(const BinarySearchTree &other) = delete;

    // Insert a key. Returns true when the key was added, or false when the key
    // already exists.
    bool insert(int key);

    // Remove a key. Returns true when the key was removed, or false when the
    // key was not present.
    bool remove(int key);

    // Return true when the key is present.
    bool contains(int key) const;

    // Return the smallest or largest key. Throws std::runtime_error when the
    // tree is empty.
    int minimum() const;
    int maximum() const;

    std::size_t size() const;
    bool empty() const;

    // Return the height of the tree (0 for an empty tree).
    int height() const;

    // Return keys in the requested traversal order.
    std::vector<int> inorder() const;
    std::vector<int> preorder() const;
    std::vector<int> postorder() const;

    // Return true when every node satisfies the binary search tree ordering
    // rules (left subtree < node < right subtree).
    bool isValidBST() const;

    // Print an indented representation of the tree.
    void printTree() const;

private:
    BSTNode *root;
    std::size_t count;

    static void destroy(BSTNode *node);
    static int nodeHeight(const BSTNode *node);
    static const BSTNode *findMin(const BSTNode *node);
    static const BSTNode *findMax(const BSTNode *node);
    static void inorderHelper(const BSTNode *node, std::vector<int> &out);
    static void preorderHelper(const BSTNode *node, std::vector<int> &out);
    static void postorderHelper(const BSTNode *node, std::vector<int> &out);
    static bool validateHelper(const BSTNode *node, const int *low, const int *high);
    static void printHelper(const BSTNode *node, const std::string &indent, bool isRight);

    BSTNode *insertHelper(BSTNode *node, int key, bool &inserted);
    BSTNode *removeHelper(BSTNode *node, int key, bool &removed);
};

#endif // BINARY_SEARCH_TREE_H
