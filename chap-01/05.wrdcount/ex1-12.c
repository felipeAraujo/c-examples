#include<stdio.h>

#define IN 0
#define OUT 1

int main() {
    int state, isWordOut, c;

    state = OUT;

    while ((c = getchar()) != EOF) {

        isWordOut = (c == '\n' || c == ' ' || c == '\t');

        if (isWordOut && state == IN)
            putchar('\n');

        if (isWordOut)
            state = OUT;
        else {
            state = IN;
            putchar(c);
        }
    }

    return 0;
}
