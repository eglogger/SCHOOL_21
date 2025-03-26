#include <math.h>
#include <stdio.h>

int isPrime(int num);

int main() {
    int a;
    int output = 0;
    char check;

    scanf("%d%c", &a, &check);

    if (check != '\n') {
        printf("n/a");
        return 0;
    }

    if (a < 0) {
        a = -a;
    }

    for (int i = 2; i <= a; i++) {
        int temp = a;

        while (temp > 0) {
            temp -= i;
        }

        if (temp == 0 && isPrime(i)) {
            output = i;
        }
    }

    if (output != 0) {
        printf("%d", output);
        return 0;
    } else {
        printf("n/a");
        return 0;
    }
}

int isPrime(int num) {
    if (num <= 1) {
        return 0;
    }

    for (int i = 2; i < num; i++) {
        int temp = num;

        while (temp > 0) {
            temp = temp - i;
        }

        if (temp == 0) {
            return 0;
        }
    }

    return 1;
}