#include<stdio.h>

int main() {
    int previous, actual;

    previous = getchar();

    putchar(previous);
    while ((actual = getchar()) != EOF) {
        if (previous == ' ' && actual == ' ') {
            continue;
        }
        putchar(actual);
        previous = actual;
    }

    printf("\n");

    return 0;
}
