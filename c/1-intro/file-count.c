#include <stdio.h>
#include <string.h>
/* count characters in input */
int main(int argc, char *argv[]){
    if (argc <= 1){
        printf("Not Float Mode\n");
        double nc;
        for (nc = 0; getchar() != EOF; ++nc)
            ;
        printf("%.0f\n",nc);
    } else if (strcmp(argv[1],"float") == 0){
        printf("Float Mode\n");
        long nc = 0;
        while(getchar()!=EOF){
            ++nc;
            printf("%ld\n", nc);
         }
    } else if (strcmp(argv[1],"line") ==0) {
        printf("Line Mode\n");
        int c, nl = 0;
        while((c = getchar()) != EOF)
            if (c == '\n')
                ++nl;
        printf("%3d\n",nl);
    }
}
