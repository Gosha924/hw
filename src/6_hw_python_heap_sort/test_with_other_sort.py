from heap_sort import heap_sort
from other_sort import bubble_sort, quick_sort

class TestProperty:
    def test_sort_result_length(self):
        values = [12, 35, 78, 445, 11, 4, 2, 21, 7]
        lenght = len(values)
        assert len(heap_sort(values)) == lenght
        assert len(bubble_sort(values)) == lenght
        assert len(quick_sort(values)) == lenght

    def test_ordered_output(self):
        values = [6, 3, 23, 67, 78, 21, 81, 13, 5]
        result = heap_sort(values)
        result1 = bubble_sort(values)
        result2 = quick_sort(values)
        for i in range(1, len(result) - 1):
            assert result[i - 1] < result[i]
            assert result1[i - 1] < result1[i]
            assert result2[i - 1] < result2[i]

    def test_heap_sort_other_sort(self):
        values = [9, 8, 7, 6, 5, 4, 3, 2, 1]
        assert heap_sort(values) == quick_sort(values)
        assert heap_sort(values) == bubble_sort(values)