#include <stdio.h>
#include <math.h>

int main(){
    int n, i, Fn0 = 0, Fn1 = 1, res=1;
    scanf("%d", &n);
    for(i = 1; i < n; ++i){
        res = Fn1 + Fn0;
        Fn0 = Fn1;
        Fn1 = res;
    }
    printf("F_%d = %d\n", n, res);
    {
        double sqrt5 = sqrt(5);
        int res = (int)((pow((1+sqrt5)/2, n) - pow((1-sqrt5)/2, n)) / sqrt5 + 0.5);
        printf("F_%d = %d\n", n, res);
    }
    return 0;
}
