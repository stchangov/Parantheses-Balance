#ifndef stack_h
#define stack_h
#include "status.h"


typedef void* STACK;

STACK StackInitDefault(void);

Status StackPush(STACK hStack, char c);

Status StackPop(STACK hStack);

char StackTop(STACK hStack, Status* pStatus);

void StackDestroy(STACK* phStack);

Boolean StackIsEmpty(STACK hStack);



#endif /* stack_h */
