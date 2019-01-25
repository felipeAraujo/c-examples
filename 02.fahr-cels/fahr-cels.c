#include<stdio.h>

int main() {
	int fahr, cels;
	int steps = 20;
	int lower = 0;
	int upper = 300;

	for(fahr = lower; fahr <= upper; fahr += steps) {
		cels = 5 * (fahr - 32) / 9;
		
		printf("%d\t%d\n", fahr, cels);
	}

	return 0;
}
