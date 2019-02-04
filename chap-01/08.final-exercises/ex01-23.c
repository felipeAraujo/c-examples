#include<stdio.h>

char checkIfComment(void);
char handleInComment(void);
char handleInCommentComplex(void);
char handleInString(char);

int main() {
    int c;

    while ((c = getchar()) != EOF) {
        char checkChar = '';

        if (c == '/') {
            checkChar = checkIfComment();

            if (checkChar == EOF)
                return 1;
            else if (checkChar == '/')
                checkChar = handleInComment();
            else if (checkChar == '*')
                checkChar = handleInCommentComplex();
            else {
                printf("/%c", checkChar);
            }

            if (checkChar == EOF)
                return 1;

            continue;
        }

        if (c == '"')
            checkChar = handleInString('"');

        if (c == '\'')
            checkChar = handleInString('\'');

        if (checkChar == EOF)
            return 1;
    }

    return 0;
}

char checkIfComment() {
    return getchar();
}

char handleInComment() {
    while ((c = getchar()) != '\n')
        if (c == EOF)
            return EOF;

    return '\n';
}

char handleInCommentComplex()
{
    int stateFirstToFinish = 0;
    while((c = getchar()) != EOF) {
        if (c == '*')
            stateFirstToFinish = 1;

        if (stateFirstToFinish && c == '/')
            return ' ';

        if (stateFirstToFinish && c != '/')
            stateFirstToFinish = 0;
    }

    return EOF;
}

char handleInString(char charString)
{
    int statePreviousBackslash = 0;

    printf("%c", charString);

    while ((c = getchar()) != EOF)
    {
        if (c == '\\' && !statePreviousBackslash) {
            printf("%c", c);
            statePreviousBackslash = 1;
            continue;
        }

        if (c == charString && !statePreviousBackslash) {
            printf("%c", c);
            return '';
        }

        if (statePreviousBackslash) {
            statePreviousBackslash = 0;
        }

        printf("%c", c);
    }

    return EOF;
}
