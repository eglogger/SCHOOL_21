#ifndef INPUT_CHECK_H
#define INPUT_CHECK_H

#include "lexemas_list.h"

int is_digit(char c);
int checkBrackets(const char* str);
int checkForX(const char* str);
int checkInvalidCharacters(const char* str);
int checkOperators(const char* str);

#endif