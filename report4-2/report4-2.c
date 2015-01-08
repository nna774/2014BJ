#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "SFMT.h"

#define SQARE(x) ((x) * (x))
#define ABS(x) ((x) > 0 ? (x) : -(x))


double f(double x) {
    return 2 * (1 + SQARE(x)) / (SQARE(1 - x * x) + SQARE(x));
}

double integral(int n) {
    double res = 0;
    for(int i=0; i < n; ++i) res += f(genrand_real2());
    return res / n;
}

int main() {
    double pi = atan(1.0) * 4;
    init_gen_rand(12597);
    int n = 1;
    for(int i=1; i < 7; ++i) {
        n *= 10;
        double res = integral(n);
        double e = 1.0 / sqrt(n);
        printf("1e%d: %e error: %e l: %e\n", i, res, ABS(pi-res), ABS(pi-res)/ e);
    }
    return 0;
}
