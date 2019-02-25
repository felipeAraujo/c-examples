#include<stdio.h>

int invert(int, unsigned int, unsigned int);
int onlyFirstNBits(int, unsigned int);
int removeFromPBits(int, unsigned, unsigned);
void showBits(int);

int main() {
    int x = 544;
    int p = 7;

    int n  = 4;

    int result = invert(x, p, n);

    printf("x: %d - ", x);
    showBits(x);

    printf("p: %d\n", p);
    printf("n: %d\n", n);

    printf("result: ");
    showBits(result);

    return 0;
}

void showBits(int y)
{
    int n;
    int i;
    for (i = 16; i >= 0; --i)
    {
        int t = 1u << i;
        (y & t) ? printf("1") : printf("0");
    }

    printf("\n");
}

int invert(
    int x,
    unsigned int p,
    unsigned int n
) {
    return
        (onlyFirstNBits(~x >> (p-n), n) << (p-n))
        |
        removeFromPBits(x, p, n);
}

int onlyFirstNBits(int y, unsigned int n)
{
    return (~((~0) << n) & y);
}

int removeFromPBits(int x, unsigned p, unsigned n)
{
    return ((x >> p) << p) | onlyFirstNBits(x, p-n);
}

