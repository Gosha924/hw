#include "../list.h"
#include <stdio.h>
#include <stdlib.h>

int testGetSize()
{
    int data[] = { 13, 34, 56, 42, 11, 2, 6, 234, 56567, 67, 78, 91 };
    int len = sizeof(data) / sizeof(int);
    LinkedList* list1 = createNewList();
    for (int i = 0; i < len; i++) {
        insertSorted(list1, data[i]);
    }
    int result = getSize(list1);
    deleteList(list1);
    return !(result == len);
}

int testEmptyList()
{
    LinkedList* list1 = createNewList();
    LinkedList* list2 = createNewList();
    insertSorted(list1, 3);
    int result = (getSize(list1) > 0) && (getSize(list2) == 0);
    deleteList(list1);
    deleteList(list2);
    return !result;
}
int testInsertSorted()
{
    LinkedList* list = createNewList();
    insertSorted(list, 12);
    insertSorted(list, 10);
    insertSorted(list, 15);
    int first = list->head->data;
    int second = list->head->next->data;
    int third = list->head->next->next->data;
    deleteList(list);
    return !(first == 10 && second == 12 && third == 15);
}

int testRemoveValue()
{
    LinkedList* list = createNewList();
    int data[] = { 12, 33, 123, 4, 545, 55 };
    int len = sizeof(data) / sizeof(int);
    for (int i = 0; i < len; i++) {
        insertSorted(list, data[i]);
    }
    int result1 = removeValue(list, 33);
    int result2 = removeValue(list, 999);

    deleteList(list);
    return !(result1 == 1 && result2 == 0);
}

int testRemoveFromSingleNodeList()
{
    LinkedList* list = createNewList();
    insertSorted(list, 6);
    int err = removeValue(list, 6);
    if (err != 1) {
        deleteList(list);
        return 1;
    }
    int result = list->head == NULL && getSize(list) == 0;
    deleteList(list);
    return !result;
}

int testInsertSortedOrder()
{
    LinkedList* list = createNewList();
    int data[] = { 11, 34, 15, 67, 89, 98, 12, 2, 3, 7, 77, 88, 95, 987, 9231 };
    int len = sizeof(data) / sizeof(int);
    for (int i = 0; i < len; i++) {
        insertSorted(list, data[i]);
    }
    Node* currNode = list->head;
    int result = 1;
    for (int i = 0; i < len - 1; i++) {
        if (currNode->data > currNode->next->data) {
            result = 0;
            break;
        }
        currNode = currNode->next;
    }
    deleteList(list);
    return !result;
}

int testDuplicateInsert()
{
    LinkedList* list = createNewList();
    insertSorted(list, 11);
    insertSorted(list, 22);
    insertSorted(list, 11);
    insertSorted(list, 30);
    insertSorted(list, 22);
    Node* current = list->head;
    int result = 1;
    int expected[] = { 11, 11, 22, 22, 30 };
    for (int i = 0; i < 5; i++) {
        if (current == NULL || current->data != expected[i]) {
            result = 0;
            break;
        }
        current = current->next;
    }
    result = result && (getSize(list) == 5);

    deleteList(list);
    return !result;
}

int testRemoveDuplicates()
{
    LinkedList* list = createNewList();
    insertSorted(list, 11);
    insertSorted(list, 22);
    insertSorted(list, 11);
    insertSorted(list, 30);
    insertSorted(list, 22);
    int result1 = removeValue(list, 11);
    int result2 = removeValue(list, 22);
    int size = getSize(list);
    deleteList(list);
    return !(result1 == 1 && result2 == 1 && size == 3);
}

int runTest()
{
    int failures = 0;
    if (testInsertSorted() != 0) {
        fprintf(stderr, "FAILURE: Insert sorted test failed\n");
        failures++;
    } else {
        printf("Test 1 PASSED.\n");
    }
    if (testEmptyList() != 0) {
        fprintf(stderr, "FAILURE: Empty list test failed\n");
        failures++;
    } else {
        printf("Test 2 PASSED.\n");
    }
    if (testInsertSortedOrder() != 0) {
        fprintf(stderr, "FAILURE: Sorted order test failed\n");
        failures++;
    } else {
        printf("Test 3 PASSED.\n");
    }

    if (testRemoveValue() != 0) {
        fprintf(stderr, "FAILURE: Remove value test failed\n");
        failures++;
    } else {
        printf("Test 4 PASSED.\n");
    }

    if (testRemoveFromSingleNodeList() != 0) {
        fprintf(stderr, "FAILURE: Remove from single node list test failed\n");
        failures++;
    } else {
        printf("Test 5 PASSED.\n");
    }

    if (testGetSize() != 0) {
        fprintf(stderr, "FAILURE: Get size test failed\n");
        failures++;
    } else {
        printf("Test 6 PASSED.\n");
    }

    if (testDuplicateInsert() != 0) {
        fprintf(stderr, "FAILURE: Duplicate insert test failed\n");
        failures++;
    } else {
        printf("Test 7 PASSED.\n");
    }

    if (testRemoveDuplicates() != 0) {
        fprintf(stderr, "FAILURE: Remove duplicates test failed\n");
        failures++;
    } else {
        printf("Test 8 PASSED.\n");
    }

    printf("\nTests completed: %d passed, %d failed\n", 8 - failures, failures);
    if (failures > 0) {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

int main(void)
{
    return runTest();
}