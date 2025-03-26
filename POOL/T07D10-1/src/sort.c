#include <stdio.h>
#include <stdlib.h>

int input(int *buffer, int length);
void output(int *buffer, int length);
void sort(int *buffer, int length);

int main() {
    int n;
    int *data = NULL;

    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("n/a");
    }

    data = malloc(n * sizeof(int));

    if (input(data, n)) {
        sort(data, n);
        output(data, n);
    } else {
        printf("n/a");
    }

    free(data);
    return 0;
}

int input(int *buffer, int length) {
    char check;
    int flag = 1;

    for (int i = 0; i < length; i++) {
        scanf("%d%c", &buffer[i], &check);
        if (i == length - 1 && check != '\n') {
            flag = 0;
        }
        if (check != '\n' && check != ' ') {
            flag = 0;
        }
    }

    return flag;
}

void output(int *buffer, int length) {
    for (int i = 0; i < length; i++) {
        if (i == length - 1) {
            printf("%d", buffer[i]);
        } else {
            printf("%d ", buffer[i]);
        }
    }
}

void sort(int *buffer, int length) {
    int temp;
    for (int i = 0; i < length; ++i) {
        for (int j = i + 1; j < length; ++j) {
            if (buffer[i] > buffer[j]) {
                temp = buffer[i];
                buffer[i] = buffer[j];
                buffer[j] = temp;
            }
        }
    }
}