/* EX.NO: 4 - Recognize a valid variable (letter followed by letters/digits) */
%{
#include<stdio.h>
%}
%token LET DIG
%%
variable: var ;
var: var DIG | var LET | LET ;
%%
int main() {
    printf("Enter the variable:\n");
    yyparse();
    printf("Valid variable\n");
    return 0;
}
int yyerror() {
    printf("Invalid variable\n");
    exit(0);
}

/*
PROCEDURE:
lex valvar.l
yacc -d valvar.y
gcc lex.yy.c y.tab.c -o valvar
./valvar

OUTPUT:
Enter the variable: add
Valid variable

Enter the variable: add1
Valid variable

Enter the variable: 1add
Invalid variable

RESULT: Thus the program to recognize a valid variable which starts with a letter followed by any number
of letters or digits using YACC tool was executed and verified successfully.
*/
