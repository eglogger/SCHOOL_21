#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define ROWS 25
#define COLS 80
#define MIN_SPEED 0.1
#define MAX_SPEED 10.0

void printBoard(int board[ROWS][COLS]);
int countCells(int board[ROWS][COLS], int x, int y);
void updateBoard(int board[ROWS][COLS]);
void inputManual(int board[ROWS][COLS]);
void inputPattern(int board[ROWS][COLS], char *filename);
void playGame(int board[ROWS][COLS]);
char getInput();
int kbhit();

int main(int argc, char **argv) {
    system("stty -icanon");
    int board[ROWS][COLS] = {0};

    if (argc == 2) {
        char *filename = *(argv + 1);
        inputPattern(board, filename);
    } else if (argc == 1) {
        inputManual(board);
    }

    printBoard(board);
    playGame(board);

    return 0;
}

void printBoard(int board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == 1) {
                printf("*");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
    printf("a - увеличить скорость\nz - уменьшить скорость\nq - выйти из игры\n");
}

int countCells(int board[ROWS][COLS], int x, int y) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (!(i == 0 && j == 0)) {
                int nx = (ROWS + (x + i)) % ROWS;
                int ny = (COLS + (y + j)) % COLS;
                if (board[nx][ny] == 1) {
                    count++;
                }
            }
        }
    }
    return count;
}

void updateBoard(int board[ROWS][COLS]) {
    int new_board[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int neighbors = countCells(board, i, j);
            if (board[i][j] == 1) {
                if (neighbors < 2 || neighbors > 3) {
                    new_board[i][j] = 0;
                } else {
                    new_board[i][j] = 1;
                }
            } else {
                if (neighbors == 3) {
                    new_board[i][j] = 1;
                } else {
                    new_board[i][j] = 0;
                }
            }
        }
    }
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = new_board[i][j];
        }
    }
}

void inputManual(int board[ROWS][COLS]) {
    printf("Введите начальное состояние поля:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            char tmp;
            scanf("%c", &tmp);
            while (tmp != '1' && tmp != '0') {
                scanf("%c", &tmp);
            }
            board[i][j] = tmp == '1' ? 1 : 0;
        }
    }
}

void inputPattern(int board[ROWS][COLS], char *filename) {
    if (filename != NULL) {
        FILE *fp = fopen(filename, "r");
        if (fp == NULL) {
            printf("\nНе удалось открыть файл '%s'.\n", filename);
            exit(1);
        }
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                char symbol;
                fscanf(fp, "%c", &symbol);
                if (symbol == '\n') {
                    fscanf(fp, "%c", &symbol);
                }
                board[i][j] = symbol == '1' ? 1 : 0;
            }
        }
        fclose(fp);
    }
}

int kbhit() {
    struct timeval tv;
    fd_set rdfs;

    tv.tv_sec = 0;
    tv.tv_usec = 0;

    FD_ZERO(&rdfs);
    FD_SET(STDIN_FILENO, &rdfs);

    select(STDIN_FILENO + 1, &rdfs, NULL, NULL, &tv);
    return FD_ISSET(STDIN_FILENO, &rdfs);
}

char getInput() {
    char button = '0';
    if (kbhit()) {
        button = getc(stdin);
    }
    return button;
}

void playGame(int board[ROWS][COLS]) {
    double speed_coef = 1;
    while (1) {
        char key;
        key = getInput();
        if (key == 'q') {
            break;
        } else if (key == 'a' && speed_coef > MIN_SPEED) {
            speed_coef /= 2;
        } else if (key == 'z' && speed_coef < MAX_SPEED) {
            speed_coef *= 2;
        }
        printf("\033[H\033[J");
        updateBoard(board);
        printBoard(board);

        usleep(100000.0 * speed_coef);
    }
}