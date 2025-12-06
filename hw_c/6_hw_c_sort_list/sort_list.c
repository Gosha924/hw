#include "list.h"
#include <stdio.h>

int main(void)
{
    LinkedList* sortLst = createNewList();
    int command, value, result;
    do {
        puts("Введите команду");
        scanf("%d", &command);
        switch (command) {
        case 0:
            puts("Конец программы");
            break;
        case 1:
            puts("Введите значение для добавления: ");
            scanf("%d", &value);
            insertSorted(sortLst, value);
            break;
        case 2:
            puts("Введите значение для удаления: ");
            scanf("%d", &value);
            result = removeValue(sortLst, value);
            if (result) {
                printf("Значение %d удалено из списка\n", value);
            } else {
                printf("Значение %d не найдено в списке\n", value);
            }
            break;
        case 3:
            printList(sortLst);
            break;
        default:
            puts("Введите цифру от 0 до 3");
        }
    } while (command != 0);
    deleteList(sortLst);
    return 0;
}
