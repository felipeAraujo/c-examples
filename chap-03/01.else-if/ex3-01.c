#include<stdio.h>

int binsearch(int, int[], int);

int main()
{
    int v[] = {1, 2, 3, 4, 5, 6, 7};

    printf("Location: %d\n", binsearch(8, v, 6));

    return 0;
}

int binsearch(int x, int v[], int n)
{
    int low, high, mid, prev;

    low = 0;
    high = n;
    prev = 0;

    while (low < high) {
        mid = (low + high) / 2;

        if (v[mid] <= x)
            low = mid;
        else
            high = mid;

        if (prev == mid)
            break;

        prev = mid;
    }

    if (v[low] == x)
        return low;

    return -1;
}

