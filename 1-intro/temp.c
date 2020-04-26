#include <stdio.h>
#include <string.h>
#define LOWER 0
#define UPPER 300
#define STEP 20
/* print Fahrenheit-Cencius table for
 * fahr = 0, 20, ..., 300 */

int main(int argc, char* argv[]){
    if (argc > 1 && strcmp(argv[1], "fast") == 0 ){
        printf("Fast Mode\n");
        int fahr;
        for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP){
            printf("%3d %6.1f\n", fahr, (5.0)/(9.0) * (fahr - 32));
        }
    } else {
        printf("Not Fast Mode\n");
        float fahr, celsius;
        float lower, upper, step;

        lower = 0;
        upper = 300;
        step = 20;

        fahr = lower;
        while (fahr <= upper) {
            printf("%3.0f\t%6.1f\n", fahr, celsius);
            fahr = fahr + step;
        }
    }
}
