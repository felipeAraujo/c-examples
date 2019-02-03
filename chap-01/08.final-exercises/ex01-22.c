#include<stdio.h>

#define LINESIZE 30

int main() {

    int c, i;

    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            printf("\n");
            i = 0;
            continue;
        }

        if (i == LINESIZE) {
            printf("%c\n", c);
            i = 0;
        }

        int isBlank = (
            c == ' ' ||
             c == '\t'
         );

        if (i == 0 && isBlank)
            continue;

        printf("%c", c);
        ++i;
    }

    return 0;
}

