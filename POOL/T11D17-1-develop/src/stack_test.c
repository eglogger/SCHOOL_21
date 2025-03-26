#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

int test_push() {
    Stack* stack;
    init(&stack);

    push(&stack, 10);
    push(&stack, 20);

    if (stack->data != 20) return 0;
    if (stack->next->data != 10) return 0;

    destroy(&stack);
    return 1;
}

int test_pop() {
    Stack* stack;
    init(&stack);

    push(&stack, 10);
    push(&stack, 20);

    if (pop(&stack) != 20) return 0;
    if (pop(&stack) != 10) return 0;

    destroy(&stack);
    return 1;
}

int main() {
    test_push() == 1 ? printf("SUCCESS\n") : printf("FAIL\n");
    test_pop() == 1 ? printf("SUCCESS") : printf("FAIL");

    return 0;
}