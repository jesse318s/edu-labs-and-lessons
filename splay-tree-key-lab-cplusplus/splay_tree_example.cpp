#include <iostream>
#include <vector>

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node *parent; // Added parent pointer

    Node(int value) : data(value), left(nullptr), right(nullptr), parent(nullptr) {}

    ~Node()
    {
        delete left;
        delete right;
    }
};

class SplayTree
{
public:
    Node *root;

    SplayTree() : root(nullptr) {}

    ~SplayTree()
    {
        delete root;
    }

    // Core splay operations
    void rightRotate(Node *x)
    {
        Node *y = x->left;
        if (y)
        {
            x->left = y->right;
            if (y->right)
                y->right->parent = x;
            y->parent = x->parent;
        }

        if (!x->parent)
            root = y;
        else if (x == x->parent->left)
            x->parent->left = y;
        else
            x->parent->right = y;

        if (y)
        {
            y->right = x;
            x->parent = y;
        }
    }

    void leftRotate(Node *x)
    {
        Node *y = x->right;
        if (y)
        {
            x->right = y->left;
            if (y->left)
                y->left->parent = x;
            y->parent = x->parent;
        }

        if (!x->parent)
            root = y;
        else if (x == x->parent->left)
            x->parent->left = y;
        else
            x->parent->right = y;

        if (y)
        {
            y->left = x;
            x->parent = y;
        }
    }

    void splay(Node *x)
    {
        while (x && x->parent)
        {
            if (!x->parent->parent)
            {
                // Zig step
                if (x->parent->left == x)
                    rightRotate(x->parent);
                else
                    leftRotate(x->parent);
            }
            else if (x->parent->left == x && x->parent->parent->left == x->parent)
            {
                // Zig-zig step
                rightRotate(x->parent->parent);
                rightRotate(x->parent);
            }
            else if (x->parent->right == x && x->parent->parent->right == x->parent)
            {
                // Zig-zig step
                leftRotate(x->parent->parent);
                leftRotate(x->parent);
            }
            else if (x->parent->left == x && x->parent->parent->right == x->parent)
            {
                // Zig-zag step
                rightRotate(x->parent);
                leftRotate(x->parent);
            }
            else
            {
                // Zig-zag step
                leftRotate(x->parent);
                rightRotate(x->parent);
            }
        }
    }

    bool insert(int value)
    {
        Node *newNode = nullptr;

        // If tree is empty
        if (!root)
        {
            root = new Node(value);
            return true;
        }

        Node *current = root;
        Node *parent = nullptr;

        // Find insertion point
        while (current)
        {
            parent = current;
            if (value < current->data)
                current = current->left;
            else if (value > current->data)
                current = current->right;
            else
                return false; // Duplicate value
        }

        // Create new node
        newNode = new Node(value);
        newNode->parent = parent;

        // Insert node
        if (value < parent->data)
            parent->left = newNode;
        else
            parent->right = newNode;

        // Splay the newly inserted node
        splay(newNode);
        return true;
    }

    Node *search(int value)
    {
        Node *current = root;

        while (current)
        {
            if (value == current->data)
            {
                splay(current);
                return current;
            }
            if (value < current->data)
                current = current->left;
            else
                current = current->right;
        }
        return nullptr;
    }

    // Keep existing helper functions from BST
    std::vector<int> inOrder(Node *start, std::vector<int> &list)
    {
        if (start != nullptr)
        {
            inOrder(start->left, list);
            list.push_back(start->data);
            inOrder(start->right, list);
        }
        return list;
    }
};

int main()
{
    SplayTree tree;

    // Insert some values
    tree.insert(50);
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(70);
    tree.insert(60);
    tree.insert(80);

    std::vector<int> inOrderList;

    tree.inOrder(tree.search(80), inOrderList);
    std::cout << "In-order traversal after insertions: ";

    for (int val : inOrderList)
    {
        std::cout << val << " ";
    }

    std::cout << std::endl;

    return 0;
}