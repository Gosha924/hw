import unittest
from main import heap_sort

class TestHeapSort(unittest.TestCase):
    def test_empty_list(self):
        self.assertEqual(heap_sort([]), [])
    def test_single_element(self):
        self.assertEqual(heap_sort([7]), [7])
    def test_sorted_list(self):
        input_list = [1, 2, 3, 4, 5]
        expected = [1, 2, 3, 4, 5]
        self.assertEqual(heap_sort(input_list), expected)
    def test_reverse_sorted_list(self):
        input_list = [5, 4, 3, 2, 1]
        expected = [1, 2, 3, 4, 5]
        self.assertEqual(heap_sort(input_list), expected)
    def test_duplicate_elements(self):
        input_list = [5, 6, 8, 1, 3, 9, 2, 1, 5, 3, 5]
        expected = [1, 1, 2, 3, 3, 5, 5, 5, 6, 8, 9]
        self.assertEqual(heap_sort(input_list), expected)
    def test_negative_numbers(self):
        input_list = [3, -1, 4, -2, 5, 0, -5]
        expected = [-5, -2, -1, 0, 3, 4, 5]
        self.assertEqual(heap_sort(input_list), expected)
    def test_all_same_elements(self):
        input_list = [1, 1, 1]
        expected = [1, 1, 1]
        self.assertEqual(heap_sort(input_list), expected)
    def test_simple_test(self):
        input_list = [23, 45, 12, 90, 1, 13, 24, 17]
        expected = [1, 12, 13, 17, 23, 24, 45, 90]
        self.assertEqual(heap_sort(input_list), expected)


if __name__ == '__main__':
    unittest.main(verbosity=2)
