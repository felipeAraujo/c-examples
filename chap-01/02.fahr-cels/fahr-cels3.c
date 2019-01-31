#include<stdio.h>

int main() {
	float fahr, cels;
	int steps = 20;
	int lower = 0;
	int upper = 300;

	for(fahr = lower; fahr <= upper; fahr += steps) {
		cels = 5 * (fahr - 32) / 9;
		
		printf("%3.0f\t%6.1f\n", fahr, cels);
	}

	return 0;
}
