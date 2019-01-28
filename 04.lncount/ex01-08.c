#include<stdio.h>

int main() {
	long n1 = 0;
	int c = 0;

	while ((c = getchar()) != EOF)
		if (c == '\n' || c == '\t' || c == ' ')
			++n1;

	printf("\n%ld\n", n1);
	
	return 0;
}
