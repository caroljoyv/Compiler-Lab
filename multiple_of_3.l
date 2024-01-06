%{}
#include<stdio.h>
int count = 0;
%}
%%
0 {count++;}
.

%%

int main(){
    yylex();
    if(count%3 ==0){
        printf("Yes");
    }
    else{
        printf("No");
    }
    return 0;
}

int yywrap(){
    return 1;
}