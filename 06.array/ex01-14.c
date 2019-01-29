#include<stdio.h>

#define ARRAYSIZE 8
#define HISTLENGTH 3
#define CLUSTER 10

int main() {
	int i, j, c, nother;
	int counter[ARRAYSIZE];

	nother = 0;
	for (i = 0; i < ARRAYSIZE; ++i) 
		counter[i] = 0;

	while ((c = getchar()) != EOF) {
		if (c >= '0')
			++counter[(c-'0')/CLUSTER];
		
	}

	printf("\n");
	for (i = 0; i < ARRAYSIZE; ++i) {
		printf("%c-%c:\t", i*CLUSTER + '0', (i+1)*CLUSTER + '0' - 1);
		int histLength = counter[i]/HISTLENGTH;
		for (j = 0; j < histLength; ++j)
			printf("=");
		printf("\n");
	}
}
