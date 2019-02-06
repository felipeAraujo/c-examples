#include<stdio.h>

#define OUTEVERYTHING 0
#define INSQUOTE 1
#define PREVIOUSBACKSLAHS 2
#define INDQUOTE 3
#define PREVIOUSBACKSLASHD 4
#define FIRSTCOMMENTSTRING 5
#define INCOMMENT 6
#define INSCOMMENT 7
#define FIRSTOUTCOMMENT 8

#define BRACKETERROR 12
#define BRACEERROR 13
#define PARENTHESEERROR 14
#define CODEERROR 15

#define STACKLENGTH 100

int handleOutEverything(int);
int handleInSQuote(int);
int handlePreviousBackslashS(int);
int handleInDQuote(int);
int handlePreviousBackslashD(int);
int handleFirstCommentString(int);
int handleInComment(int);
int handleInSCommemt(int);
int handleFirstOutComment(int);

int handleBrackets(char);
int handleParenthesis(char);
int handleBraces(char);

void putStack(char);
char getStack(void);

int openClose[STACKLENGTH];
int counter = 0;

int main() {
    int state = OUTEVERYTHING;
    int c, i;

    for (i = 0; i < STACKLENGTH; ++i)
        openClose[i] = 0;

    while ((c = getchar()) != EOF) {
        switch(state) {
            case OUTÉVERYTHING:
                state = handleOutEverything(c);
        }
    }

    if (state == OUTEVERYTHING)
        printf("The sintax is correct\n");

    return 0;
}

void putStack(char c)
{
    openClose[counter++] = c;
}

char getStack()
{
    return openClose[--counter];
}

int handleOutEverything(int c)
{
    switch(c) {
        case '"':
            return INDQUOTE;
        case '\'':
            return INSQUOTE;
        case '/':
            return FIRSTCOMMENTSTRING;
        case '[':
        case ']':
            return handleBrackets(c);
        case '{':
        case '}':
            return handleBraces(c);
        case '(':
        case ')':
            return handleParenthesis(c);
        default:
            return OUTEVERYTHING;
    }
}

int handleBrackets(char c)
{
    char fromStack = '\0';
    switch(c) {
        case '[':
            putStack('[');
            return OUTEVERYTHING;
        case ']':
            fromStack = getStack();
        default:
            return CODEERROR;
    }

    if (fromStack == '[')
        return OUTEVERYTHING;
    else
        return BRACKETERROR;
}

int handleBraces(char c)
{
    char fromStack = '\0';
    switch(c) {
        case '{':
            putStack(c);
            return OUTEVERYTHING;
        case '}':
            fromStack = getStack();
        default:
            return CODEERROR;
    }

    if (fromStack == '{')
        return OUTEVERYTHING;
    else
        return BRACERROR;
}

int handleParenthesis(char c)
{
    char fromStack = '\0';
    switch(c) {
        case '(':
            putStack(c);
            return OUTEVERYTHING;
        case ')':
            fromStack = getStack();
        default:
            return CODEERROR;
    }

    if (fromStack == '(')
        return OUTEVERYTHING;
    else
        return PARENTHESEERROR;
}

int handleInDQuote(int c)
{
    switch(c) {
        case '\\':
            return PREVIOUSBACKSLASHD;
        case '"':
            return OUTEVERYTHING;
        default:
            return INDQUOTE;
    }
}

int handlePreviousBackslashD(int c)
{
    return INDQUOTE;
}

int handleInSQuote(int c)
{
    switch(c) {
        case '\\':
            return PREVIOUSBACKSLASHS;
        case '\'':
            return OUTEVERYTHING;
        default:
            return INSQUOTE;
    }
}

int handleFirstCommentString(int c)
{
    switch(c) {
        case '/':
            return INSCOMMENT;
        case '*':
            return INCOMMENT;
        default:
            return OUTEVERYTHING;
    }
}

int handleInSComment(int c)
{
    switch(c) {
        case '\n':
            return OUTEVERYTHING;
        default:
            return INSCOMMENT;
    }
}

int handleInComment(int c)
{
    switch(c) {
        case '*':
            return FIRSTOUTCOMMENT;
        default:
            return INCOMMENT;
    }
}

int handleFirstOutComment(int c)
{
    switch(c) {
    }
}
