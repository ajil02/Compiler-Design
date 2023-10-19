%{ 
  #include<stdio.h> 
  void yyerror();
  int yyparse();
  int yylex();
  int flag=0; 
%} 

%token NUMBER 
%left '+' '-'
%left '*' '/' '%'
%left '(' ')'
%% 
  
ArithmeticExpression: E{ printf("\nResult = %d\n", $$); return 0; }; 
 E : E'+'E {$$=$1+$3;}
   |E'-'E {$$=$1-$3;} 
   |E'*'E {$$=$1*$3;} 
   |E'/'E {$$=$1/$3;} 
   |E'%'E {$$=$1%$3;} 
   |'('E')' {$$=$2;} 
   | NUMBER {$$=$1;} 
   ; 
%% 

void main() 
{ 
   printf("Enter expression: "); 
   yyparse(); 
  // if(flag==0) 
   	//printf("Valid Expression\n"); 
} 
  
void yyerror() 
{ 
   //printf("Invalid Expression\n"); 
   flag=1; 
}
