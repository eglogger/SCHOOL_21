#ifndef RPN_H
#define RPN_H

#include <math.h>

#include "lexemas_list.h"
#include "stack.h"

int priority(char op);
double applyOp(double a, double b, char op);
char* toRPN(const char* str);
double calcRPN(const char* rpn, double x_value);

#endif