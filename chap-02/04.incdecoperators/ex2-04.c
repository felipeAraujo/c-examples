#include<stdio.h>

void squeeze(char[], char[]);
int inString(char, char[]);

int main()
{
    char s1[] = "to remove";

    char s2[] = "eo";

    squeeze(s1, s2);

    printf("%s\n", s1);
}

void squeeze(char s1[], char s2[])
{
    int i, j;

    for (i = j = 0; s1[i] != '\0'; ++i)
        if(!inString(s1[i], s2))
            s1[j++] = s1[i];

    s1[j] = '\0';
}

int inString(char c, char s[])
{
    char t;
    int i = 0;

    while ((t = s[i++]) != '\0')
        if (t == c)
            return 1;

    return 0;
}

