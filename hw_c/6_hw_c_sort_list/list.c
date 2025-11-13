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

int removeValue(LinkedList* list, int value)
{
    Node* current = list->head;
    Node* previous = NULL;
    if (current->data == value) {
        list->head = current->next;
        free(current);
        list->size--;
        return 1;
    }
    while (current != NULL && current->data != value) {
        previous = current;
        current = current->next;
    }
    if (current == NULL) {
        return 0;
    }
    previous->next = current->next;
    free(current);
    list->size--;
    return 1;
}

void printList(LinkedList* list)
{
    if (list->head == NULL) {
        printf("Список пуст\n");
        return;
    }
    Node* current = list->head;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) {
            printf(" ");
        }
        current = current->next;
    }
    printf("\n");
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