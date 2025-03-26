#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);

void output_result(int max_v, int min_v, double mean_v, double variance_v);

int main() {
    int n, data[NMAX];

    if (input(data, &n)) {
        output(data, n);
        output_result(max(data, n), min(data, n), mean(data, n), variance(data, n));
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

int min(int *a, int n) {
    int min = *a;
    for (int i = 0; i < n; i++) {
        if (*(a + i) < min) {
            min = *(a + i);
        }
    }
    return min;
}

int max(int *a, int n) {
    int max = *a;
    for (int i = 0; i < n; i++) {
        if (*(a + i) > max) {
            max = *(a + i);
        }
    }
    return max;
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

void output_result(int max_v, int min_v, double mean_v, double variance_v) {
    printf("%d %d %lf %lf\n", max_v, min_v, mean_v, variance_v);
}