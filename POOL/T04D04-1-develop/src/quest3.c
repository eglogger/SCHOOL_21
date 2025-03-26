#include <math.h>
#include <stdio.h>

int seqFibonacci(int num);

int main() {
    int a;
    char check;

    scanf("%d%c", &a, &check);

    if (check != '\n') {
        printf("n/a");
        return 0;
    }

    printf("%d", seqFibonacci(a));
    return 0;
}

int seqFibonacci(int pos) {
    if (pos == 1 || pos == 2) {
        return 1;
    }

    return seqFibonacci(pos - 2) + seqFibonacci(pos - 1);
}