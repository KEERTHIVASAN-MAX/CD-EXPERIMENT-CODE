/* EX.NO: 3 - Recognize a valid arithmetic expression using +, -, *, / */
%{
#include<stdio.h>
%}
%token ID DIG
%left '+' '-'
%left '*' '/'
%right UMINUS
%%
stmt: expn ;
expn: expn '+' expn
    | expn '-' expn
    | expn '*' expn
    | expn '/' expn
    | '-' expn %prec UMINUS
    | '(' expn ')'
    | DIG
    | ID
    ;
%%
int main() {
    printf("Enter the Expression\n");
    yyparse();
    printf("valid Expression\n");
    return 0;
}
int yyerror() {
    printf("Invalid Expression");
    exit(0);
}

/*
PROCEDURE:
lex art_expr.l
yacc -d art_expr.y
gcc lex.yy.c y.tab.c -o art_expr
./art_expr

OUTPUT:
Enter the Expression
a+b*c-d/e
valid Expression

Enter the Expression
a=b
Invalid Expression

RESULT: Thus the program to recognize a valid arithmetic expression that uses operator +, -, * and /
using YACC tool was executed and verified successfully.
*/
