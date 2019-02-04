#include<stdio.h>

int main() {
    float fahr, cels;
    int steps = 20;
    int lower = 0;
    int upper = 300;

    printf("Celsius\t\tFahrenheint\n");

    for(cels = lower; cels <= upper; cels += steps) {
        fahr = cels*9/5 +32;

        printf("%3.0f\t\t%6.1f\n", cels, fahr);
    }

    return 0;
}
