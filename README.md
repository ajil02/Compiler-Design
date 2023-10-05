# Compiler-Design

%{
	#include<stdio.h>
%}
%token NUMBER ID
%left '+' '-'
%left '*' '/'
%%
E:T{printf("Result=%d\n",$$);return 0;}
T:T'+'T{$$=$1'+'$3;}
 |T'*'T{$$=$1'*'$3;}
 |T'-'T{$$=$1'-'$3;}
 |T'/'T{$$=$1'/'$3;}
 |'-'NUMBER{$$= -$2}
 |'('T')'{$$=$2;}
 |ID{$$=$1;}
 ;
%%
 
