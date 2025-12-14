import pytest
import sys
from heap_sort import heap_sort

TEST_DATA = [
    ([], [], "empty"),
    ([1], [1], "single"),
    ([1, 2, 3], [1, 2, 3], "already_sorted"),
    ([3, 2, 1], [1, 2, 3], "reverse_sorted"),
    ([3, 1, 4, 1, 5], [1, 1, 3, 4, 5], "with_duplicates"),
    ([0, -1, 2, -3], [-3, -1, 0, 2], "with_negatives"),
    ([5, 5, 5], [5, 5, 5], "all_equal"),
    ([64, 34, 25, 12, 22, 11, 90], [11, 12, 22, 25, 34, 64, 90], "example"),
]


@pytest.mark.parametrize("input_list,expected,name", TEST_DATA)
def test_heap_sort_basic(input_list, expected, name):
    assert heap_sort(input_list) == expected


if __name__ == "__main__":
    sys.exit(pytest.main(["-v", __file__]))
