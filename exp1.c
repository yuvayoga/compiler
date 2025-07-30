%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100
char *symbol_table[MAX];
int symbol_count = 0;
int search_symbol(char *name) {
    for(int i = 0; i < symbol_count; i++) {
        if(strcmp(symbol_table[i], name) == 0)
            return 1;
    }
    return 0;
}
void add_symbol(char *name) {
    if(!search_symbol(name)) {
        symbol_table[symbol_count++] = strdup(name);
    }
}
%}
IDENTIFIER [a-zA-Z_][a-zA-Z0-9_]*
NUMBER [0-9]+
OPERATOR [\+\-\*/=<>!]+
COMMENT1 "//".*
COMMENT2 "/"([^]|\+[^/])\+"/"
%%
{IDENTIFIER} {
    printf("Identifier: %s\n", yytext);
    add_symbol(yytext);
}
{NUMBER} {
    printf("Constant: %s\n", yytext);
}
{COMMENT1} {
    printf("Single-line Comment: %s\n", yytext);
}
{COMMENT2} {
    printf("Multi-line Comment: %s\n", yytext);
}
{OPERATOR} {
    printf("Operator: %s\n", yytext);
}
[\t\n ]+ ; // Ignore whitespace
. {
    printf("Unknown token: %s\n", yytext);
}
%%
int main(int argc, char **argv) {
    yylex();
    printf("\n--- Symbol Table ---\n");
    for(int i = 0; i < symbol_count; i++) {
        printf("%d: %s\n", i+1, symbol_table[i]);
    }
    return 0;
}
int yywrap() {
    return 1;
}