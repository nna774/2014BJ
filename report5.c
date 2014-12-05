#include <stdio.h>

typedef _Bool bool;

bool map(bool before, bool current, bool after){
    int val = (before << 2) + (current << 1) + after;
    static bool const table[] = {0, 1, 0, 1, 1, 0, 1, 0};
    return table[val];
}

int main(){
    int const WIDTH = 127;
    int const STEP_MAX = 128;
    bool table[WIDTH];
    bool buff[WIDTH];

    for(int i = 0; i < WIDTH; ++i) table[i] = 0;

    table[WIDTH/2 - 1] = 1;
    table[WIDTH/2] = 1;
    for(int step = 0; step < STEP_MAX; ++step){
        for(int i = 0; i < WIDTH; ++i) buff[i] = table[i];
        for(int i = 0; i < WIDTH; ++i){
            if(i == 0){
                table[0] = map(buff[WIDTH - 1], buff[0], buff[1]);
            } else if(i == WIDTH - 1){
                table[WIDTH - 1] = map(buff[WIDTH - 2], buff[WIDTH - 1], buff[0]);
            } else{
                table[i] = map(buff[i - 1], buff[i], buff[i + 1]);
            }
            printf("%d %d %d\n", i, step, table[i]);
        }
         puts("");
    }
    return 0;
}
