#include <stdio.h>
#include <math.h>

static const double THETA = 0.5;
static const double E = 0.5;
static const double T = 2 * 3.141592653;
static const double DT = 0.05;
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
    int const N = T / DT + 2;
    double thetas[N];
    thetas[0] = 0;
    printf("%d %e %e %e\n", 0, 0.0, x(0, E), y(0, E));
    for(int i = 1; i < N; ++i){
        double theta = thetas[i-1];
        double t = i * DT;
        while(fabs(f(theta, E, t)) > EPS) {
            theta = theta - f(theta, E, t)/Df(theta, E, t, H);
        }
        thetas[i] = theta;
        printf("%d %e %e %e\n", i, t, x(theta, E), y(theta, E));
    }
    return 0;
}
