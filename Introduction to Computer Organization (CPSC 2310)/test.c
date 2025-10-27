#include <stdio.h>
int f(int , int *, int **);
int main(){
    int c, *b, **a;
    c = 18;
    b = &c;
    a = &b;
    printf("%d \n", f(c, b, a));
    return 0;
}
int f(int x, int *py, int **ppz){
    int y, z;
    (*(*ppz)) += 3;
    z = **ppz;
    printf("%d\n", z);

    printf("%d\n", *py);
    *py += 9;
    y = *py;
    printf("%d\n", y);

    x += 5;
    printf("%d\n", x);
    return x + y + z;
}