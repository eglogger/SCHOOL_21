#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
void squaring(int *a, int n);

int main() {
    int n, data[NMAX];

    if (input(data, &n)) {
        squaring(data, n);
        output(data, n);
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

void output(int *a, int n) {
    for (int i = 0; i < n; i++) {
        if (i == n - 1) {
            printf("%d\n", *(a + i));
        } else {
            printf("%d ", *(a + i));
        }
    }
}

void squaring(int *a, int n) {
    for (int i = 0; i < n; i++) {
        *(a + i) *= *(a + i);
    }
}