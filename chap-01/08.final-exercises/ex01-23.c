#include<stdio.h>

int checkIfComment(void);
int handleInComment(void);
int handleInCommentComplex(void);
int handleInString(char);

int main() {
    int c;
    int checkChar;

    while ((c = getchar()) != EOF) {
        checkChar = '\0';

        if (c == '/') {
            checkChar = checkIfComment();

            if (checkChar == EOF)
                return 1;
            else if (checkChar == '/')
                checkChar = handleInComment();
            else if (checkChar == '*')
                checkChar = handleInCommentComplex();
            else
                printf("/%c", checkChar);
        } else if (c == '"')
            checkChar = handleInString('"');
        else  if (c == '\'')
            checkChar = handleInString('\'');
        else
            printf("%c", c);


        if (checkChar == EOF)
            return 1;
    }

    return 0;
}

int checkIfComment() {
    return getchar();
}

int handleInComment() {
    int c;
    while ((c = getchar()) != '\n')
        if (c == EOF)
            return EOF;

    return '\n';
}

int handleInCommentComplex()
{
    int stateFirstToFinish = 0;
    int c;
    while((c = getchar()) != EOF) {
        if (c == '*') {
            stateFirstToFinish = 1;
            continue;
        }

        if (stateFirstToFinish && c == '/')
            return '\0';

        if (stateFirstToFinish && c != '/')
            stateFirstToFinish = 0;
    }

    return EOF;
}

int handleInString(char charString)
{
    int statePreviousBackslash = 0;
    int c;

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
            return '\0';
        }

        if (statePreviousBackslash) {
            statePreviousBackslash = 0;
        }

        printf("%c", c);
    }

    return EOF;
}
