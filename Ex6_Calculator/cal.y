/* EX.NO: 6 - Implementation of calculator using LEX and YACC */
%{
#include <ctype.h>
#include <stdio.h>
#define YYSTYPE double
%}
%token NUM
%left '+' '-'
%left '*' '/'
%right UMINUS
%%
Statment: E { printf("Answer: %g \n", $$); }
        | Statment '\n'
        ;

E : E '+' E { $$ = $1 + $3; }
  | E '-' E { $$ = $1 - $3; }
  | E '*' E { $$ = $1 * $3; }
  | E '/' E { $$ = $1 / $3; }
  | NUM
  ;
%%

/*
PROCEDURE:
lex cal.l
yacc cal.y
cc lex.yy.c y.tab.c -o calc
./calc

OUTPUT:
Enter the expression:
2+2
Answer: 4

RESULT: Thus the program for implementing calculator using LEX and YACC was executed and
verified successfully.
*/
