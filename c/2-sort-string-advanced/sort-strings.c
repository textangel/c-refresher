#include <stdio.h>
#include <string.h>
#define MAXLINES 5000

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void qsort(char *lineptr[], int left, int right);

/* sort input lines */
int main(int argc, char *argv[]){
    int nlines;

    if ((nlines = readlines(lineptr, MAXLINES))>0){
        qsort(lineptr, 0, nlines-1);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("Error: input is too long to sort\n");
        return 1;
    }
}

#define MAXLEN 1000
int getNewLine(char *, int);
char *alloc(int);

/*readlines: read input lines*/
int readlines(char * lineptr[], int maxlines){
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len = getNewLine(line, MAXLEN)) > 0){
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;
        else {
            line[len-1] = '\0'; /* remove newline */
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    }
    return nlines;
}

void writelines(char *lineptr[], int nlines){
    for (int i = 0; i < nlines; i++){
        printf("%s\n", lineptr[i]);
    }
}

/* qsort: */
void qsort(char *v[], int left, int right) {
    int i, last;
    void swap(char *v[], int i, int j);
    if (left >= right) /* do nothign if array contains */
        return;
    swap(v, left, (left+ right)/2);
    last = left;
    for (i = left + 1; i<=right; i++){
        if (strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);
    }
    swap(v, left, last);
    qsort(v, left, last-1);
    qsort(v, last+1, right);
}

void swap(char *v[], int i, int j) {
    char *temp;

    temp=v[i];
    v[i] = v[j];
    v[j] = temp;
}

/*alloc*/

#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE]; /*storage ofr alloc*/
static char *allocp = allocbuf; /*next free position */

char *alloc(int n){
    if (allocbuf + ALLOCSIZE - allocp >= n) { //it fits
        allocp += n;
        return allocp -n; // old p

    } else { //not enough room
        return NULL;
    }
}

void afree(char *p){ /* free storage pointed to by  p*/
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
        allocp = p;
}

/*getNewLine*/

int getNewLine(char s[], int lim){
    int c,i;
    for (i=0; i< lim-1 && (c=getchar()) != EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n'){
        s[i] = c;
        ++i;
    }
    s[i]='\0';
    return i;
}
