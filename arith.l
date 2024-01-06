%{
	#include "y.tab.c"
%}

%%
	[a-zA-Z]  {return ALPHA;}
	[0-9]+   { return NUMBER; }
	[\t] ;
	[\n]  {return '\n';}
	.  {return yytext[0];}
%%
	
