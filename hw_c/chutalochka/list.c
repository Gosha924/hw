#include "list.h"
#include <stdio.h>
#include <stdlib.h>

LinkedList* createNewList()
{
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    if (list == NULL) {
        printf("Ошибка выделения памяти для списка\n");
        return NULL;
    }
    list->head = NULL;
    list->size = 0;
    return list;
}

void insertSorted(LinkedList* list, int value)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Ошибка выделения памяти для нового узла\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;
    if (list->head == NULL || value < list->head->data) {
        newNode->next = list->head;
        list->head = newNode;
        list->size++;
        return;
    }
    Node* current = list->head;
    while (current->next != NULL && current->next->data < value) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
    list->size++;
}

int removeIndex(LinkedList* list, int index)
{
    if (index < 0 || index >= list->size) {
        return -1;
    }
    Node* current = list->head;
    Node* previous = NULL;
    int removedValue;
    if (index == 0) {
        removedValue = current->data;
        list->head = current->next;
        free(current);
    } else {
        for (int i = 0; i < index; i++) {
            previous = current;
            current = current->next;
        }
        removedValue = current->data;
        previous->next = current->next;
        free(current);
    }
    list->size--;
    return removedValue;
}

void printList(LinkedList* list)
{
    Node* current = list->head;
    do {
        printf("%d", current->data);
        if (current->next != list->head) {
            printf(" -> ");
        }
        current = current->next;
    } while (current != list->head);
}

void deleteList(LinkedList* list)
{
    if (list == NULL) {
        return;
    }
    Node* current = list->head;
    Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    free(list);
}

int getSize(LinkedList* list)
{
    if (list == NULL) {
        return 0;
    }
    return list->size;
}

int get(LinkedList* list, int index)
{
    if (index < 0 || index >= list->size) {
        printf("Индекс за пределами списка\n");
        return -1;
    }
    Node* current = list->head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->data;
}