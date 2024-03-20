#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "status.h"


struct node;
typedef struct node Node;

struct node {
    char value;
    Node* next;
};

struct stack {
    Node* head;
};
typedef struct stack Stack;

STACK StackInitDefault(void) {
    Stack* pStack = (Stack*)malloc(sizeof(Stack));
    
    if (pStack != NULL) {  
        pStack->head = NULL;
    }
    
    return pStack;
}
    
Boolean StackIsEmpty(STACK hStack) {
    Stack* pStack = (Stack*)hStack;
    
    return (pStack->head == NULL)?TRUE:FALSE;
}

char StackTop(STACK hStack, Status* pStatus) {
    Stack* pStack = (Stack*)hStack;
    
    if (StackIsEmpty(hStack)) {
        if (pStatus != NULL) {
            *pStatus = FAILURE;
        }
        return 'e';
    }
    if (pStatus != NULL) {
        *pStatus = SUCCESS;
    }
    return pStack->head->value;
}


Status StackPush(STACK hStack, char c) {
    Stack* pStack = (Stack*)hStack;
    Node* temp = (Node*)malloc(sizeof(Node));
    
    if (temp == NULL) {
        return FAILURE;
    }
    
    temp->value = c;
    temp->next = pStack->head;
    pStack->head = temp;
    
    return SUCCESS;
}

Status StackPop(STACK hStack) {
    Stack* pStack = (Stack*)hStack;
    Node* temp;
    
    if (StackIsEmpty(hStack)) {
        return FAILURE;
    }
    
    temp = pStack->head;
    pStack->head = pStack->head->next;
    free(temp);
    
    return SUCCESS;
}

void StackDestroy(STACK* phStack) {
    Stack* pStack = (Stack*)*phStack;
    Node* temp = pStack->head;
    
    while (pStack->head != NULL) {
        temp = pStack->head;
        pStack->head = pStack->head->next;
        free(temp);
    }
    free(pStack);
    
    *phStack = NULL;
}
