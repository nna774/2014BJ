#include <stdio.h>
#include <math.h>

static const double THETA = 0.5;
static const double E = 0.5;
static const double T = 1;
static const double H = 1e-8;

double f(double theta, double e, double t) {
    return theta - e * sin(theta) - t;
}

double df_dt(double theta, double e, double t) {
    return 1 - e * cos(theta);
}

double Df(double theta, double e, double t, double h) {
    return (f(theta + h, e, t) - f(theta, e, t)) / h;
}

int main() {
    printf("f: %e\n", f(THETA, E, T));
    printf("df/dth: %e\n", df_dt(THETA, E, T));
    printf("Df: %e\n", Df(THETA, E, T, H));
    return 0;
}
