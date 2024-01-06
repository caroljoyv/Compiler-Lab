#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int i = 0, error = 0;
char input[10];

void E();
void E_dash();
void T();
void T_dash();
void F();
void F_dash();
void P();
void P_dash();
void Z();







int main(){
    printf("\nEnter the expression: ");
    scanf("%s",input);

    // start the parser
    E();

    if(strlen(input)==i && error != 1){
        printf("\nValid string\n");
    }
    else{
        printf("\nInvalid string\n");
    }
    return 0;
}





void E(){
    // E = TE'
    T();
    E_dash();
}

void E_dash(){
    // E' = +TE' | epsilon
    if(input[i] == '+'){
        i++;
        T();
        E_dash();
    }
}

void T(){
    // T = FT'
    F();
    T_dash();
}

void T_dash(){
    // T' = *FT' | epsilon
    if(input[i] == '*'){
        i++;
        F();
        T_dash();
    }
}

void F(){
    // F = PF''
    P();
    F_dash();
}

void F_dash(){
    // F' = -PF' | epsilon
    if(input[i] == '-'){
        i++;
        P();
        F_dash();
    }
}

void P(){
    // P = ZP'
    Z();
    P_dash();
}


void P_dash(){
    // P' = /ZP' | epsilon
    if(input[i] == '/'){
        i++;
        Z();
        P_dash();
    }
}


void Z(){
    //Z = ( E ) | id
    if(input[i] == '('){
        i++;
        E();
        if(input[i] == ')'){
            i++;
        }
        else{
            error = 1;
        }
    }
    else if(isalnum(input[i])){
        i++;
    }
    else{
        error = 1;
    }
}







