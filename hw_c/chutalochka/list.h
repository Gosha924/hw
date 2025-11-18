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
void insertSorted(LinkedList* list, int value);
int removeIndex(LinkedList* list, int index);
void printList(LinkedList* list);
void deleteList(LinkedList* list);
int getSize(LinkedList* list);
int get(LinkedList* list, int index);
#endif
