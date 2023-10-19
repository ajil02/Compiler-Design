%{ 
#include<stdio.h>
#include<stdlib.h>
int yyerror();
int yyparse();
int yylex();
%} 
%token LET DIG 
%% 
	variable:var
	; 
	var:var DIG 
	|var LET 
	|LET 
	; 
%% 
int main()
{
	printf("Enter identifier: ");
	yyparse();
	printf("Valid Variable \n");
	return 0; 
}
int yyerror()
{ 
	printf("Invalid Variable \n"); 
	exit(0); 
} 
