#include "rpn.h"

int priority(char op) {
    int result = 0;
    if (op == '+' || op == '-') result = 1;
    if (op == '*' || op == '/') result = 2;
    if (op == 's' || op == 'c' || op == 't' || op == 'l' || op == 'S' || op == 'C') result = 3;
    return result;
}

double applyOp(double a, double b, char op) {
    double result;
    switch (op) {
        case '+':
            result = a + b;
            break;
        case '-':
            result = a - b;
            break;
        case '*':
            result = a * b;
            break;
        case '/':
            result = a / b;
            break;
        case 's':
            result = sin(b);
            break;
        case 'c':
            result = cos(b);
            break;
        case 't':
            result = tan(b);
            break;
        case 'l':
            result = log(b);
            break;
        case 'S':
            result = sqrt(b);
            break;
        case 'C':
            result = 1 / tan(b);
            break;
        default:
            result = 0;
            break;
    }
    return result;
}

char* toRPN(const char* str) {
    char* result = (char*)malloc(SIZE * sizeof(char));
    int j = 0;
    Stack* stack;
    stackInit(&stack);

    for (int i = 0; str[i] != '\0'; i++) {
        char c = str[i];

        if ((c >= '0' && c <= '9') || c == '.' || c == 'x') {
            while ((c >= '0' && c <= '9') || c == '.' || c == 'x') {
                result[j++] = c;
                c = str[++i];
            }
            result[j++] = ' ';
            i--;
        }

        else if (c == '(') {
            push(&stack, c);
        }

        else if (c == ')') {
            while (!isEmpty(stack) && getTop(stack) != '(') {
                result[j++] = pop(&stack);
                result[j++] = ' ';
            }
            pop(&stack);
        }

        else if (strchr(OPERANDS, c)) {
            while (!isEmpty(stack) && priority(getTop(stack)) >= priority(c)) {
                result[j++] = pop(&stack);
                result[j++] = ' ';
            }
            push(&stack, c);
        }
    }

    while (!isEmpty(stack)) {
        result[j++] = pop(&stack);
        result[j++] = ' ';
    }

    result[j] = '\0';
    return result;
}

double calcRPN(const char* rpn, double x_value) {
    Stack* stack;
    stackInit(&stack);

    for (int i = 0; rpn[i] != '\0'; i++) {
        char c = rpn[i];

        if ((c >= '0' && c <= '9') || c == '.') {
            double num = 0;
            int decimal = 0, divisor = 1;
            while ((c >= '0' && c <= '9') || c == '.') {
                if (c == '.') {
                    decimal = 1;
                } else {
                    if (!decimal) {
                        num = num * 10 + (c - '0');
                    } else {
                        divisor *= 10;
                        num += (c - '0') / (double)divisor;
                    }
                }
                c = rpn[++i];
            }
            push(&stack, num);
            i--;
        }

        else if (c == 'x') {
            push(&stack, x_value);
        }

        else if (strchr(OPERANDS, c)) {
            double b = pop(&stack);
            double a =
                (c != 's' && c != 'c' && c != 't' && c != 'l' && c != 'S' && c != 'C') ? pop(&stack) : 0;
            push(&stack, applyOp(a, b, c));
        }
    }

    return pop(&stack);
}