/*
    Search module for the desired value from data array.

    Returned value must be:
        - "even"
        - ">= mean"
        - "<= mean + 3 * sqrt(variance)"
        - "!= 0"

        OR

        0
*/

#include <math.h>
#include <stdio.h>
#define NMAX 30

int input(int *a, int *n);
double mean(int *a, int n);
double variance(int *a, int n);
int isEven(int num);
int search(int *a, int n);

int main() {
    int n, data[NMAX];

    if (input(data, &n)) {
        printf("%d\n", search(data, n));
    } else {
        printf("n/a\n");
    }

    return 0;
}

int input(int *a, int *n) {
    char check;
    int flag = 1;

    scanf("%d%c", n, &check);

    if (*n < 1 || *n > NMAX || check != '\n') {
        flag = 0;
    }

    if (flag == 1) {
        for (int i = 0; i < *n; i++) {
            if (scanf("%d%c", &*(a + i), &check) == 2) {
                if (i == *n - 1 && check != '\n') {
                    flag = 0;
                }
                if (check != '\n' && check != ' ') {
                    flag = 0;
                }
            } else {
                flag = 0;
            }
        }
    }

    return flag;
}

double mean(int *a, int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += *(a + i);
    }

    return sum / n;
}

double variance(int *a, int n) {
    double mean_c = mean(&*a, n);
    double sum;
    for (int i = 0; i < n; i++) {
        sum += (*(a + i) - mean_c) * (*(a + i) - mean_c);
    }

    return sum / n;
}

int isEven(int num) {
    if (num % 2 == 0) {
        return 1;
    } else {
        return 0;
    }
}

int search(int *a, int n) {
    for (int i = 0; i < n; i++) {
        if (isEven(*(a + i)) && (*(a + i) >= mean(&*a, n)) &&
            (*(a + i) <= ((mean(&*a, n) + 3) * sqrt(variance(&*a, n)))) && (*(a + i) != 0)) {
            return *(a + i);
        }
    }
    return 0;
}