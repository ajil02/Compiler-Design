%{
#include <stdio.h>
int cv,cc;
%}

%%
[aeiouAEIOU] {cv++;printf("\n%s is a vowel",yytext);}
[a-zA-Z] {cc++;printf("\n%s is a consonant",yytext);}
[\t\n] ECHO;
%%
int main() 
{
    printf("Enter string:");
    yylex();
    printf("vowel count:%d",cv);
    printf("consonant count:%d",cc);
    return 0;
}

int yywrap()
{
	
	return 1;
}
