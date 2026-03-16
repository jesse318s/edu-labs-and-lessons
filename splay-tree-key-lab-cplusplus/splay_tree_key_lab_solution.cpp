#include <iostream>
#include <vector>
#include <cassert>

class Node
{
public:
	int key;
	Node *left;
	Node *right;
	Node *parent;

	Node(int value) : key(value), left(nullptr), right(nullptr), parent(nullptr) {}

	~Node()
	{
		delete left;
		delete right;
	}
};

class SplayTree
{
public:
	SplayTree(int key, Node *root = nullptr) : key(key), root(root)
	{
		if (root == nullptr)
		{
			insert(key);
		}
	}

	void solve()
	{
		// Example operations
		insert(30);
		insert(20);
		insert(40);
		insert(70);
		insert(60);
		insert(80);
	}

	~SplayTree()
	{
		delete root;
	}

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
				if (x->parent->left == x)
					rightRotate(x->parent);
				else
					leftRotate(x->parent);
			}
			else if (x->parent->left == x && x->parent->parent->left == x->parent)
			{
				rightRotate(x->parent->parent);
				rightRotate(x->parent);
			}
			else if (x->parent->right == x && x->parent->parent->right == x->parent)
			{
				leftRotate(x->parent->parent);
				leftRotate(x->parent);
			}
			else if (x->parent->left == x && x->parent->parent->right == x->parent)
			{
				rightRotate(x->parent);
				leftRotate(x->parent);
			}
			else
			{
				leftRotate(x->parent);
				rightRotate(x->parent);
			}
		}
		key = x->key; // Update the key to match the root
	}

	bool insert(int value)
	{
		Node *newNode = nullptr;

		if (!root)
		{
			root = new Node(value);
			key = root->key; // Update the key to match the root
			return true;
		}

		Node *current = root;
		Node *parent = nullptr;

		while (current)
		{
			parent = current;
			if (value < current->key)
				current = current->left;
			else if (value > current->key)
				current = current->right;
			else
				return false;
		}

		newNode = new Node(value);
		newNode->parent = parent;

		if (value < parent->key)
			parent->left = newNode;
		else
			parent->right = newNode;

		splay(newNode);
		return true;
	}

	Node *search(int value)
	{
		Node *current = root;

		while (current)
		{
			if (value == current->key)
			{
				splay(current);
				return current;
			}
			if (value < current->key)
				current = current->left;
			else
				current = current->right;
		}
		return nullptr;
	}

	std::vector<int> inOrder(Node *start, std::vector<int> &list)
	{
		if (start != nullptr)
		{
			inOrder(start->left, list);
			list.push_back(start->key);
			inOrder(start->right, list);
		}
		return list;
	}

	// Getter function to return the key of the root node
	int getRootKey() const
	{
		if (key)
			return key;
		return -1;
	}

private:
	int key;
	Node *root;
};

// Tests
void test_insert()
{
	SplayTree tree(0);

	tree.insert(10);
	tree.insert(20);
	tree.insert(30);
	assert(tree.search(20)->key == 20);
}

void test_search()
{
	SplayTree tree(0);

	tree.insert(10);
	tree.insert(20);
	tree.insert(30);
	assert(tree.search(30)->key == 30);
}

void test_getRootKey()
{
	SplayTree tree(50);

	tree.insert(30);
	tree.insert(20);
	tree.insert(40);
	tree.insert(70);
	tree.insert(60);
	tree.insert(80);
	assert(tree.getRootKey() == 80); // After splaying, the last inserted key should be the root
}

// Demo
int main()
{
	test_insert();
	test_search();
	test_getRootKey();

	SplayTree tree(50);

	tree.solve();

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
