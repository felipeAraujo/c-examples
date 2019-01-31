#include<stdio.h>

int fahr2cel(int);

int main() {
	int fahr, cels;
	int steps = 20;
	int lower = 0;
	int upper = 300;

	for(fahr = lower; fahr <= upper; fahr += steps) {
		cels = fahr2cel(fahr);
		
		printf("%d\t%d\n", fahr, cels);
	}

	return 0;
}

int fahr2cel(int fahr)
{
	return 5 * (fahr - 32) / 9;
}

