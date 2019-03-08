#include<stdio.h>

#define MAX_LENGTH 1000

void scape(char[], char[]);

int main() {
    int c;
    int i = 0;
    char s[MAX_LENGTH];
    char t[MAX_LENGTH];

    while ((c = getchar()) != EOF) {
        t[i++] = c;
    }
    t[i++] = '\0';

    scape(s, t);

    printf("\nResult:\n");

    printf("%s\n", s);

    return 0;
}

void scape(char s[], char t[])
{
    char c;
    int i = 0;
    int j = 0;

    while ((c = t[i++]) != '\0') {
        switch (c) {
            case '\n':
                s[j++] = '\\';
                s[j++] = 'n';
                break;
            case '\t':
                s[j++] = '\\';
                s[j++] = 't';
                break;
            default :
                s[j++] = c;
                break;
        }
    }
}
