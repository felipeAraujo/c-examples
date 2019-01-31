#include<stdio.h>

#define LENGTHUNTIL 10

int main() {
	int c, i, j, nother, counter;
	int frequencies[LENGTHUNTIL+1];

	nother = 0;
	for (i = 0; i < LENGTHUNTIL; ++i)
		frequencies[i] = 0;

	counter = 0;
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n'|| c == '\t') {
			if (counter > LENGTHUNTIL)
				++nother;
			else
				++frequencies[counter];

			counter = 0;
		}

		++counter;
	}

	printf("\n");
	for (i = 0; i <= LENGTHUNTIL; ++i) {
		printf("%d:\t", i);
		for (j = 0; j < frequencies[i]; ++j)
			printf("=");
		printf("\n");
	}
	
	printf("ot:\t");
	for (i = 0; i < nother; ++i)
		printf("=");
	printf("\n");
		
	return 0;
}
