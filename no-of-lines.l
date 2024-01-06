%{
#include <stdio.h>

int lines = 1;
int words = 0;
int chars = 0;
%}

%%
\n      { lines++;  }
[a-zA-Z]+   { words++; chars += yyleng; }

%%

int main() {
    yylex();
    
    printf("Lines: %d\n", lines);
    printf("Words: %d\n", words);
    printf("Characters: %d\n", chars);

    return 0;
}

