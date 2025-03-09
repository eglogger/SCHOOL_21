#include <math.h>
#include <stdio.h>

void encoding();
void decoding();

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("n/a");
        return 0;
    }

    char *operation_mode = *(argv + 1);

    switch (*operation_mode) {
        case '0':
            encoding();
            break;

        case '1':
            decoding();
            break;

        default:
            printf("n/a");
            break;
    }

    return 0;
}

void encoding() {
    char letter;
    char letter_separator;
    while (scanf("%c%c", &letter, &letter_separator)) {
        if (letter_separator != '\n' && letter_separator != ' ') {
            printf("n/a");
            break;
        }

        printf("%X ", letter);

        if (letter_separator == '\n') {
            break;
        }
    }
}

void decoding() {
    int hex;
    char hex_separator;
    while (scanf("%2X%c", &hex, &hex_separator)) {
        if (hex_separator != '\n' && hex_separator != ' ') {
            printf("n/a");
            break;
        }

        printf("%c ", hex);

        if (hex_separator == '\n') {
            break;
        }
    }
}