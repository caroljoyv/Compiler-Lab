%{
	#include<stdio.h>
	#include"y.tab.h"
%}
%%
	"if"    {return IF;}
	"else"  {return ELSE;}
	">"	{return G;}
	">="	{return GE;}
	"<"	{return L;}
	"<="	{return LE;}
	"=="	{return E;}
	"!="	{return	NE;}
	"&&"	{return AND;}
	"||"	{return OR;}
	[=,{}();]	{return yytext*;}
	[\t\n]+	;
	[a-zA-Z][a-zA-Z0-9]*	{return ID;}
	[0-9]+	{return NUM;}	
	.	{return yytext[0];}
%%

int yywrap(){
	return 1;
}
		
