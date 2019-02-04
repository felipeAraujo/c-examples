#include<stdio.h>

#define OUTEVERYTHING 0
#define INCOMMENT 1
#define INCOMMENTCOMPLEX 2
#define INSTRINGSIMPLE 3
#define INSTRINGDOUBLE 4

int main() {
    int c;
    int stateC

    while ((c = getchar()) != EOF) {

    }
}

char handleInComment() {
    while ((c = getchar()) != '\n')
        if (c == EOF)
            return EOF;

    return '\n';
}

char handleInCommentComplex()
{

    int stateFirstToFinish = 0;
    while((c = getchar()) != EOF) {
        if (c == '*')
            stateFirstToFinish = 1;

        if (stateFirstToFinish && c == '/')
            return ' ';

        if (stateFirstToFinish && c != '/')
            stateFirstToFinish = 0;
    }

    return EOF;
}

int handleInString(char commentString)
{
    while ((c = getchar()) != EOF)
    {
    }

    return EOF;
}
