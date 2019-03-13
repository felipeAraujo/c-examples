#include<stdio.h>

void expand(char[], char[]);

int main()
{

    return 0;
}

void expand(char s1[], char s2[])
{
    char prev, current;
    int slen = strlen(s1);
    int i;
    int j = 0;

    prev = '\0';
    for (i = 0; i < slen, ++i) {
        current = s1[i];
        if (prev != '\0' && prev != '-')
            s2[j++] = prev;

        prev = current;
    }
}
