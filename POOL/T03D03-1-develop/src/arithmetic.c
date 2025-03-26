#include <stdio.h>

int main() {

    int a, b;
    char end[2];
    char input[80];

    if (fgets(input sizeof(input), stdin) == NULL) {
        printf("n/a");
        return 0;
    }

    if (sscanf(input, "%d %d%s", &a, &b, end) != 2) {
        printf("n/a");
        return 0;
    }

    if (b == 0) {
        printf("%d %d %d n/a", a+b, a-b, a*b);
        return 0;
    }

    printf("%d %d %d %d", a+b, a-b, a*b, a/b);

    return 0;
}