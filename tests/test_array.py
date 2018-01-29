import unittest
from algorithms import array

class TestArray(unittest.TestCase):
    def test_sum(self):
        instance = array.Array()
        result = instance.sum(6, '1 2 3 4 10 11')
        self.assertEqual(result, 31)
