#include<stdio.h>

#define MAXLINE 1000

int getline2(char line[], int lim);
void copy2(char to[], char from[]);

int main()
{
    int len;
    char line[MAXLINE];

    while ((len = getline2(line, MAXLINE)) > 1) {
        printf("%s", line);
    }

    return 0;
}

int getline2(char line[], int lim)
{
    int i, c;

    i=0;

    while ((c = getchar()) != EOF && c != '\n') {
        if (c == ' ' || c == '\t')
            continue;

        line[i++] = c;
    }

    if (c == '\n') {
        line[i] = '\n';
    }
    line[++i] = '\0';

    return i;
}

