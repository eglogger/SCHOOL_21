#ifndef STACK_H
#define STACK_H

#include <stdlib.h>

typedef struct Stack {
    double data;
    struct Stack *next;
} Stack;

void stackInit(Stack **top);
int isEmpty(const Stack *top);
void push(Stack **top, double e);
double getTop(Stack *top);
double pop(Stack **top);

#endif