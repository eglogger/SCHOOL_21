#include "lexemas_list.h"

char *lexema() {
    char *result = malloc(SIZE * sizeof(char));
    int flag = 1;

    fgets(result, SIZE, stdin);

    format(result, &flag);

    return flag ? result : NULL;
}

void format(char *str, int *flag) {
    space(str);

    char result[SIZE];
    int count = 0;
    int i = 0;
    while (str[i] != '\0' && flag) {
        if (str[i] == 's') {
            if (str[i + 1] == 'i') {
                *flag = operand(str, i, "sin");
                if (*flag) {
                    result[count] = str[i];
                    count += 1;
                    i += 3;
                }
            } else if (str[i + 1] == 'q') {
                *flag = operand(str, i, "sqrt");
                if (*flag) {
                    result[count] = 'S';
                    count += 1;
                    i += 4;
                }
            }
        } else if (str[i] == 'c') {
            if (str[i + 1] == 'o') {
                *flag = operand(str, i, "cos");
                if (*flag) {
                    result[count] = str[i];
                    count += 1;
                    i += 3;
                }
            } else if (str[i + 1] == 't') {
                *flag = operand(str, i, "ctg");
                if (*flag) {
                    result[count] = 'C';
                    count += 1;
                    i += 3;
                }
            }
        } else if (str[i] == 't') {
            *flag = operand(str, i, "tan");
            if (*flag) {
                result[count] = str[i];
                count += 1;
                i += 3;
            }
        } else if (str[i] == 'l') {
            *flag = operand(str, i, "ln");
            if (*flag) {
                result[count] = str[i];
                count += 1;
                i += 2;
            }
        } else {
            result[count] = str[i];
            count += 1;
            i++;
        }
    }
    if (count != 0) result[count] = '\0';
    strcpy(str, result);
}

int operand(const char *str, int i, const char *operand) {
    int count = 0, flag = 1;
    while (operand[count] != '\0' && flag) {
        if (str[i] != operand[count]) {
            flag = 0;
        }
        count += 1;
        i++;
    }
    return flag;
}

void space(char *str) {
    char result[SIZE];
    int count = 0, i = 0;
    while (str[i] != '\n') {
        if (str[i] != ' ') {
            result[count] = str[i];
            count += 1;
        }
        i++;
    }
    result[count] = '\0';
    strcpy(str, result);
}

/* using operand like this

*flag = operand(str, i, "sin");
*flag = operand(str, i, "cos");
*flag = operand(str, i, "ctg");
*flag = operand(str, i, "tan");
*flag = operand(str, i, "ln");

*/