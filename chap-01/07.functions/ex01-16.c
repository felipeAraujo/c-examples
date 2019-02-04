#include<stdio.h>

#define MAXLINE 1000

int getline2(char line[], int lim);
void copy2(char to[], char from[]);

int main()
{
    int len;
    int max;
    int textlength;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    textlength = 0;

    while ((len = getline2(line, MAXLINE)) > 0) {
        printf("len: %d\n", len);
        textlength += len;
        if (len > max) {
            max = len;
            copy2(longest, line);
        }
    }

    if (max > 0)
        printf("%s\n", longest);

    printf("Text Length: %d\n", textlength);

    return 0;
}

int getline2(char line[], int lim)
{
    int i, c;

    for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;

    if (c == '\n') {
        line[i++] = c;
    }

    line[i] = '\0';

    return i;
}

void copy2(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}

