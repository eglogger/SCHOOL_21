#include <stdio.h>

int input(int *a, int n);
void output(int *a, int n);
void copyArr(int *a, int *b, int n);
void swap(int *a, int *b);
int partition(int *a, int low, int high);
void quickSort(int *a, int low, int high);
void heapify(int *a, int n, int i);
void heapSort(int *a, int n);

int main() {
    int n = 10, data[n], data_copy[n];

    if (input(data, n)) {
        copyArr(data, data_copy, n);
        quickSort(data, 0, n - 1);
        heapSort(data_copy, n);
        output(data, n);
        output(data_copy, n);
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

void copyArr(int *a, int *b, int n) {
    for (int i = 0; i < n; i++) {
        *(b + i) = *(a + i);
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *a, int low, int high) {
    int p = *(a + low);
    int i = low;
    int j = high;

    while (i < j) {
        while (*(a + i) <= p && i <= high - 1) {
            i++;
        }

        while (*(a + j) > p && j >= low + 1) {
            j--;
        }

        if (i < j) {
            swap(&*(a + i), &*(a + j));
        }
    }
    swap(&*(a + low), &*(a + j));
    return j;
}

void quickSort(int *a, int low, int high) {
    if (low < high) {
        int pi = partition(a, low, high);

        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}

void heapify(int *a, int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && *(a + l) > *(a + largest)) {
        largest = l;
    }

    if (r < n && *(a + r) > *(a + largest)) {
        largest = r;
    }

    if (largest != i) {
        swap(&*(a + i), &*(a + largest));
        heapify(a, n, largest);
    }
}

void heapSort(int *a, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(a, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        swap(&*a, &*(a + i));
        heapify(a, i, 0);
    }
}