#include <stdio.h>
#include <stdlib.h>

static int    const N = 777;
static double const a = 123456789012345.;

int main() {
    FILE *fp;
    fp = fopen("file", "w");
    if(!fp) {
        puts("open error");
        exit(-1);
    }

    fprintf(fp, "%d %e\n", N, a);
    fprintf(fp, "%d %21.14e\n", N, a);
    fclose(fp);
    return 0;
}
