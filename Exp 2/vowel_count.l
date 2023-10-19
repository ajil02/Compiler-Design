%{ 
#include<stdio.h>
int vcount=0;
int ccount=0;
%}

%%
[aeiouAEIOU] {vcount++; printf("%s is a vowel\n",yytext);}
[a-zA-Z] {ccount++; printf("%s is a consonant\n",yytext);}

"\n" {printf("Vowel count: %d\nConsonant count: %d", vcount,ccount); vcount = 0 ;ccount=0;}
[\t\n];
<<EOF>> {
        return 0; }

%%

int main()
{
	printf("Enter string: ");
	yylex();
	
	
}

int yywrap()
{
	return 1;
}


