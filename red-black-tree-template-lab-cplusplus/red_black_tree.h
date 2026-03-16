#ifndef RED_BLACK_TREE_H
#define RED_BLACK_TREE_H

#include <iostream>

// Color enumeration for Red-Black Tree nodes
enum Color
{
    RED,
    BLACK
};

// Red-Black Tree Node structure
template <typename T>
struct RBNode
{
    T data;
    Color color;
    RBNode<T> *left;
    RBNode<T> *right;
    RBNode<T> *parent;

    // Constructor
    RBNode(T value, Color c = RED, RBNode *l = nullptr, RBNode *r = nullptr, RBNode *p = nullptr)
        : data(value), color(c), left(l), right(r), parent(p) {}
};

// Red-Black Tree class
template <typename T>
class RedBlackTree
{
private:
    RBNode<T> *root;
    RBNode<T> *TNULL; // Sentinel node (NIL)

    // Helper functions
    void initializeNULLNode(RBNode<T> *node, RBNode<T> *parent);
    void leftRotate(RBNode<T> *x);
    void rightRotate(RBNode<T> *y);
    void insertFix(RBNode<T> *k);
    void deleteFix(RBNode<T> *x);
    void transplant(RBNode<T> *u, RBNode<T> *v);
    RBNode<T> *minimum(RBNode<T> *node);
    RBNode<T> *maximum(RBNode<T> *node);
    RBNode<T> *searchTreeHelper(RBNode<T> *node, T key);
    void printHelper(RBNode<T> *root, std::string indent, bool last);
    void deleteNodeHelper(RBNode<T> *node, T key);
    void deleteNode(RBNode<T> *node);

public:
    // Constructor and Destructor
    RedBlackTree();
    ~RedBlackTree();

    // Public methods
    void insert(T key);
    void remove(T key);
    bool search(T key);
    void printTree();
    void inorder();
    void preorder();
    void postorder();
    T getMinimum();
    T getMaximum();
    int getBlackHeight();

private:
    void inorderHelper(RBNode<T> *node);
    void preorderHelper(RBNode<T> *node);
    void postorderHelper(RBNode<T> *node);
    int blackHeightHelper(RBNode<T> *node);
    void deleteAll(RBNode<T> *node);
};

#endif // RED_BLACK_TREE_H