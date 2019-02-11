#include<stdio.h>
#include<limits.h>

int main()
{
    printf("int limits: %d <=> %d\n", INT_MAX, INT_MIN);
    printf("char limits: %d <=> %d\n", CHAR_MAX, CHAR_MIN);
    printf("long limits: %ld <=> %ld\n", LONG_MAX, LONG_MIN);
    printf("signed char limits: %d <=> %d\n", SCHAR_MAX, SCHAR_MIN);
    printf("short limits: %d <=> %d\n", SHRT_MAX, SHRT_MIN);
    printf("signed char limits: %d <=> %d\n", SCHAR_MAX, SCHAR_MIN);
    printf("unsigned char max: %d\n", UCHAR_MAX);
    printf("unsigned int max: %u\n", UINT_MAX);
    printf("unsigned long max %lu\n", ULONG_MAX);

    printf("unsigned short max %d\n", USHRT_MAX);

    return 0;
}

