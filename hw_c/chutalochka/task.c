#include "list.h"
#include <stdio.h>
#include <stdlib.h>

int killWarrior(int n, int m)
{
    LinkedList* list = createNewList();
    for (int i = 1; i <= n; i++) {
        insertSorted(list, i);
    }
    if (list->head != NULL) {
        Node* current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = list->head;
    }
    Node* current = list->head;
    Node* previous = NULL;
    int step = 1;
    while (list->size > 1) {
        if (step == m) {
            Node* toRemove = current;
            int removedValue = toRemove->data;

            if (previous != NULL) {
                previous->next = current->next;
            }
            current = current->next;
            if (toRemove == list->head) {
                list->head = current;
            }
            if (list->size == 2) {
                current->next = NULL;
            }
            free(toRemove);
            list->size--;
            printf("Убит воин номер %d. Осталось: %d воинов\n", removedValue, list->size);
            step = 1;
        } else {
            previous = current;
            current = current->next;
            step++;
        }
    }
    int lastWarrior = list->head->data;
    free(list->head);
    free(list);
    return lastWarrior;
}

int main(void)
{
    int n, m;
    printf("Введите количество воинов: ");
    scanf("%d", &n);
    printf("Введите шаг : ");
    scanf("%d", &m);
    if (n <= 0 || m <= 0) {
        printf("Ошибка: n и m должны быть положительными числами\n");
        return 0;
    }
    int result = killWarrior(n, m);
    printf("Последним остался воин номер %d\n", result);
    return 0;
}