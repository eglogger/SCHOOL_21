#include "draw.h"

#include "rpn.h"

void draw(char *rpn) {
    int width = 80, height = 25;
    double values[width];
    double x = 0.0, stepX = 4.0 * M_PI / width;

    for (int i = 0; i < width; i++) {
        double y = calcRPN(rpn, x);
        values[i] = y;
        x += stepX;
    }

    double stepY = 2.0 / height, math_error = stepY / 2.0;
    for (double y = -1.0; y <= 1.0; y += stepY) {
        for (int i = 0; i < width; i++) {
            if (values[i] <= y + math_error && values[i] >= y - math_error) {
                printf("*");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}