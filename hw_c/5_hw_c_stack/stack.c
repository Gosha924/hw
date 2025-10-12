#include <stdio.h>
#include <stdlib.h>

typedef struct tag_obj {
    int data;
    struct tag_obj* next;
} OBJ;

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
    printf("deleted %d\n", top->data);
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

int main(void)
{
    return 0;
}