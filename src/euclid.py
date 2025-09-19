a = int(input("input first number: "))
b = int(input("input second number: "))
old_first, first = 1, 0
old_second, second = 0, 1
while b != 0:
    chasnoe = a // b
    a, b = b, a - (chasnoe * b)
    old_first, first = first, old_first - (chasnoe * first)
    old_second, second = second, old_second - (chasnoe * second)

print(f"НОД: {abs(a)}, x: {old_first}, y: {old_second}")
