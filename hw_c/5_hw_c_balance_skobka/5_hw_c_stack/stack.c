#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

OBJ* push(OBJ* top, int data)
{
    OBJ* ptr = malloc(sizeof(OBJ));
    ptr->data = data;
    ptr->next = top;
    return ptr;
}

OBJ* pop(OBJ* top)
{
    if (top == NULL) {
        return top;
    }
    OBJ* ptr_next = top->next;
    free(top);
    return ptr_next;
}

void show(const OBJ* top)
{
    const OBJ* current = top;
    while (current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    }
}

int showElem(const OBJ* top, int index)
{
    const OBJ* current = top;
    int indexElem = 0;
    while (current != NULL) {
        if (indexElem == index) {
            return current->data;
        }
        indexElem++;
        current = current->next;
    }
}

int lenStack(const OBJ* top)
{
    const OBJ* current = top;
    int len = 0;
    while (current != NULL) {
        len++;
        current = current->next;
    }
    return len;
}
