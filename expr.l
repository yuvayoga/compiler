%{
#include "y.tab.h"
#include <stdlib.h>   // for atoi()
%}

%%

[0-9]+      { yylval = atoi(yytext); return NUMBER; }
[\t\n ]+    ;            // Ignore whitespace
"+"         return PLUS;
"-"         return MINUS;
"*"         return MUL;
"/"         return DIV;

.           { printf("Invalid character: %s\n", yytext); }

%%
