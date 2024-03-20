#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void ClearKeyboardBuffer(void) {
    char c;
    int noc;
    noc = scanf("%c", &c);
    
    while (noc == 1 && c != '\n') {
        scanf("%c", &c);
    }
}

Boolean isMatch(void) {
    STACK hStack;
    int noc;
    char c;
    Boolean m = TRUE;
    
    hStack = StackInitDefault();
    if (hStack == NULL) {
        printf("Failed to allocate space for stack object.\n");
        exit(1);
    }

    noc = scanf("%c", &c);
   
    while (noc == 1 && c != '\n') {
        if (StackIsEmpty(hStack)) {
            if (c == '(' || c == '[' || c == '{') {
                StackPush(hStack, c);
            } else if (c == ')' || c == ']' || c == '}') {
                m = FALSE;
            }
        } else if (!StackIsEmpty(hStack)) {
            if (c == '(' || c == '[' || c == '{') {
                StackPush(hStack, c);
            } else if (c == ')' || c == ']' || c == '}') {
                if (c == ')' && StackTop(hStack, NULL) == '(') {
                    StackPop(hStack);
                } else if (c == ']' && StackTop(hStack, NULL) == '[') {
                    StackPop(hStack);
                } else if (c == '}' && StackTop(hStack, NULL) == '{') {
                    StackPop(hStack);
                } else {
                    m = FALSE;
                }
            }
        }
        noc = scanf("%c", &c);
    }
    if (!StackIsEmpty(hStack)) {
        m = FALSE;
    }
    
    StackDestroy(&hStack);
    return  m;
}

int main(int argc, const char * argv[]) {
    int n;
    
    scanf("%d", &n);  // get number of strings that the user will be inputting
    ClearKeyboardBuffer();
    
    while (n--) {
        if (isMatch()) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    
    return 0;
}


