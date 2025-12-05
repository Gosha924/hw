#ifndef LIST_H
#define LIST_H

// Структура узла списка
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Структура списка
typedef struct LinkedList {
    Node* head;
    int size;
} LinkedList;

LinkedList* createNewList();
void insertNum(LinkedList* list, int value);
void printList(LinkedList* list);
int getValue(LinkedList* list, int index);
void deleteList(LinkedList* list);
#endif