#include <stdio.h>
#include <stdlib.h>

int inputCheck(int *i);
int inputCheckL(int *i);
int input(int ***matrix, int *n, int *m);
void output(int **matrix, int n, int m);
int sum(int **matrix_first, int n_first, int m_first, int **matrix_second, int n_second, int m_second,
        int ***matrix_result, int *n_result, int *m_result);
int mul(int **matrix_first, int n_first, int m_first, int **matrix_second, int n_second, int m_second,
        int ***matrix_result, int *n_result, int *m_result);
void transpose(int **matrix, int n, int m, int ***matrix_result, int *n_result, int *m_result);

int main() {
    int choice;
    int x, y, a, b, p, r;
    int **data1, **data2, **data_r;

    if (inputCheck(&choice) && choice > 0 && choice < 4) {
        switch (choice) {
            case 1:
                input(&data1, &x, &y);
                input(&data2, &a, &b);
                sum(data1, x, y, data2, a, b, &data_r, &p, &r);
                output(data_r, p, r);
                free(data1);
                free(data2);
                free(data_r);
                break;

            case 2:
                input(&data1, &x, &y);
                input(&data2, &a, &b);
                mul(data1, x, y, data2, a, b, &data_r, &p, &r);
                output(data_r, p, r);
                free(data1);
                free(data2);
                free(data_r);
                break;

            case 3:
                input(&data1, &x, &y);
                transpose(data1, x, y, &data_r, &p, &r);
                output(data_r, p, r);
                free(data1);
                free(data_r);
                break;

            default:
                printf("n/a");
                break;
        }
    } else {
        printf("n/a");
    }

    return 0;
}

int inputCheck(int *i) {
    char check;
    int flag = 1;

    if (scanf("%d%c", i, &check) != 2 || (check != ' ' && check != '\n')) {
        flag = 0;
    }

    return flag;
}

int inputCheckL(int *i) {
    char check;
    int flag = 1;

    if (scanf("%d%c", i, &check) != 2 || check != '\n') {
        flag = 0;
    }

    return flag;
}

int input(int ***matrix, int *n, int *m) {
    int flag = 0;

    if (inputCheck(n) && inputCheck(m) && *n > 0 && *m > 0) {
        flag = 1;
    }

    *matrix = malloc(*n * sizeof(int *));
    for (int i = 0; i < *n; i++) {
        (*matrix)[i] = malloc(*m * sizeof(int));
    }

    for (int i = 0; i < *n && flag; i++) {
        for (int j = 0; j < *m && flag; j++) {
            if (i == *n - 1 && j == *m - 1) {
                if (!inputCheckL(&(*matrix)[i][j])) {
                    flag = 0;
                }
            } else if (!inputCheck(&(*matrix)[i][j])) {
                flag = 0;
            }
        }
    }
    return flag;
}

void output(int **matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j == m - 1) {
                printf("%d", matrix[i][j]);
            } else {
                printf("%d ", matrix[i][j]);
            }
        }
        if (i != n - 1) {
            printf("\n");
        }
    }
}

int sum(int **matrix_first, int n_first, int m_first, int **matrix_second, int n_second, int m_second,
        int ***matrix_result, int *n_result, int *m_result) {
    int flag = 1;

    if (n_first != n_second || m_first != m_second) {
        flag = 0;
    } else {
        *n_result = n_first;
        *m_result = m_first;

        *matrix_result = malloc(*n_result * sizeof(int *));
        for (int i = 0; i < *n_result; i++) {
            (*matrix_result)[i] = malloc(*m_result * sizeof(int));
        }

        for (int i = 0; i < *n_result; i++) {
            for (int j = 0; j < *m_result; j++) {
                (*matrix_result)[i][j] = matrix_first[i][j] + matrix_second[i][j];
            }
        }
    }

    return flag;
}

int mul(int **matrix_first, int n_first, int m_first, int **matrix_second, int n_second, int m_second,
        int ***matrix_result, int *n_result, int *m_result) {
    int flag = 1;

    if (m_first != n_second) {
        flag = 0;
    } else {
        *n_result = n_first;
        *m_result = m_second;

        *matrix_result = malloc(*n_result * sizeof(int *));
        for (int i = 0; i < *n_result; i++) {
            (*matrix_result)[i] = malloc(*m_result * sizeof(int));
        }

        for (int i = 0; i < *n_result; i++) {
            for (int j = 0; j < *m_result; j++) {
                for (int k = 0; k < m_first; k++) {
                    (*matrix_result)[i][j] += matrix_first[i][k] * matrix_second[k][j];
                }
            }
        }
    }
    return flag;
}

void transpose(int **matrix, int n, int m, int ***matrix_result, int *n_result, int *m_result) {
    *n_result = n;
    *m_result = m;

    *matrix_result = malloc(*n_result * sizeof(int *));
    for (int i = 0; i < *n_result; i++) {
        (*matrix_result)[i] = malloc(*m_result * sizeof(int));
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            (*matrix_result)[j][i] = matrix[i][j];
        }
    }
}