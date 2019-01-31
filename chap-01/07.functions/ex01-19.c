#include<stdio.h>

#define MAXLINE 1000

int getline2(char line[], int lim);
void reverse(char line[], int size);

int main()
{
	int len;
	char line[MAXLINE];
	
	while ((len = getline2(line, MAXLINE)) > 1) {
		reverse(line, len);
		printf("%s\n", line);
	}
	printf("\n");

	return 0;
}

int getline2(char line[], int lim)
{
	int i, c;

	i=0;

	while ((c = getchar()) != EOF && c != '\n') {
		line[i++] = c;
	}

	if (c == '\n') {
		line[i++] = c;
	}

	line[i] = '\0';
	
	return i;
}

void reverse(char line[], int size)
{
	int i;
	for (i = 0; i < (size/2); ++i) {
		int temp = line[size - i - 1];
		line[size - i - 1] = line[i];
		line[i] = temp;
	}
}

