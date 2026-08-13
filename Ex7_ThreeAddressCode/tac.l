/* EX.NO: 7 - Generate three address code for a simple program using LEX and YACC */
%{
#include "y.tab.h"
%}
%%
[a-zA-Z][a-zA-Z0-9]* { yylval.str = strdup(yytext); return ID; }
[0-9]+                { yylval.str = strdup(yytext); return NUM; }
[\t\n ]+               { /* skip spaces */ }
.                      { return yytext[0]; }
%%
int yywrap() {
    return 1;
}
