%{
	#include<stdio.h>
	#include<stdlib.h>
	int yylex();
	int yyerror(char* s);
%}

%token NUMBER ALPHA
%left '+' '-'
%left '*' '/'

%%
	grammar: expr '\n' {printf("valid");exit(0);}
	
	expr: expr '+' expr
	      
	    | expr '-' expr
	    | expr '*' expr
	    | expr '/' expr
	    | NUMBER
	    |ALPHA
	    ;
%%

int main(){
	printf("Enter expression: ");
	yyparse();
	return 0;
}
yyerror(char *s){
	printf("Invalid");
	exit(0);
}
