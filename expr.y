%{
#include <stdio.h>
#include <stdlib.h>
%}

%token NUMBER PLUS MINUS MUL DIV

%%
expr: expr PLUS term   { printf("Valid + expression\n"); }
    | expr MINUS term  { printf("Valid - expression\n"); }
    | term
    ;

term: term MUL factor  { printf("Valid * term\n"); }
    | term DIV factor  { printf("Valid / term\n"); }
    | factor
    ;

factor: NUMBER
      ;
%%

int main() {
    printf("Enter an arithmetic expression:\n");
    yyparse();
    return 0;
}

int yyerror(char *msg) {
    fprintf(stderr, "Syntax Error: %s\n", msg);
    return 1;
}
