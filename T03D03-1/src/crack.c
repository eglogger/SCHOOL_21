#include <stdio.h>
#include <math.h>

int main() {

    double x, y;

    if (scanf("%lf %lf", &x, &y) != 2) {
        printf("n/a");
        return 0;
    }

    if (pow(x, 2) + pow(y, 2) <= 25) {
        printf("GOTCHA");
    } else {
        printf("MISS");
    }

    return 0;
}