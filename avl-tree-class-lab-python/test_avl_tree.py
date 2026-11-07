"""Unit tests for the Python AVL Tree Lab."""

import sys
import unittest
from io import StringIO
from pathlib import Path
from unittest.mock import patch

project_root = Path(__file__).parent
sys.path.insert(0, str(project_root))

from avl_tree import AVLTree


class TestAVLTreeBasics(unittest.TestCase):
    def test_empty_tree(self):
        tree = AVLTree()

        self.assertTrue(tree.is_empty())
        self.assertEqual(len(tree), 0)
        self.assertEqual(tree.height, 0)
        self.assertEqual(tree.inorder(), [])
        self.assertTrue(tree.is_valid_avl())

    def test_insert_and_search(self):
        tree = AVLTree()

        self.assertTrue(tree.insert(10))
        self.assertTrue(tree.insert(5))
        self.assertTrue(tree.insert(15))

        self.assertTrue(tree.search(10))
        self.assertTrue(tree.search(5))
        self.assertTrue(tree.search(15))
        self.assertFalse(tree.search(99))
        self.assertIn(15, tree)
        self.assertNotIn(99, tree)
        self.assertEqual(len(tree), 3)

    def test_duplicate_insert_is_ignored(self):
        tree = AVLTree()
        tree.insert(10)

        self.assertFalse(tree.insert(10))
        self.assertEqual(len(tree), 1)
        self.assertEqual(tree.inorder(), [10])

    def test_minimum_and_maximum(self):
        tree = AVLTree()

        with self.assertRaises(ValueError):
            tree.minimum()

        with self.assertRaises(ValueError):
            tree.maximum()

        for key in (50, 30, 70, 20, 40, 60, 80):
            tree.insert(key)

        self.assertEqual(tree.minimum(), 20)
        self.assertEqual(tree.maximum(), 80)

    def test_inorder_is_sorted(self):
        tree = AVLTree()
        keys = [30, 10, 20, 40, 50, 25, 5, 35]

        for key in keys:
            tree.insert(key)

        self.assertEqual(tree.inorder(), sorted(keys))
        self.assertEqual(list(tree), sorted(keys))


class TestAVLRotations(unittest.TestCase):
    def test_left_left_rotation(self):
        tree = AVLTree()

        for key in (30, 20, 10):
            tree.insert(key)

        self.assertEqual(tree.root.key, 20)
        self.assertEqual(tree.root.left.key, 10)
        self.assertEqual(tree.root.right.key, 30)
        self.assertTrue(tree.is_valid_avl())

    def test_right_right_rotation(self):
        tree = AVLTree()

        for key in (10, 20, 30):
            tree.insert(key)

        self.assertEqual(tree.root.key, 20)
        self.assertEqual(tree.root.left.key, 10)
        self.assertEqual(tree.root.right.key, 30)
        self.assertTrue(tree.is_valid_avl())

    def test_left_right_rotation(self):
        tree = AVLTree()

        for key in (30, 10, 20):
            tree.insert(key)

        self.assertEqual(tree.root.key, 20)
        self.assertEqual(tree.root.left.key, 10)
        self.assertEqual(tree.root.right.key, 30)
        self.assertTrue(tree.is_valid_avl())

    def test_right_left_rotation(self):
        tree = AVLTree()

        for key in (10, 30, 20):
            tree.insert(key)

        self.assertEqual(tree.root.key, 20)
        self.assertEqual(tree.root.left.key, 10)
        self.assertEqual(tree.root.right.key, 30)
        self.assertTrue(tree.is_valid_avl())

    def test_sequential_insertions_stay_balanced(self):
        tree = AVLTree()

        for key in range(1, 101):
            tree.insert(key)

        self.assertEqual(len(tree), 100)
        self.assertEqual(tree.height, 7)
        self.assertTrue(tree.is_valid_avl())
        self.assertEqual(tree.inorder(), list(range(1, 101)))


class TestAVLDeletion(unittest.TestCase):
    def test_delete_leaf(self):
        tree = AVLTree()

        for key in (20, 10, 30):
            tree.insert(key)

        self.assertTrue(tree.delete(10))
        self.assertFalse(tree.search(10))
        self.assertEqual(tree.inorder(), [20, 30])
        self.assertTrue(tree.is_valid_avl())

    def test_delete_node_with_one_child(self):
        tree = AVLTree()

        for key in (20, 10, 30, 5):
            tree.insert(key)

        self.assertTrue(tree.delete(10))
        self.assertFalse(tree.search(10))
        self.assertEqual(tree.inorder(), [5, 20, 30])
        self.assertTrue(tree.is_valid_avl())

    def test_delete_node_with_two_children(self):
        tree = AVLTree()

        for key in (20, 10, 30, 5, 15, 25, 35):
            tree.insert(key)

        self.assertTrue(tree.delete(20))
        self.assertFalse(tree.search(20))
        self.assertEqual(tree.inorder(), [5, 10, 15, 25, 30, 35])
        self.assertEqual(len(tree), 6)
        self.assertTrue(tree.is_valid_avl())

    def test_delete_missing_key(self):
        tree = AVLTree()

        for key in (10, 5, 15):
            tree.insert(key)

        self.assertFalse(tree.delete(99))
        self.assertEqual(len(tree), 3)
        self.assertEqual(tree.inorder(), [5, 10, 15])

    def test_delete_from_empty_tree(self):
        tree = AVLTree()

        self.assertFalse(tree.delete(10))
        self.assertEqual(len(tree), 0)
        self.assertTrue(tree.is_valid_avl())

    def test_delete_root_repeatedly(self):
        tree = AVLTree()

        for key in range(1, 11):
            tree.insert(key)

        for key in (6, 7, 5):
            self.assertTrue(tree.delete(key))

        self.assertEqual(tree.inorder(), [1, 2, 3, 4, 8, 9, 10])
        self.assertTrue(tree.is_valid_avl())

    def test_delete_many_keys_stays_balanced(self):
        tree = AVLTree()

        for key in range(1, 101):
            tree.insert(key)

        for key in range(2, 101, 2):
            self.assertTrue(tree.delete(key))

        expected = list(range(1, 101, 2))

        self.assertEqual(tree.inorder(), expected)
        self.assertEqual(len(tree), 50)
        self.assertTrue(tree.is_valid_avl())

    def test_deletion_causes_rebalancing(self):
        tree = AVLTree()

        for key in (50, 30, 70, 20, 40, 60, 80, 10):
            tree.insert(key)

        self.assertTrue(tree.delete(80))
        self.assertTrue(tree.is_valid_avl())


class TestAVLTraversalsAndDisplay(unittest.TestCase):
    def test_traversals(self):
        tree = AVLTree()

        for key in (20, 10, 30, 5, 15):
            tree.insert(key)

        self.assertEqual(tree.preorder(), [20, 10, 5, 15, 30])
        self.assertEqual(tree.postorder(), [5, 15, 10, 30, 20])
        self.assertEqual(tree.level_order(), [20, 10, 30, 5, 15])

    def test_print_empty_tree(self):
        tree = AVLTree()
        captured_output = StringIO()

        with patch("sys.stdout", new=captured_output):
            tree.print_tree()

        self.assertEqual(captured_output.getvalue(), "Tree is empty\n")

    def test_print_tree_contains_keys(self):
        tree = AVLTree()

        for key in (20, 10, 30):
            tree.insert(key)

        captured_output = StringIO()

        with patch("sys.stdout", new=captured_output):
            tree.print_tree()

        output = captured_output.getvalue()

        self.assertIn("20", output)
        self.assertIn("10", output)
        self.assertIn("30", output)
        self.assertIn("h=", output)
        self.assertIn("bf=", output)


if __name__ == "__main__":
    unittest.main()
