#include <stdio.h>
#include <math.h>

static const double THETA = 0.5;
static const double E = 0.5;
static const double T = 1;
static const double H = 1e-8;
static const double EPS = 1e-8;

double f(double theta, double e, double t) {
    return theta - e * sin(theta) - t;
}

double Df(double theta, double e, double t, double h) {
    return (f(theta + h, e, t) - f(theta, e, t)) / h;
}

double x(double theta, double e) {
    return cos(theta) - e;
}

double y(double theta, double e) {
    return sqrt(1 - e * e) * sin(theta);
}

int main() {
    double theta = 0.5;
    double const t = 0.25;
    while(fabs(f(theta, E, t)) > EPS) {
        theta = theta - f(theta, E, t)/Df(theta, E, t, H);
    }
    printf("t: %e\n", t);
    printf("theta: %e\n", theta);
    printf("x: %e\n", x(theta, E));
    printf("y: %e\n", y(theta, E));
    return 0;
}
