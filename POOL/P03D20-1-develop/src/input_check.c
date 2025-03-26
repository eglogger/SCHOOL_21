#include "input_check.h"

int is_digit(char c) { return (c >= '0' && c <= '9'); }

int checkBrackets(const char* str) {
    int flag = 1;
    int lbc = 0, rbc = 0;

    if (strchr(str, ')') < strchr(str, '(')) flag = 0;
    if (strrchr(str, ')') < strrchr(str, '(')) flag = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '(') lbc++;
        if (str[i] == ')') rbc++;
    }

    if (lbc != rbc) flag = 0;

    for (int i = 1; str[i] != '\0'; i++) {
        if (str[i] == '(' && str[i - 1] == ')') flag = 0;
        if (str[i] == ')' && str[i - 1] == '(') flag = 0;
    }

    return flag;
}

int checkForX(const char* str) {
    int flag = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == 'x') flag = 1;
    }
    return flag;
}

int checkInvalidCharacters(const char* str) {
    int flag = 1;
    for (int i = 0; str[i] != '\0'; i++) {
        char c = str[i];
        if (!(is_digit(c) || c == '.' || c == '+' || c == '-' || c == '*' || c == '/' || c == '(' ||
              c == ')' || c == 'x' || c == ' ' || strchr(OPERANDS, c))) {
            flag = 0;
        }
    }
    return flag;
}

int checkOperators(const char* str) {
    int flag = 1;
    for (int i = 0; str[i + 1] != '\0'; i++) {
        char current = str[i];
        char next = str[i + 1];

        if (((current == 'x') && (is_digit(next))) || (is_digit(current) && (next == 'x'))) {
            flag = 0;
        }
    }
    return flag;
}