#include <stdio.h>

int whoIsMax(int a, int b) {

    return a > b ? a : b;
}

int main() {

    int a, b;
    char end[2];
    char input[80];

    if (fgets(input, sizeof(input), stdin) == NULL) {
        printf("n/a");
        return 0;
    }

    if (sscanf(input, "%d %d%s", &a, &b, end) != 2) {
        printf("n/a");
        return 0;
    }

    printf("%d", whoIsMax(a, b));

    return 0;
}