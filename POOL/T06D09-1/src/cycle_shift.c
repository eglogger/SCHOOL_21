#include <stdio.h>
#define NMAX 10

int input(int *buffer, int *length, int *shift);
void output(int *buffer, int length);
void arrShift(int *buffer, int length, int shift, int *arr_m);

int main() {
    int n, data[NMAX], data_m[NMAX];
    int shift_v;

    if (input(data, &n, &shift_v)) {
        arrShift(data, n, shift_v, data_m);
        output(data_m, n);
    } else {
        printf("n/a\n");
    }

    return 0;
}

int input(int *buffer, int *length, int *shift) {
    char check;
    int flag = 1;

    scanf("%d%c", length, &check);

    if (*length < 1 || *length > NMAX || (check != '\n' && check != ' ')) {
        flag = 0;
    }

    if (flag == 1) {
        for (int i = 0; i < *length; i++) {
            if (scanf("%d%c", &buffer[i], &check) == 2) {
                if (i == *length - 1 && check != '\n') {
                    flag = 0;
                }
                if (check != '\n' && check != ' ') {
                    flag = 0;
                }
            } else {
                flag = 0;
            }
        }

        if (scanf("%d%c", shift, &check) != 2) {
            flag = 0;
        }
    }

    return flag;
}

void output(int *buffer, int length) {
    for (int i = 0; i < length; i++) {
        if (i == length - 1) {
            printf("%d\n", buffer[i]);
        } else {
            printf("%d ", buffer[i]);
        }
    }
}

void arrShift(int *buffer, int length, int shift, int *arr_m) {
    int s = -shift;
    if (shift != 0) {
        for (int i = 0; i < length; i++) {
            if (s >= length) {
                s = s - length;
            }
            if (s < 0) {
                s = length + s;
            }
            arr_m[s] = buffer[i];
            s++;
        }
    } else {
        for (int i = 0; i < length; i++) {
            arr_m[i] = buffer[i];
        }
    }
}