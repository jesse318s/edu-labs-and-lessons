"""Example usage for the Python AVL Tree Lab."""

from avl_tree import AVLTree


def show_tree(tree: AVLTree, title: str) -> None:
    """Print a labeled snapshot of the tree."""
    print(title)
    tree.print_tree()
    print(f"Height: {tree.height}")
    print(f"Inorder: {tree.inorder()}")
    print(f"Preorder: {tree.preorder()}")
    print(f"Postorder: {tree.postorder()}")
    print()


def demonstrate_insertions() -> AVLTree:
    """Insert keys that force each rotation type and return the tree."""
    tree = AVLTree()

    print("Inserting 30, 20, 10 (left-left case)")
    for key in (30, 20, 10):
        tree.insert(key)

    show_tree(tree, "Tree after left-left rotation:")

    print("Inserting 5, 15, 25, 35 (balanced additions)")
    for key in (5, 15, 25, 35):
        tree.insert(key)

    show_tree(tree, "Tree after more insertions:")
    return tree


def demonstrate_search_and_deletion(tree: AVLTree) -> None:
    """Search for keys and remove one that has two children."""
    print(f"Contains 25: {tree.search(25)}")
    print(f"Contains 99: {tree.search(99)}")
    print(f"Minimum: {tree.minimum()}")
    print(f"Maximum: {tree.maximum()}")
    print()

    print("Deleting 20 (a node with two children)")
    tree.delete(20)

    show_tree(tree, "Tree after deleting 20:")
    print(f"Tree is a valid AVL tree: {tree.is_valid_avl()}")


def main() -> None:
    """Run the demo."""
    tree = demonstrate_insertions()
    demonstrate_search_and_deletion(tree)


if __name__ == "__main__":
    main()
