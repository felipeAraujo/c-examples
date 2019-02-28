#include<stdio.h>

void toLower(char[]);

int main()
{
    char test[] = "EveRyThing 7o LOWer";

    toLower(test);

    printf("Result: %s\n", test);
}

void toLower(char phrase[])
{
    int i;
    for (i = 0; phrase[i] != '\0'; ++i) {
        phrase[i] = (phrase[i] >= 'A' && phrase[i] <= 'Z') ? (phrase[i] - 'A' + 'a') : phrase[i];
    }
}
