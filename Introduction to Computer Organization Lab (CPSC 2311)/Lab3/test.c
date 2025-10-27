#include <stdio.h>

int f(int, int *, int **);

int main(){
    int c, *b, **a;
    c = 16;
    b = &c;
    a = &b;
    printf("%d\n", f(c, b, a));
    return 0;
}

int f(int x, int *py, int **ppz){
    int y, z, i;
    (*(*ppz)) += 7;
    z = **ppz;
    *py += 12;
    y = *py;
    for(i = 0; i < 3; i++){
        x += 8;
        printf("%d\n", x);
    }
    return x + y + z;
}