#include "draw.h"
#include "input_check.h"
#include "lexemas_list.h"
#include "rpn.h"
#include "stack.h"

int main() {
    char* input = lexema();

    if (checkBrackets(input) && checkForX(input) && checkInvalidCharacters(input) && checkOperators(input)) {
        char* rpn = toRPN(input);
        draw(rpn);
        free(input);
        free(rpn);
    } else {
        printf("Syntax error!\n");
        free(input);
    }

    return 0;
}