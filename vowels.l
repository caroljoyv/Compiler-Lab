%{
#include<stdio.h>
int vowels = 0;
int consonants = 0;
%}

%%
[aeiouAEIOU] {vowels++;}
[a-zA-Z] {consonants ++;}

. 

%%

int main(){
yylex();
printf("\nVowels = %d", vowels);
printf("\nConsonents = %d", consonants);

return 0;
}
