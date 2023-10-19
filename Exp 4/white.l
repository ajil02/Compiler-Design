%{
#include <stdio.h>
%}
%option noyywrap
%%
"/*"([^*]|[\r\n]|(\*+([^*/]|[\r\n])))*\*+"/"   { /* Ignore multi-line comments */ }
"//"(.*)[\r\n]   { /* Ignore single-line comments */ }
[ \t]+   { /* Ignore white space */ }
.   { printf("%c", yytext[0]); }
%%

int main() {
    yyin = fopen("lex.txt", "r"); // Replace "input.txt" with the actual file name
    yylex();
    fclose(yyin);
    return 0;
}

