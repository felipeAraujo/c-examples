#include<stdio.h>

int htoi(char[]);

int main() {
    char t[] = "0xF";
    char t2[] = "0XfF";
    char t3[] = "fabc123";

    printf("%d\n%d\n%d\n", htoi(t), htoi(t2), htoi(t3));

    return 0;
}

int htoi(char s[])
{
    int i = 0;
    int sum = 0;
    char c;

    if (s[0] == '\0')
        return 0;

    if (s[0] == '0')
        i = 1;

    if (s[i] == '\0')
        return 0;

    if(s[i] == 'x' || s[i] == 'X')
        i = 2;

    while((c = s[i++]) != '\0')
    {
        switch (c) {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                sum = sum*16 + (c - '0');
                break;
            case 'A':
            case 'B':
            case 'C':
            case 'D':
            case 'E':
            case 'F':
                sum = sum*16 + (c - 'A' + 10);
                break;
            case 'a':
            case 'b':
            case 'c':
            case 'd':
            case 'e':
            case 'f':
                sum = sum*16 + (c - 'a' + 10);
                break;
        }
    }

    return sum;
}

