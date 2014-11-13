#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c, D, x_1, x_2, real, im;
    puts("input a,b,c");
    scanf("%lf%lf%lf", &a, &b, &c);

    /* printf("%lf%lf%lf", a, b, c); */

    if(a == 0) {
        if(b == 0) {
            if(c != 0) {
                puts("no solution.");
            } else {
                puts("any x is satisfiable.");
            }
        } else {
            printf("%e is only solution.\n", - (c / b));
        }
    } else {
        D = b * b - 4 * a * c;
        if(D == 0) {
            printf("%e is only solution.\n", - (b / (2 * a)));
        } else if (D > 0) {
            puts("there is two solutions.");
            x_1 = (-b + sqrt(D)) / (2 * a);
            x_2 = (-b - sqrt(D)) / (2 * a);
            printf("one is %e, the other is %e.\n", x_1, x_2);
        } else {
            puts("there is two solutions.");
            real = -b / (2 * a);
            im = sqrt(-D) / (2 * a);
            printf("%e \\pm \\sqrt(-1) * %e\n", real, im);
        }
    }
    return 0;
}
