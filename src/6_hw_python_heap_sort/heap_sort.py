def heapify(array, n, i):
    """Функция для создания кучи"""
    largest = i
    left = 2 * i + 1
    right = 2 * i + 2
    if left < n and array[i] < array[left]:
        largest = left
    if right < n and array[largest] < array[right]:
        largest = right
    if largest != i:
        array[i], array[largest] = array[largest], array[i]
        heapify(array, n, largest)


def heap_sort(array):
    lenn = len(array)
    for i in range(lenn // 2 - 1, -1, -1):
        heapify(array, lenn, i)
    for i in range(lenn - 1, 0, -1):
        array[i], array[0] = array[0], array[i]
        heapify(array, i, 0)
    return array


if __name__ == '__main__':
    count = int(input("Input array`s len: "))
    array = [int(input()) for i in range(count)]
    sort_array = heap_sort(array)
    print(sort_array)
