#include <iostream>
#include <vector>
#include <cassert>

// This is the same Node class from the example Splay Tree, but data is renamed to key
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

/*
class SplayTree {
public:
	SplayTree(key: int (for internal tree operations), root: Node* (for internal tree operations)) {
		// Implement a Splay Tree with basic operations: insertion, search, and splay.
		// A Splay Tree is a self-adjusting binary search tree with the additional property that recently accessed elements are quick to access again.
		// The specific assignment objective aside from simply creating a working Splay is to implement proper maintenance of the key member variable with valid usage
		// Initialize parameters
		// TODO: Implement solution
	}

	void solve() {
		// TODO: Implement solution
	}

private:
	key: int (for student to maintain); root: Node* (for internal tree operations; for student to maintain);
};
*/

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

// Demo
int main()
{
	SplayTree tree(50);

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