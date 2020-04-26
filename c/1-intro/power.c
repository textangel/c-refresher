#include <stdio.h>
int power(int m, int n);

int main(int argc, char *argv[]){
    int i;
    for (i=0;i<10; ++i)
        printf("%2d %d %d\n", i, power(3,i), power(-2,i));
    return 0;
}

int power(int base, int n){
    int i, p;
    p=1;
    for(i=1; i<=n; ++i)
        p = p*base;
    return p;
}
