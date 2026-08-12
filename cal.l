/* EX.NO: 6 - Implementation of calculator using LEX and YACC */
DIGIT [0-9]+
%option noyywrap
%%
{DIGIT} { yylval = atof(yytext); return NUM; }
\n|.    { return yytext[0]; }
%%
