"""AVL Tree implementation for the Python AVL Tree Lab.

An AVL tree is a self-balancing binary search tree. After every insertion or
deletion, the tree checks the balance factor of each affected node and uses
rotations to restore the AVL property.

Height convention used in this file:
    - The height of an empty tree is 0.
    - The height of a leaf is 1.
    - Balance factor = height(left subtree) - height(right subtree).
"""

from typing import Any, Iterator, List, Optional


class AVLNode:
    """A single node in an AVL tree.

    Parameters:
        key: The value stored in the node. Keys must be mutually comparable
            and must not be None.
    """

    __slots__ = ("key", "left", "right", "height")

    def __init__(self, key: Any) -> None:
        self.key = key
        self.left: Optional["AVLNode"] = None
        self.right: Optional["AVLNode"] = None
        self.height = 1

    def __repr__(self) -> str:
        return f"AVLNode(key={self.key!r}, height={self.height})"


class AVLTree:
    """A self-balancing binary search tree.

    The tree stores unique keys. Inserting a key that already exists leaves the
    tree unchanged and reports that no new key was added.
    """

    def __init__(self) -> None:
        self._root: Optional[AVLNode] = None
        self._size = 0

    # ------------------------------------------------------------------
    # Basic container protocol
    # ------------------------------------------------------------------

    def __len__(self) -> int:
        """Return the number of keys stored in the tree."""
        return self._size

    def __contains__(self, key: Any) -> bool:
        """Support the ``key in tree`` syntax."""
        return self.search(key)

    def __iter__(self) -> Iterator[Any]:
        """Iterate over keys in ascending order."""
        return iter(self.inorder())

    def __repr__(self) -> str:
        return f"AVLTree({self.inorder()})"

    @property
    def root(self) -> Optional[AVLNode]:
        """Return the root node, or None when the tree is empty."""
        return self._root

    @property
    def height(self) -> int:
        """Return the height of the tree (0 for an empty tree)."""
        return self._node_height(self._root)

    def is_empty(self) -> bool:
        """Return True when the tree contains no keys."""
        return self._root is None

    # ------------------------------------------------------------------
    # Height and rotation helpers
    # ------------------------------------------------------------------

    @staticmethod
    def _node_height(node: Optional[AVLNode]) -> int:
        """Return a node's stored height, treating None as height 0."""
        if node is None:
            return 0

        return node.height

    def _update_height(self, node: AVLNode) -> None:
        """Recompute a node's height from its children."""
        node.height = 1 + max(self._node_height(node.left), self._node_height(node.right))

    def _balance_factor(self, node: Optional[AVLNode]) -> int:
        """Return the balance factor of a node."""
        if node is None:
            return 0

        return self._node_height(node.left) - self._node_height(node.right)

    def _rotate_left(self, node: AVLNode) -> AVLNode:
        """Rotate the subtree rooted at node to the left and return its new root."""
        pivot = node.right

        if pivot is None:
            return node

        middle_subtree = pivot.left
        pivot.left = node
        node.right = middle_subtree

        # Update the lower node first because its height depends on its children.
        self._update_height(node)
        self._update_height(pivot)

        return pivot

    def _rotate_right(self, node: AVLNode) -> AVLNode:
        """Rotate the subtree rooted at node to the right and return its new root."""
        pivot = node.left

        if pivot is None:
            return node

        middle_subtree = pivot.right
        pivot.right = node
        node.left = middle_subtree

        # Update the lower node first because its height depends on its children.
        self._update_height(node)
        self._update_height(pivot)

        return pivot

    def _rebalance(self, node: AVLNode) -> AVLNode:
        """Restore the AVL property for one node and return the new subtree root."""
        self._update_height(node)
        balance = self._balance_factor(node)

        # Left-heavy subtree.
        if balance > 1:
            # Left-right case: the left child is right-heavy, so rotate it left.
            if self._balance_factor(node.left) < 0:
                node.left = self._rotate_left(node.left)

            return self._rotate_right(node)

        # Right-heavy subtree.
        if balance < -1:
            # Right-left case: the right child is left-heavy, so rotate it right.
            if self._balance_factor(node.right) > 0:
                node.right = self._rotate_right(node.right)

            return self._rotate_left(node)

        return node

    # ------------------------------------------------------------------
    # Insertion
    # ------------------------------------------------------------------

    def insert(self, key: Any) -> bool:
        """Insert a key into the tree.

        Parameters:
            key: The value to insert. It must be comparable with existing keys.

        Returns:
            True if the key was inserted, or False if it already existed.
        """
        self._root, inserted = self._insert(self._root, key)

        if inserted:
            self._size += 1

        return inserted

    def _insert(self, node: Optional[AVLNode], key: Any) -> tuple:
        """Recursively insert a key and return (new_subtree, inserted)."""
        if node is None:
            return AVLNode(key), True

        if key < node.key:
            node.left, inserted = self._insert(node.left, key)
        elif key > node.key:
            node.right, inserted = self._insert(node.right, key)
        else:
            # Duplicate keys are ignored.
            return node, False

        # The subtree changed, so its height and balance may have changed.
        return self._rebalance(node), inserted

    # ------------------------------------------------------------------
    # Deletion
    # ------------------------------------------------------------------

    def delete(self, key: Any) -> bool:
        """Remove a key from the tree.

        Parameters:
            key: The value to remove.

        Returns:
            True if the key was removed, or False if it was not present.
        """
        self._root, deleted = self._delete(self._root, key)

        if deleted:
            self._size -= 1

        return deleted

    def _delete(self, node: Optional[AVLNode], key: Any) -> tuple:
        """Recursively delete a key and return (new_subtree, deleted)."""
        if node is None:
            return None, False

        if key < node.key:
            node.left, deleted = self._delete(node.left, key)
        elif key > node.key:
            node.right, deleted = self._delete(node.right, key)
        else:
            deleted = True

            # Case 1 and case 2: the node has at most one child.
            if node.left is None:
                return node.right, True

            if node.right is None:
                return node.left, True

            # Case 3: the node has two children. Replace its key with the
            # inorder successor, then remove the successor from the right subtree.
            successor = self._minimum_node(node.right)
            node.key = successor.key
            node.right, _ = self._delete(node.right, successor.key)

        # The subtree changed, so rebalance on the way back up the recursion.
        return self._rebalance(node), deleted

    # ------------------------------------------------------------------
    # Search and min/max operations
    # ------------------------------------------------------------------

    def search(self, key: Any) -> bool:
        """Return True when the key is present in the tree."""
        current = self._root

        while current is not None:
            if key == current.key:
                return True

            if key < current.key:
                current = current.left
            else:
                current = current.right

        return False

    def _minimum_node(self, node: AVLNode) -> AVLNode:
        """Return the leftmost node in a non-empty subtree."""
        current = node

        while current.left is not None:
            current = current.left

        return current

    def _maximum_node(self, node: AVLNode) -> AVLNode:
        """Return the rightmost node in a non-empty subtree."""
        current = node

        while current.right is not None:
            current = current.right

        return current

    def minimum(self) -> Any:
        """Return the smallest key.

        Raises:
            ValueError: If the tree is empty.
        """
        if self._root is None:
            raise ValueError("Cannot find the minimum of an empty tree")

        return self._minimum_node(self._root).key

    def maximum(self) -> Any:
        """Return the largest key.

        Raises:
            ValueError: If the tree is empty.
        """
        if self._root is None:
            raise ValueError("Cannot find the maximum of an empty tree")

        return self._maximum_node(self._root).key

    # ------------------------------------------------------------------
    # Traversals
    # ------------------------------------------------------------------

    def inorder(self) -> List[Any]:
        """Return keys in ascending order (left, node, right)."""
        result: List[Any] = []

        def visit(node: Optional[AVLNode]) -> None:
            if node is None:
                return

            visit(node.left)
            result.append(node.key)
            visit(node.right)

        visit(self._root)

        return result

    def preorder(self) -> List[Any]:
        """Return keys in preorder (node, left, right)."""
        result: List[Any] = []

        def visit(node: Optional[AVLNode]) -> None:
            if node is None:
                return

            result.append(node.key)
            visit(node.left)
            visit(node.right)

        visit(self._root)

        return result

    def postorder(self) -> List[Any]:
        """Return keys in postorder (left, right, node)."""
        result: List[Any] = []

        def visit(node: Optional[AVLNode]) -> None:
            if node is None:
                return

            visit(node.left)
            visit(node.right)
            result.append(node.key)

        visit(self._root)

        return result

    def level_order(self) -> List[Any]:
        """Return keys by level from top to bottom, left to right."""
        if self._root is None:
            return []

        result: List[Any] = []
        queue: List[AVLNode] = [self._root]

        while queue:
            node = queue.pop(0)
            result.append(node.key)

            if node.left is not None:
                queue.append(node.left)

            if node.right is not None:
                queue.append(node.right)

        return result

    # ------------------------------------------------------------------
    # Validation and display
    # ------------------------------------------------------------------

    def is_valid_avl(self) -> bool:
        """Return True when the tree satisfies all AVL and BST invariants.

        The check verifies BST ordering, stored node heights, and balance
        factors. It is useful in tests and while debugging rotations.
        """
        def validate(node: Optional[AVLNode], low: Any, high: Any) -> tuple:
            if node is None:
                return 0, True

            # Enforce strict BST ordering. Duplicate keys are not allowed.
            if low is not None and node.key <= low:
                return 0, False

            if high is not None and node.key >= high:
                return 0, False

            left_height, left_valid = validate(node.left, low, node.key)
            right_height, right_valid = validate(node.right, node.key, high)

            if not left_valid or not right_valid:
                return 0, False

            if abs(left_height - right_height) > 1:
                return 0, False

            expected_height = 1 + max(left_height, right_height)

            if node.height != expected_height:
                return 0, False

            return node.height, True

        return validate(self._root, None, None)[1]

    def print_tree(self) -> None:
        """Print an indented representation of the tree.

        Each line shows the key, its stored height (h), and its balance
        factor (bf). Left children are marked with L---- and right children
        with R----.
        """
        if self._root is None:
            print("Tree is empty")
            return

        self._print_helper(self._root, "", True)

    def _print_helper(self, node: Optional[AVLNode], indent: str, is_right: bool) -> None:
        """Recursively print one subtree with indentation."""
        if node is None:
            return

        print(indent, end="")

        if is_right:
            print("R----", end="")
            child_indent = indent + "     "
        else:
            print("L----", end="")
            child_indent = indent + "|    "

        balance = self._balance_factor(node)
        print(f"{node.key} (h={node.height}, bf={balance})")
        self._print_helper(node.left, child_indent, False)
        self._print_helper(node.right, child_indent, True)
