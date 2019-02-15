#include<stdio.h>

int any(char[], char[]);
int cPosition(char, char[]);

int main()
{
    char s1[] = "to remove";

    char s2[] = "er";

    printf("%d\n", any(s1, s2));
}

int any(char s1[], char s2[])
{
    int i;
    int position = -1;

    for (i = 0; s2[i] != '\0'; ++i) {
        int charPos = cPosition(s2[i], s1);
        if(charPos < position || position == -1)
            position = charPos;
    }

    return position;
}

int cPosition(char c, char s[])
{
    char t;
    int i = 0;

    while ((t = s[i++]) != '\0')
        if (t == c)
            return --i;

    return -1;
}

