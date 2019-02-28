#include<stdio.h>


/*
 * x &= (x-1) => x = x & (x-1);
 * if x ends in 1, all the bit's going
 * to be the same as x except the last one
 * that ends in 0
 *
 *   x-x-x-...-1 (x)
 *  &x-x-x-...-0 (x-1)
 *  -------------
 *   x-x-x-...-0
 *
 * if x ends in 0, the last rightmost bit 1
 * will became 0 and the 0's after will be
 * kept
 *
 *   x-x-x-1-0-...-0 (x)
 *  &x-x-x-0-1-....1 (x-1)
 *  -----------------
 *   x-x-x-0-0-...-0
 * */

int bitcount(unsigned x);

int main()
{
    int test = 256u;

    printf(
        "number: %d\nbitcount:%d\n",
        test,
        bitcount(test)
    );

    return 0;
}

int bitcount(unsigned x)
{
    int c = 0;
    while (x != 0u) {
        ++c;
        x &= x-1;
    }
    
    return c;
}


