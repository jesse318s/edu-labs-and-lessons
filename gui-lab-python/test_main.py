import unittest
import sys
from pathlib import Path

project_root = Path(__file__).parent
sys.path.append(str(project_root))

import main


class TestMainFunction(unittest.TestCase):
    def test_main_exists(self):
        self.assertTrue(callable(main.main))


if __name__ == '__main__':
    unittest.main()
