%{
	#include<stdio.h>
%}
%token IF ELSE G GE L LE NE E AND OR ID NUM

%%
	S: if else {printf("\nVAlid string");} ;
	if: IF '(' cond ')' '{' stmt '}' ;
	else: ELSE '{' stmt '}' | ;
	cond: second | second AND second |second OR second ;
	second: mid|mid relop mid ;
	mid: ID | NUM ;
	relop: L|LE|G|GE|NE|E ;
	stmt: ID stmt  | NUM stmt | ;
%%
	
	



int yyerror(){
	printf("\ninvalid string");
	return 1;
}

int main(){
	printf("Enter a string: \n");
	yyparse();
	return 0;
}
