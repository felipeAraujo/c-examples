#include<stdio.h>

int rightrot(unsigned int, unsigned int);
int onlyFirstNBits(int, unsigned int);
int removeFromPBits(int, unsigned, unsigned);
void showBits(int);

int main() {
    int x = 544;
    int n  = 15;

    int result = rightrot(x, n);

    printf("x: %d - ", x);
    showBits(x);

    printf("n: %d\n", n);

    printf("result: ");
    showBits(result);

    return 0;
}

void showBits(int y)
{
    int n;
    int i;
    for (i = (sizeof(int) * 8) - 1; i >= 0; --i)
    {
        int t = 1u << i;
        (y & t) ? printf("1") : printf("0");
    }

    printf("\n");
}

int rightrot(
    unsigned int x,
    unsigned int n
) {
    int i;
    int left1 = ~((~0u) >> 1);

    for (i = 0; i < n; ++i) {
        int isOne = x & 1u;
        x = x >> 1;
        if (isOne)
            x = x | left1;
    }

    return x;
}

