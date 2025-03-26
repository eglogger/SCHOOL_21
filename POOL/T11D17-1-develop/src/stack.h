#ifndef STACK_H
#define STACK_H

typedef struct Stack {
    int data;
    struct Stack* next;
} Stack;

void init(Stack** top);
void push(Stack** stack, int value);
int pop(Stack** stack);
void destroy(Stack** stack);

#endif