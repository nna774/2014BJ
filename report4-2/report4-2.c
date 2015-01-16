#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "SFMT.h"

#define SQARE(x) ((x) * (x))
#define ABS(x) ((x) > 0 ? (x) : -(x))

#define ITERATION 1000

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
    double res[6];
    for(int i=1; i < 7; ++i) res[i] = 0;
    for(int it=0; it < ITERATION; ++it) {
        init_gen_rand(12597+it);
        int n = 1;
        for(int i=1; i < 7; ++i) {
            n *= 10;
            res[i-1] += integral(n);
        }
    }
    for(int i=1; i < 7; ++i) res[i] /= ITERATION;
    int n = 1;
    for(int i=1; i < 7; ++i) {
        n *= 10;
        double e = 1.0 / sqrt(n);
        printf("1e%d: %e error: %e l: %e\n", i, res[i-1], ABS(pi-res[i-1]), ABS(pi-res[i-1])/ e);
    }
    return 0;
}
