def can_be_here_queen(new_queen_column, old_queen):
    if new_queen_column in old_queen:
        return False
    new_queen_row = len(old_queen)
    for row, colum in enumerate(old_queen):
        row_diff = new_queen_row - row
        colum_diff = abs(new_queen_column - colum)
        if colum_diff == row_diff:
            return False
    return True


def rekur_ferz(count):
    desk = [[]]
    for i in range(count):
        new_desk = []
        for position in desk:
            for colum in range(count):
                if can_be_here_queen(colum + 1, position):
                    new_desk.append(position + [colum + 1])
        desk = new_desk
    return len(desk)


count = int(input("Введите количество ферзей: "))
if count <= 0:
    print("Введено некорректное число")
    exit()
print(rekur_ferz(count))
