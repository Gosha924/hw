from itertools import permutations

# считываем данные
count = int(input("Введите количество ферзей: "))
if count <= 0:
    print("Введено некорректное число")
    exit()

result = 0
# проходим по всем возможным расстановкам
for perm in permutations(range(count)):
    valid = True
    for i in range(count):
        for j in range(i + 1, count):
            # проверяем есть ли ферзи на одной диагонали
            if abs(perm[i] - perm[j]) == abs(i - j):
                valid = False
                break
        if not valid:
            break
    if valid:
        result += 1
print(result)
