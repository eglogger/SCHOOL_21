#include <stdio.h>

int input(int *a, int n);
void output(int *a, int n);
void sort(int *a, int n);

int main() {
    int n = 10, data[n];

    if (input(data, n)) {
        sort(data, n);
        output(data, n);
    } else {
        printf("n/a\n");
    }

    return 0;
}

int input(int *a, int n) {
    char check;
    int flag = 1;

    for (int i = 0; i < n; i++) {
        if (scanf("%d%c", &*(a + i), &check) == 2) {
            if (i == n - 1 && check != '\n') {
                flag = 0;
            }
            if (check != '\n' && check != ' ') {
                flag = 0;
            }
        } else {
            flag = 0;
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

void sort(int *a, int n) {
    int temp;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (*(a + i) > *(a + j)) {
                temp = *(a + i);
                *(a + i) = *(a + j);
                *(a + j) = temp;
            }
        }
    }
}