#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

void init(Stack **top) { *top = NULL; }

void push(Stack **top, int val) {
    Stack *p = (Stack *)malloc(sizeof(Stack));

    p->data = val;
    p->next = *top;
    *top = p;
}

int pop(Stack **top) {
    Stack *p = *top;

    int e = p->data;
    *top = p->next;
    free(p);

    return e;
}

void destroy(Stack **top) {
    Stack *current = *top;

    while (current != NULL) {
        Stack *temp = current;
        current = current->next;
        free(temp);
    }

    *top = NULL;
}