#include<stdio.h>

#define MAX_LINE 100

int main()
{
    int i, c;
    char s[MAX_LINE];

    for (i = 0; i < MAX_LINE - 1; ++i) {
        if ((c = getchar()) == EOF)
            break;

        if (c == '\n')
            break;

        s[i] = c;
    }

    printf("\n%s\n", s);

    return 0;
}

