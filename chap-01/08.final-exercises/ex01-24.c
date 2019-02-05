#include<stdio.h>

#define OUTEVERYTHING 0
#define INSQUOTE 1
#define PREVIOUSBACKSLAHS 2
#define INDQUOTE 3
#define PREVIOUSBACKSLASHD 4
#define INBRACKETS 5
#define FIRSTCOMMENTSTRING 6
#define INCOMMENT 7
#define INSCOMMENT 8
#define FIRSTOUTCOMMENT 9
#define INPARENTHESES 10
#define INBRACES 11

#define OUTBRACKETERROR 12
#define OUTBRACEERROR 13
#define OUTPARENTHESEERROR 14

int handleOutEverything(int);
int handleInSQuote(int);
int handlePreviousBackslashS(int);
int handleInDQuote(int);
int handlePreviousBackslashD(int);
int handleInBrackets(int);
int handleFirstCommentString(int);
int handleInComment(int);
int handleInSCommemt(int);
int handleFirstOutComment(int);
int handleInParentheses(int);
int handleInBraces(int);

int main() {

    int state = OUTEVERYTHING;
    int c;

    while ((c = getchar()) != EOF) {
    }

    if (state == OUTEVERYTHING)
        printf("The sintax is correct\n");

    return 0;
}

int handleOutEvything(int c)
{
    switch(c) {
        case '"':
            return INDQUOTE;
        case '\'':
            return INSQUOTE;
        case '/':
            return FIRSTCOMMENTSTRING;
        case '[':
            return INBRACKETS;
        case ']':
            return OUTBRACKETERROR;
        case '{':
            return INBRACES;
        case '}':
            return OUTBRACEERROR;
        case '(':
            return INPARENTHESES;
        case ')':
            return OUTPARENTHESEERROR;
        default:
            return OUTEVERYTHING;
    }
}
