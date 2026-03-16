#ifndef RED_BLACK_TREE_CPP
#define RED_BLACK_TREE_CPP

#include "red_black_tree.h"
#include <iostream>

// Initialize the TNULL (sentinel) node
template <typename T>
void RedBlackTree<T>::initializeNULLNode(RBNode<T> *node, RBNode<T> *parent)
{
    node->data = T();
    node->parent = parent;
    node->left = nullptr;
    node->right = nullptr;
    node->color = BLACK;
}

// Constructor for Red-Black Tree
template <typename T>
RedBlackTree<T>::RedBlackTree()
{
    TNULL = new RBNode<T>(T());
    TNULL->color = BLACK;
    TNULL->left = nullptr;
    TNULL->right = nullptr;
    root = TNULL;
}

// Destructor for Red-Black Tree
template <typename T>
RedBlackTree<T>::~RedBlackTree()
{
    deleteAll(root);
    delete TNULL;
}

// Helper method to delete all nodes in the tree
template <typename T>
void RedBlackTree<T>::deleteAll(RBNode<T> *node)
{
    if (node != TNULL)
    {
        deleteAll(node->left);
        deleteAll(node->right);
        delete node;
    }
}

// Left rotation on given node x
template <typename T>
void RedBlackTree<T>::leftRotate(RBNode<T> *x)
{
    RBNode<T> *y = x->right;
    x->right = y->left;

    if (y->left != TNULL)
    {
        y->left->parent = x;
    }

    y->parent = x->parent;

    if (x->parent == nullptr)
    {
        this->root = y;
    }
    else if (x == x->parent->left)
    {
        x->parent->left = y;
    }
    else
    {
        x->parent->right = y;
    }

    y->left = x;
    x->parent = y;
}

// Right rotation on given node x
template <typename T>
void RedBlackTree<T>::rightRotate(RBNode<T> *y)
{
    RBNode<T> *x = y->left;
    y->left = x->right;

    if (x->right != TNULL)
    {
        x->right->parent = y;
    }

    x->parent = y->parent;

    if (y->parent == nullptr)
    {
        this->root = x;
    }
    else if (y == y->parent->right)
    {
        y->parent->right = x;
    }
    else
    {
        y->parent->left = x;
    }

    x->right = y;
    y->parent = x;
}

// Search the tree for a key
template <typename T>
RBNode<T> *RedBlackTree<T>::searchTreeHelper(RBNode<T> *node, T key)
{
    if (node == TNULL || key == node->data)
    {
        return node;
    }

    if (key < node->data)
    {
        return searchTreeHelper(node->left, key);
    }

    return searchTreeHelper(node->right, key);
}

// Public method to search for a key in the tree
template <typename T>
bool RedBlackTree<T>::search(T key)
{
    return searchTreeHelper(this->root, key) != TNULL;
}

// Fix the Red-Black Tree properties after insertion
template <typename T>
void RedBlackTree<T>::insertFix(RBNode<T> *k)
{
    RBNode<T> *u;

    while (k->parent != nullptr && k->parent->color == RED)
    {
        if (k->parent == k->parent->parent->right)
        {
            u = k->parent->parent->left;

            // Case 1: Uncle is RED
            if (u->color == RED)
            {
                u->color = BLACK;
                k->parent->color = BLACK;
                k->parent->parent->color = RED;
                k = k->parent->parent;
            }
            else
            {
                // Case 2: Uncle is BLACK and k is left child
                if (k == k->parent->left)
                {
                    k = k->parent;
                    rightRotate(k);
                }

                // Case 3: Uncle is BLACK and k is right child
                k->parent->color = BLACK;
                k->parent->parent->color = RED;
                leftRotate(k->parent->parent);
            }
        }
        else
        {
            u = k->parent->parent->right;

            // Case 1: Uncle is RED
            if (u->color == RED)
            {
                u->color = BLACK;
                k->parent->color = BLACK;
                k->parent->parent->color = RED;
                k = k->parent->parent;
            }
            else
            {
                // Case 2: Uncle is BLACK and k is right child
                if (k == k->parent->right)
                {
                    k = k->parent;
                    leftRotate(k);
                }

                // Case 3: Uncle is BLACK and k is left child
                k->parent->color = BLACK;
                k->parent->parent->color = RED;
                rightRotate(k->parent->parent);
            }
        }

        if (k == root)
        {
            break;
        }
    }

    // Always ensure the root is BLACK
    root->color = BLACK;
}

// Insert a new key into the tree
template <typename T>
void RedBlackTree<T>::insert(T key)
{
    RBNode<T> *node = new RBNode<T>(key);
    node->left = TNULL;
    node->right = TNULL;

    RBNode<T> *y = nullptr;
    RBNode<T> *x = this->root;

    // Find the position to insert the new node
    while (x != TNULL)
    {
        y = x;
        if (node->data < x->data)
        {
            x = x->left;
        }
        else
        {
            x = x->right;
        }
    }

    // Set the parent of the new node
    node->parent = y;

    // If tree was empty, set node as root
    if (y == nullptr)
    {
        root = node;
        node->color = BLACK; // Root must be black
        return;
    }
    else if (node->data < y->data)
    {
        y->left = node;
    }
    else
    {
        y->right = node;
    }

    // If new node is a root node, return
    if (node->parent == nullptr)
    {
        node->color = BLACK;
        return;
    }

    // If grandparent is null, simply return
    if (node->parent->parent == nullptr)
    {
        return;
    }

    // Fix Red-Black properties
    insertFix(node);
}

// Find the node with minimum key value
template <typename T>
RBNode<T> *RedBlackTree<T>::minimum(RBNode<T> *node)
{
    while (node->left != TNULL)
    {
        node = node->left;
    }
    return node;
}

// Find the node with maximum key value
template <typename T>
RBNode<T> *RedBlackTree<T>::maximum(RBNode<T> *node)
{
    while (node->right != TNULL)
    {
        node = node->right;
    }
    return node;
}

// Get minimum value in the tree
template <typename T>
T RedBlackTree<T>::getMinimum()
{
    if (root == TNULL)
    {
        throw std::runtime_error("Tree is empty");
    }
    RBNode<T> *min = minimum(root);
    return min->data;
}

// Get maximum value in the tree
template <typename T>
T RedBlackTree<T>::getMaximum()
{
    if (root == TNULL)
    {
        throw std::runtime_error("Tree is empty");
    }
    RBNode<T> *max = maximum(root);
    return max->data;
}

// Replace one subtree as a child of its parent with another subtree
template <typename T>
void RedBlackTree<T>::transplant(RBNode<T> *u, RBNode<T> *v)
{
    if (u->parent == nullptr)
    {
        root = v;
    }
    else if (u == u->parent->left)
    {
        u->parent->left = v;
    }
    else
    {
        u->parent->right = v;
    }
    v->parent = u->parent;
}

// Helper function for deletion
template <typename T>
void RedBlackTree<T>::deleteNodeHelper(RBNode<T> *node, T key)
{
    RBNode<T> *z = TNULL;
    RBNode<T> *x, *y;

    // Find the node to be deleted
    while (node != TNULL)
    {
        if (node->data == key)
        {
            z = node;
        }

        if (node->data <= key)
        {
            node = node->right;
        }
        else
        {
            node = node->left;
        }
    }

    if (z == TNULL)
    {
        std::cout << "Key not found in the tree" << std::endl;
        return;
    }

    y = z;
    Color y_original_color = y->color;

    if (z->left == TNULL)
    {
        x = z->right;
        transplant(z, z->right);
    }
    else if (z->right == TNULL)
    {
        x = z->left;
        transplant(z, z->left);
    }
    else
    {
        y = minimum(z->right);
        y_original_color = y->color;
        x = y->right;

        if (y->parent == z)
        {
            x->parent = y;
        }
        else
        {
            transplant(y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }

        transplant(z, y);
        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;
    }
    delete z;

    if (y_original_color == BLACK)
    {
        deleteFix(x);
    }
}

// Fix the Red-Black Tree properties after deletion
template <typename T>
void RedBlackTree<T>::deleteFix(RBNode<T> *x)
{
    RBNode<T> *s;
    while (x != root && x->color == BLACK)
    {
        if (x == x->parent->left)
        {
            s = x->parent->right;
            if (s->color == RED)
            {
                // Case 1: x's sibling s is RED
                s->color = BLACK;
                x->parent->color = RED;
                leftRotate(x->parent);
                s = x->parent->right;
            }

            if (s->left->color == BLACK && s->right->color == BLACK)
            {
                // Case 2: x's sibling s is BLACK, and both of s's children are BLACK
                s->color = RED;
                x = x->parent;
            }
            else
            {
                if (s->right->color == BLACK)
                {
                    // Case 3: x's sibling s is BLACK, s's left child is RED, and s's right child is BLACK
                    s->left->color = BLACK;
                    s->color = RED;
                    rightRotate(s);
                    s = x->parent->right;
                }

                // Case 4: x's sibling s is BLACK, and s's right child is RED
                s->color = x->parent->color;
                x->parent->color = BLACK;
                s->right->color = BLACK;
                leftRotate(x->parent);
                x = root;
            }
        }
        else
        {
            s = x->parent->left;
            if (s->color == RED)
            {
                // Case 1: x's sibling s is RED
                s->color = BLACK;
                x->parent->color = RED;
                rightRotate(x->parent);
                s = x->parent->left;
            }

            if (s->right->color == BLACK && s->left->color == BLACK)
            {
                // Case 2: x's sibling s is BLACK, and both of s's children are BLACK
                s->color = RED;
                x = x->parent;
            }
            else
            {
                if (s->left->color == BLACK)
                {
                    // Case 3: x's sibling s is BLACK, s's right child is RED, and s's left child is BLACK
                    s->right->color = BLACK;
                    s->color = RED;
                    leftRotate(s);
                    s = x->parent->left;
                }

                // Case 4: x's sibling s is BLACK, and s's left child is RED
                s->color = x->parent->color;
                x->parent->color = BLACK;
                s->left->color = BLACK;
                rightRotate(x->parent);
                x = root;
            }
        }
    }
    x->color = BLACK;
}

// Public method to delete a node with a given key
template <typename T>
void RedBlackTree<T>::remove(T key)
{
    deleteNodeHelper(this->root, key);
}

// Helper function for inorder traversal
template <typename T>
void RedBlackTree<T>::inorderHelper(RBNode<T> *node)
{
    if (node != TNULL)
    {
        inorderHelper(node->left);
        std::cout << node->data << " ";
        inorderHelper(node->right);
    }
}

// Inorder traversal
template <typename T>
void RedBlackTree<T>::inorder()
{
    inorderHelper(this->root);
    std::cout << std::endl;
}

// Helper function for preorder traversal
template <typename T>
void RedBlackTree<T>::preorderHelper(RBNode<T> *node)
{
    if (node != TNULL)
    {
        std::cout << node->data << " ";
        preorderHelper(node->left);
        preorderHelper(node->right);
    }
}

// Preorder traversal
template <typename T>
void RedBlackTree<T>::preorder()
{
    preorderHelper(this->root);
    std::cout << std::endl;
}

// Helper function for postorder traversal
template <typename T>
void RedBlackTree<T>::postorderHelper(RBNode<T> *node)
{
    if (node != TNULL)
    {
        postorderHelper(node->left);
        postorderHelper(node->right);
        std::cout << node->data << " ";
    }
}

// Postorder traversal
template <typename T>
void RedBlackTree<T>::postorder()
{
    postorderHelper(this->root);
    std::cout << std::endl;
}

// Helper function to print the tree structure
template <typename T>
void RedBlackTree<T>::printHelper(RBNode<T> *root, std::string indent, bool last)
{
    if (root != TNULL)
    {
        std::cout << indent;
        if (last)
        {
            std::cout << "R----";
            indent += "     ";
        }
        else
        {
            std::cout << "L----";
            indent += "|    ";
        }

        std::string color = root->color == RED ? "RED" : "BLACK";
        std::cout << root->data << "(" << color << ")" << std::endl;
        printHelper(root->left, indent, false);
        printHelper(root->right, indent, true);
    }
}

// Print the tree structure
template <typename T>
void RedBlackTree<T>::printTree()
{
    if (root == TNULL)
    {
        std::cout << "Tree is empty" << std::endl;
        return;
    }
    printHelper(this->root, "", true);
}

// Calculate black height (number of black nodes from root to leaves)
template <typename T>
int RedBlackTree<T>::blackHeightHelper(RBNode<T> *node)
{
    if (node == TNULL)
    {
        return 1; // NIL nodes are BLACK
    }

    int leftHeight = blackHeightHelper(node->left);
    int rightHeight = blackHeightHelper(node->right);

    // Validate property 5 (all paths have same number of black nodes)
    if (leftHeight != rightHeight)
    {
        std::cout << "Red-Black Tree property violation: Unbalanced black nodes" << std::endl;
        return -1;
    }

    // Add current node to black height if it's black
    return (node->color == BLACK) ? leftHeight + 1 : leftHeight;
}

// Get black height of the tree
template <typename T>
int RedBlackTree<T>::getBlackHeight()
{
    return blackHeightHelper(root);
}

#endif // RED_BLACK_TREE_CPP