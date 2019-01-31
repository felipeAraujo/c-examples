#include<stdio.h>

#define TABSIZE 4

void printSpace(int);

int main() {
	int i, c;

	i = 0;
	while((c = getchar()) != EOF ) {
		if (c == '\t') {
			printSpace(TABSIZE - i);
			i = 0;
			continue;
		}
		else
			printf("%c", c);

		i = (i + 1) % TABSIZE;
	}

	printf("\n");

}

void printSpace(int size)
{
	int i;
	for(i= 0; i < size; ++i)
		printf(" ");
}

