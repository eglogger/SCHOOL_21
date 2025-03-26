#include <stdio.h>
#define N 15
#define M 13

void transform(int *buf, int **matr, int n, int m);
void make_picture(int **picture, int n, int m);
void reset_picture(int **picture, int n, int m);

int main() {
    int picture_data[N][M];
    int *picture[N];
    transform(&picture_data[0][0], picture, N, M);

    make_picture(picture, N, M);
    return 0;
}

void make_picture(int **picture, int n, int m) {
    int frame_w[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int frame_h[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    const int tree_trunk[] = {7, 7, 7, 7};
    const int tree_foliage[] = {3, 3, 3, 3};
    int sun_data[6][5] = {{0, 6, 6, 6, 6}, {0, 0, 6, 6, 6}, {0, 0, 6, 6, 6},
                          {0, 6, 0, 0, 6}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}};

    reset_picture(picture, n, m);

    int length_frame_w = sizeof(frame_w) / sizeof(frame_w[0]);
    int length_frame_h = sizeof(frame_h) / sizeof(frame_h[0]);

    for (int i = 0; i < length_frame_w; i++) {
        picture[0][i] = frame_w[i];
        picture[n - 1][i] = frame_w[i];
    }

    for (int i = 0; i < length_frame_h; i++) {
        picture[i][0] = frame_h[i];
        picture[i][m - 1] = frame_h[i];
    }

    for (int i = 0; i < 4; i++) {
        picture[n - 5][2 + i] = tree_trunk[i];
    }

    for (int i = 0; i < 2; i++) {
        picture[n - 6][3 + i] = tree_trunk[i];
        picture[n - 7][3 + i] = tree_trunk[i];
        picture[n - 8][3 + i] = tree_trunk[i];
        picture[n - 9][3 + i] = tree_trunk[i];
    }

    for (int i = 0; i < 2; i++) {
        picture[n - 10][3 + i] = tree_foliage[i];
        picture[n - 13][3 + i] = tree_foliage[i];
    }

    for (int i = 0; i < 4; i++) {
        picture[n - 11][2 + i] = tree_foliage[i];
        picture[n - 12][2 + i] = tree_foliage[i];
    }

    for (int i = 0; i < 5; i++) {
        picture[n - 14][i + 7] = sun_data[0][i];
        picture[n - 13][i + 7] = sun_data[1][i];
        picture[n - 12][i + 7] = sun_data[2][i];
        picture[n - 11][i + 7] = sun_data[3][i];
        picture[n - 10][i + 7] = sun_data[4][i];
        picture[n - 9][i + 7] = sun_data[5][i];
    }

    for (int i = 0; i < length_frame_w; i++) {
        picture[0][i] = frame_w[i];
        picture[n / 2][i] = frame_w[i];
        picture[n - 1][i] = frame_w[i];
    }

    for (int i = 0; i < length_frame_h; i++) {
        picture[i][0] = frame_h[i];
        picture[i][m / 2] = frame_h[i];
        picture[i][m - 1] = frame_h[i];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (j == m - 1) {
                printf("%d", picture[i][j]);
            } else {
                printf("%d ", picture[i][j]);
            }
        }
        if (i != n - 1) {
            printf("\n");
        }
    }
}

void reset_picture(int **picture, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            picture[i][j] = 0;
        }
    }
}

void transform(int *buf, int **matr, int n, int m) {
    for (int i = 0; i < n; i++) {
        matr[i] = buf + i * m;
    }
}