def sortirovka(array):
    for i in range(len(array)):
        for j in range(len(array) - i - 1):
            if array[j] > array[j + 1]:
                array[j], array[j + 1] = array[j + 1], array[j]
    return array



a = [10, 9, 8, 7, 6, 5, 4, 3, 2, 1]
# если введете 10, то сортировать будeт массив а который создан выше
lenn = int(input("Ведите длину массива: "))
if lenn != 10:
    a = [int(input()) for i in range(lenn)]
print("Исходный массив")
print(a)
a = sortirovka(a)
print("Отсортированный массив")
print(sortirovka(a))
