#include<stdio.h>

void expand(char[], char[]);

int main()
{

    return 0;
}

void expand(char s1[], char s2[])
{
    char range1, range2, prev, current;
    int slen = strlen(s1);
    int i;
    int j = 0;

    range1 = '\0';
    prev = '\0';
    range2 = '\0';
    for (i = 0; i < slen - 1, ++i) {
        if(s1[i+1] != '-' && s1[i] != '-')
            s2[j++] = s1[i];
        else if (s1[i+1] == '-' && s1[i] != '-')
            range1 = s1[i];
        else if (s1[i] == '-' && s1[i+1] != '-') {
            range2 = s1[i+1];
            if (range2 > range1) {
                int temp = range1;
                range1 = range2;
                range2 = temp;
            }

            while (range1 <= range2)
                s2[j++] = range1++;

            range1 = '\0';
            range2 = '\0';
            ++i;
        } 
    }
}
