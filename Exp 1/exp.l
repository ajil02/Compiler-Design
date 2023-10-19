%{
	#include "y.tab.h"
	extern yyval;
%}

%%
[0-9]+ {yyval=atoi(yytext);return NUMBER;}
[a-zA-Z]+ {return ID;}
[\t]+ ;

%%
