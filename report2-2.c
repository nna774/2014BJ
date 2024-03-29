#include <stdio.h>
#include <math.h>

double const h = 1E-3;

double getR(double const * const xs){
    return sqrt(xs[0] * xs[0] + xs[1] * xs[1]);
}

void update(double* xs){
    double tmp[4] = {};
    for(int i = 0; i < 4; ++i) {
        tmp[i] = xs[i];
    }
    xs[0] = tmp[0] + h * tmp[2];
    xs[1] = tmp[1] + h * tmp[3];
    double m = pow(xs[0] * xs[0] + xs[1] * xs[1], -3.0/2.0);
    xs[2] = tmp[2] - h * tmp[0] * m; // こうすると精度がつらくなる(オイラー法に落ちる)
    xs[3] = tmp[3] - h * tmp[1] * m; // 
}

int main() {
    double const e = 0.5;
    double xs[4] = { 1 - e, 0, 0, sqrt((1+e)/(1-e)) };
    double r = getR(xs);
    double t = 0;

    int const N = 62834;
    for(int i = 0; i < N; ++i) {
        double E = (xs[2] * xs[2] + xs[3] * xs[3]) / 2.0 - 1.0 / getR(xs);
        printf("%e %e %e %e %e %e \n",t, xs[0], xs[1], xs[2], xs[3], E);
        update(xs);
        t += h;
    }
}
