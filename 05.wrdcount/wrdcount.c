#include<stdio.h>

#define IN 0
#define OUT 1

int main() {
	int c, nl, nw, nc, state;

	state = OUT;

	nl = nw = nc = 0;

	while ((c = getchar()) != EOF) {
		++nc;

		if (c == '\n')
			++nl;
		
		if (c == '\n' || c == ' ' || c == '\t')
			state = OUT;
		else if(state == OUT) {
			++nw;
			state = IN;
		}
	}

	printf("\ncharacter: %d\n", nc);
	printf("word: %d\n", nw);
	printf("line: %d\n", nl);

	return 0;
}
