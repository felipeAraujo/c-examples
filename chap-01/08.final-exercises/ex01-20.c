#include<stdio.h>

#define TABSIZE 4

void printSpace(int);

int main() {
    int i, c;

    while((c = getchar()) != EOF)
        if (c == '\t')
            printSpace(TABSIZE);
        else
            printf("%c", c);

    printf("\n");

}

void printSpace(int size)
{
    int i;
    for(i= 0; i < size; ++i)
        printf(" ");
}

