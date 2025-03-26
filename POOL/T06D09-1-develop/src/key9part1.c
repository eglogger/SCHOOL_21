/*------------------------------------
        Здравствуй, человек!
        Чтобы получить ключ
        поработай с комментариями.
-------------------------------------*/
#include <stdio.h>
#define NMAX 10

int input(int *buffer, int *length);
void output(int *buffer, int length);
int sum_numbers(int *buffer, int length);
int find_numbers(int *buffer, int length, int number, int *numbers);

/*------------------------------------
        Функция получает массив данных
        через stdin.
        Выдает в stdout особую сумму
        и сформированный массив
        специальных элементов
        (выбранных с помощью найденной суммы):
        это и будет частью ключа
-------------------------------------*/
int main() {
    int n, data[NMAX], numbers[NMAX];

    if (input(data, &n)) {
        int sum = sum_numbers(data, n);
        int m = find_numbers(data, n, sum, numbers);

        if (m == 0) {
            printf("n/a\n");

        } else {
            printf("%d\n", sum);
            output(numbers, m);
        }
    } else {
        printf("n/a\n");
    }

    return 0;
}

/*------------------------------------
        Функция должна находить
        сумму четных элементов
        с 0-й позиции.
-------------------------------------*/
int sum_numbers(int *buffer, int length) {
    int sum = 0;

    for (int i = 0; i < length; i++) {
        if (buffer[i] % 2 == 0) {
            sum += buffer[i];
        }
    }

    return sum;
}

/*------------------------------------
        Функция должна находить
        все элементы, на которые нацело
        делится переданное число и
        записывает их в выходной массив.
-------------------------------------*/
int find_numbers(int *buffer, int length, int number, int *numbers) {
    int j = 0;
    for (int i = 0; i < length; i++) {
        if ((buffer[i] != 0) && (number % buffer[i] == 0)) {
            numbers[j] = buffer[i];
            j++;
        }
    }
    return j;
}

int input(int *buffer, int *length) {
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