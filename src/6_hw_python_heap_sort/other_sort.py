def bubble_sort(array):
    new_array = array[:]
    for i in range(len(new_array) - 1):
        for j in range(len(new_array) - 1 - i):
            if new_array[j] > new_array[j + 1]:
                new_array[j], new_array[j + 1] = new_array[j + 1], new_array[j]
    return new_array


def quick_sort(array):
    if len(array) <= 1:
        return array
    elem = array[len(array) // 2]
    left = [x for x in array if x < elem]
    middle = [x for x in array if x == elem]
    right = [x for x in array if x > elem]
    return  quick_sort(left) + middle + quick_sort(right)