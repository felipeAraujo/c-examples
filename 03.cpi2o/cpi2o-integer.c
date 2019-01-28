#include<stdio.h>

int main() {
	int c;

	c = getchar();
	while (c != EOF) {
		c = getchar();
		printf("%d\n", c);
	}

	printf("\n");
}
