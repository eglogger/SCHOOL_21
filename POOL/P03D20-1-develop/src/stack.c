#include "stack.h"

void stackInit(Stack **top) { *top = NULL; }

int isEmpty(const Stack *top) {
    int flag = 0;
    if (top == NULL) {
        flag = 1;
    }
    return flag;
}

void push(Stack **top, double e) {
    Stack *p = (Stack *)malloc(sizeof(Stack));
    p->data = e;
    p->next = *top;
    *top = p;
}

double getTop(Stack *top) {
    if (!isEmpty(top)) {
        return top->data;
    }
    return 0;
}

double pop(Stack **top) {
    if (!isEmpty(*top)) {
        Stack *p = *top;
        double e = p->data;
        *top = p->next;
        free(p);
        return e;
    }
    return 0;
}