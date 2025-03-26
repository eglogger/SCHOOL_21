#include <stdio.h>
#include <stdlib.h>
#define NMAX 100

int input(int* i);
int inputLast(int* i);
void staticMatrix(int rows, int cols);
void dynamicMatrix1(int rows, int cols);
void dynamicMatrix2(int rows, int cols);
void dynamicMatrix3(int rows, int cols);

int main() {
    int choice;
    int x, y;

    if (input(&choice) && choice > 0 && choice < 5 && input(&x) && input(&y) && x > 0 && y > 0) {
        switch (choice) {
            case 1:
                staticMatrix(x, y);
                break;

            case 2:
                dynamicMatrix1(x, y);
                break;

            case 3:
                dynamicMatrix2(x, y);
                break;

            case 4:
                dynamicMatrix3(x, y);
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

int input(int* i) {
    char check;
    int flag = 1;

    if (scanf("%d%c", i, &check) != 2 || (check != ' ' && check != '\n')) {
        flag = 0;
    }

    return flag;
}

int inputLast(int* i) {
    char check;
    int flag = 1;

    if (scanf("%d%c", i, &check) != 2 || check != '\n') {
        flag = 0;
    }

    return flag;
}

void staticMatrix(int rows, int cols) {
    int matrix[NMAX][NMAX];
    int flag = 1;

    if (rows > NMAX || cols > NMAX) {
        flag = 0;
    }

    if (flag) {
        for (int i = 0; i < rows && flag; i++) {
            for (int j = 0; j < cols && flag; j++) {
                if (i == rows - 1 && j == cols - 1) {
                    if (!inputLast(&matrix[i][j])) {
                        flag = 0;
                    }
                } else if (!input(&matrix[i][j])) {
                    flag = 0;
                }
            }
        }
    }

    if (flag) {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (j == cols - 1) {
                    printf("%d", matrix[i][j]);
                } else {
                    printf("%d ", matrix[i][j]);
                }
            }
            if (i != rows - 1) {
                printf("\n");
            }
        }
    } else {
        printf("n/a");
    }
}

void dynamicMatrix1(int rows, int cols) {
    int** single_array_matrix = malloc(rows * cols * sizeof(int) + rows * sizeof(int*));
    int* ptr = (int*)(single_array_matrix + rows);
    int flag = 1;

    for (int i = 0; i < rows; i++) {
        single_array_matrix[i] = ptr + cols * i;
    }

    for (int i = 0; i < rows && flag; i++) {
        for (int j = 0; j < cols && flag; j++) {
            if (i == rows - 1 && j == cols - 1) {
                if (!inputLast(&single_array_matrix[i][j])) {
                    flag = 0;
                }
            } else if (!input(&single_array_matrix[i][j])) {
                flag = 0;
            }
        }
    }

    if (flag) {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (j == cols - 1) {
                    printf("%d", single_array_matrix[i][j]);
                } else {
                    printf("%d ", single_array_matrix[i][j]);
                }
            }
            if (i != rows - 1) {
                printf("\n");
            }
        }
    } else {
        printf("n/a");
    }

    free(single_array_matrix);
}

void dynamicMatrix2(int rows, int cols) {
    int** pointer_array = malloc(rows * sizeof(int*));
    int flag = 1;

    for (int i = 0; i < rows; i++) {
        pointer_array[i] = malloc(cols * sizeof(int));
    }

    for (int i = 0; i < rows && flag; i++) {
        for (int j = 0; j < cols && flag; j++) {
            if (i == rows - 1 && j == cols - 1) {
                if (!inputLast(&pointer_array[i][j])) {
                    flag = 0;
                }
            } else if (!input(&pointer_array[i][j])) {
                flag = 0;
            }
        }
    }

    if (flag == 1) {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (j == cols - 1) {
                    printf("%d", pointer_array[i][j]);
                } else {
                    printf("%d ", pointer_array[i][j]);
                }
            }
            if (i != rows - 1) {
                printf("\n");
            }
        }
    } else {
        printf("n/a");
    }

    free(pointer_array);
}

void dynamicMatrix3(int rows, int cols) {
    int** pointer_array = malloc(rows * sizeof(int*));
    int* values_array = malloc(rows * cols * sizeof(int));
    int flag = 1;

    for (int i = 0; i < rows; i++) {
        pointer_array[i] = values_array + cols * i;
    }

    for (int i = 0; i < rows && flag; i++) {
        for (int j = 0; j < cols && flag; j++) {
            if (i == rows - 1 && j == cols - 1) {
                if (!inputLast(&pointer_array[i][j])) {
                    flag = 0;
                }
            } else if (!input(&pointer_array[i][j])) {
                flag = 0;
            }
        }
    }

    if (flag == 1) {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (j == cols - 1) {
                    printf("%d", pointer_array[i][j]);
                } else {
                    printf("%d ", pointer_array[i][j]);
                }
            }
            if (i != rows - 1) {
                printf("\n");
            }
        }
    } else {
        printf("n/a");
    }

    free(values_array);
    free(pointer_array);
}