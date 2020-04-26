#include <stdio.h>
#define MAXLINE 1000

int max; //maximum length seen so far
char line[MAXLINE]; //current input line
char longest[MAXLINE]; //longest line saved here

int getNextLine(void);
void copy(void);

int main(int argc, char *argv[]){
    int len;
    extern int max;
    extern char longest[];


    max=0;
    while((len = getNextLine()) > 0) {
        if (len > max) {
            max = len;
            copy();
        }
    }
    if (max > 0)
        printf("%s", longest);
    return 0;
}

int getNextLine(){
    int c,i;
    extern char line[];

    for (i=0; i< MAXLINE-1 && (c=getchar()) != EOF && c!='\n'; ++i)
        line[i] = c;
    if (c == '\n'){
        line[i] = c;
        ++i;
    }
    line[i]='\0';
    return i;
}

void copy(void){
    extern char line[], longest[];
    int i=0;
    while((longest[i] = line[i]) != '\0')
        ++i;
}
