#include <stdio.h>
#define ARR_LEN 10

/* count digits, white space, others */
int main(int argc, char *argv[]) {
    int c, i, nwhite, nother;
    int ndigit[ARR_LEN];

    nwhite = nother = 0;
    for (i=0; i<ARR_LEN; ++i)
        ndigit[i] = 0;

    while((c = getchar()) != EOF){
        if (c >= '0' && c <= '9')
            ++ndigit[c-'0'];
        else if (c == ' ' || c == '\n' || c == '\t')
            ++nwhite;
        else
            ++nother;
    }

    printf("digits =");
    for (i=0; i<ARR_LEN; ++i)
        printf("%3d", ndigit[i]);
    printf(", white space = %d, other = %d\n", nwhite, nother);
}
