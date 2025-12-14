def make_change(amount, coins):
    name = coins[0]
    surname = coins[1]
    patronymic = coins[2]
    max_a = amount // name + 1
    max_b = amount // surname + 1
    for x in range(max_a + 1):
        for y in range(max_b + 1):
            remaining = amount - (x * name + y * surname)
            if remaining > 0 and remaining % patronymic == 0:
                z = remaining // patronymic
                return (x, y, z)
    return -42


name = input("Введите имя: ")
surname = input("Введите фамилию: ")
patronymic = input("Введите отчество (или Enter если нет): ")

name_len = len(name)
surname_len = len(surname)
if patronymic:
    patronymic_len = len(patronymic)
else:
    patronymic_len = 19

coins = [name_len, surname_len, patronymic_len]
amount = int(input("Введите сумму для размена: "))
result = make_change(amount, coins)
if result == -42:
    print("-42!")
else:
    print("\nРазмен найден:")
    print(f"Проверка: {result[0]}×{name_len} + {result[1]}×{surname_len} + {result[2]}×{patronymic_len} = {amount}")