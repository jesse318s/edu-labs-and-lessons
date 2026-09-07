import unittest
from unittest.mock import patch
from io import StringIO
import main


class TestMain(unittest.TestCase):
    def test_hello_world(self):
        captured_output = StringIO()

        with patch('sys.stdout', new=captured_output):
            main.main()

        output = captured_output.getvalue()

        self.assertIn("Hello, World!\n", output)
        self.assertIn("a + b is equal to 3\n", output)
        self.assertIn("Number of HelloWorld objects: 2\n", output)


if __name__ == '__main__':
    unittest.main()
