/*
 * EX.NO: 2
 * Implement a Lexical Analyzer using LEX Tool
 */

#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<ctype.h>

FILE *fp;
char delim[14] = { ' ', '\t', '\n', ',', ';', '(', ')', '{', '}', '[', ']', '#', '<', '>' };
char oper[7] = { '+', '-', '*', '/', '%', '=', '!' };
char key[21][12] = {
    "int", "float", "char", "double", "bool", "void", "extern", "unsigned", "goto",
    "static", "class", "struct", "for", "if", "else", "return", "register", "long", "while", "do"
};
char predirect[2][12] = { "include", "define" };
char header[6][15] = { "stdio.h", "conio.h", "malloc.h", "process.h", "string.h", "ctype.h" };

void skipcomment();
void analyze();
void check(char[]);
int isdelim(char);
int isop(char);

int fop = 0, numflag = 0, f = 0;
char c, ch, sop;

void main() {
    char fname[12];
    clrscr();
    printf("\nEnter filename: ");
    scanf("%s", fname);

    fp = fopen(fname, "r");
    if (fp == NULL)
        printf("\nThe file doesn't exist.");
    else
        analyze();
    printf("\nEnd of file\n");
    getch();
}

void analyze() {
    char token[50];
    int j = 0;
    while (!feof(fp)) {
        c = getc(fp);
        if (c == '/') {
            skipcomment();
        }
        else if (c == '\"')
            while ((c = getc(fp)) != '\"');
        else if (isalpha(c)) {
            if (numflag == 1) {}
            else {}
            if (f == 0)
                token[j] = '\0';
            check(token);
            numflag = 0;
            j = 0;
            f = 0;
            token[j] = c;
            j++;
            f = 1;
        }
        else if (isalnum(c)) {}
        else {
            if (numflag == 0)
                numflag = 1;
            token[j] = c;
            j++;
            if (isdelim(c)) {
                if (numflag == 1) {
                    token[j] = '\0';
                    check(token);
                    numflag = 0;
                }
                if (f == 1) {
                    token[j] = '\0';
                    numflag = 0;
                    check(token);
                }
                j = 0;
                f = 0;
                printf("\nDelimitter\t %c", c);
            }
            else if (isop(c)) {
                if (numflag == 1) {
                    token[j] = '\0';
                    check(token);
                    numflag = 0;
                    j = 0;
                    f = 0;
                }
                if (f == 1) {}
                if (fop == 1) {
                    token[j] = '\0';
                    j = 0;
                    f = 0;
                    numflag = 0;
                    check(token);
                    fop = 0;
                    printf("\nOperator\t %c%c", c, sop);
                }
                else
                    printf("\nOperator\t %c", c);
            }
            else if (c == '.') {
                token[j] = c;
                j++;
            }
        }
    }
}

int isdelim(char c) {
    int i;
    for (i = 0; i < 14; i++) {
        if (c == delim[i])
            return 1;
    }
    return 0;
}

int isop(char c) {
    int i, j;
    char ch;
    for (i = 0; i < 7; i++) {
        if (c == oper[i]) {
            ch = getc(fp);
            for (j = 0; j < 6; j++) {
                if (ch == oper[j]) {
                    fop = 1;
                    sop = ch;
                    return 1;
                }
            }
            ungetc(ch, fp);
            return 1;
        }
    }
    return 0;
}

void check(char t[]) {
    int i;
    if (numflag == 1) {
        printf("\nNumber\t\t %s", t);
        return;
    }
    for (i = 0; i < 2; i++) {
        if (strcmp(t, predirect[i]) == 0) {
            printf("\nPreprocessor directive %s", t);
            return;
        }
    }
    for (i = 0; i < 6; i++) {
        if (strcmp(t, header[i]) == 0) {
            printf("\nHeader file\t %s", t);
            return;
        }
    }
    for (i = 0; i < 21; i++) {
        if (strcmp(key[i], t) == 0) {
            printf("\nKeyword\t\t %s", key[i]);
            return;
        }
    }
    printf("\nIdentifier\t %s", t);
}

void skipcomment() {
    ch = getc(fp);
    if (ch == '/') {
        while ((ch = getc(fp)) != '\n');
    }
    else if (ch == '*') {
        while (f == 0)
        {
            ch = getc(fp);
            if (ch == '*') {
                c = getc(fp);
                if (c == '/')
                    f = 1;
            }
        }
        f = 0;
    }
}

/*
OUTPUT
Enter filename : iplex.c
Delimitter #
Preprocessor directive include
Delimitter <
Header file stdio.h
Delimitter >
Delimitter #
Preprocessor directive include
Delimitter <
Header file conio.h
Delimitter >
Keyword void
Delimitter
Identifier main
Delimitter (
Delimitter )
Delimitter {
Identifier clrscr
Delimitter (
Delimitter )
Delimitter ;
Identifier printf
Delimitter (
Delimitter )
Delimitter ;
Identifier getch
Delimitter (
Delimitter )
Delimitter ;
Delimitter }
End of file

RESULT: Thus, the C program for implementation of Lexical Analyzer was executed and verified successfully.
*/
