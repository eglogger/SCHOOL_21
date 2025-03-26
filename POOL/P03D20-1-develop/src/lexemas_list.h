#ifndef LEXEMAS_LIST_H
#define LEXEMAS_LIST_H
#define SIZE 100
#define OPERANDS "+-/*sScCtl()"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* lexema();
int validation(char* str);
void format(char* str, int* flag);
void space(char* str);
int operand(const char* str, int i, const char* operand);

#endif  // LEXEMAS_LIST_H