#include "list.h"
#include <stdio.h>
#include <stdlib.h>

LinkedList* createNewList()
{
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    if (list == NULL) {
        printf("Ошибка выделения памяти\n");
        return NULL;
    }
    list->head = NULL;
    list->size = 0;
    return list;
}

void insertNum(LinkedList* list, int value)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    if (list->head == NULL) {
        list->head = newNode;
    } else {
        Node* current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
    list->size++;
}
void printList(LinkedList* list)
{
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

int getValue(LinkedList* list, int index)
{
    Node* current = list->head;
    int indexElem = 0;
    while (current != NULL) {
        if (index == indexElem) {
            return current->data;
        }
        current = current->next;
        indexElem++;
    }
}

void deleteList(LinkedList* list)
{
    Node* current = list->head;
    Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    free(list);
}
