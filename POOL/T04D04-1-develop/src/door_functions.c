#include <math.h>
#include <stdio.h>

double agnesi(double x);
double bernoulli(double x);
double hyperbola(double x);

int main() {
    double start = -M_PI;
    double end = M_PI;
    double step = (2 * M_PI) / 42;

    for (; start <= end; start += step) {
        if (isnan(bernoulli(start))) {
            printf("%.7lf | %.7lf | - | %.7lf\n", start, agnesi(start), hyperbola(start));
        } else {
            printf("%.7lf | %.7lf | %.7lf | %.7lf\n", start, agnesi(start), bernoulli(start),
                   hyperbola(start));
        }
    }

    return 0;
}

double agnesi(double x) {
    double y = pow(1, 3) / (pow(1, 2) + pow(x, 2));
    return y;
}

double bernoulli(double x) {
    double y = sqrt(sqrt(pow(1, 4) + 4 * pow(x, 2) * pow(1, 2)) - pow(x, 2) - pow(1, 2));
    return y;
}

double hyperbola(double x) {
    double y = 1 / pow(x, 2);
    return y;
}