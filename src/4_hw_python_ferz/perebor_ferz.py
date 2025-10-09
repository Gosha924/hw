from itertools import permutations


count = int(input("Введите количество ферзей: "))
if count <= 0:
    print("Введено некорректное число")
    exit()
result = 0
for perm in permutations(range(count)):
    valid = True
    for i in range(count):
        for j in range(i + 1, count):
            if abs(perm[i] - perm[j]) == abs(i - j):
                valid = False
                break
        if not valid:
            break
    if valid:
        result += 1
print(result)
