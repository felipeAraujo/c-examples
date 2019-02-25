#include<stdio.h>

int setbits(int, unsigned int, unsigned int, int);
int onlyFirstNBits(int, unsigned int);
int removeFromPBits(int, unsigned, unsigned);
void showBits(int);

int main() {
    int x = 544;
    int y = 678;
    int p = 9;

    int n  = 3;

    int result = setbits(x, p, n, y);

    printf("x: %d - ", x);
    showBits(x);

    printf("y: %d - ", y);
    showBits(y);

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

int setbits(
    int x,
    unsigned int p,
    unsigned int n,
    int y
) {
    return
        (onlyFirstNBits(y, n) << (p-n))
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

