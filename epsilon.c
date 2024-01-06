#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>


//global declarations

char a[10][10], f[10];
int n, m=0, i, j,z;

void epsilon(char c){

    for(i=0; i<n; i++){
        if(a[i][0] == c && a[i][1] == 'e'){
            f[m++] = a[i][2];
            epsilon(a[i][2]);
        }
    }
}

// main function

int main(){
    char c,ch;
    printf("\nEnter the number of transition: ");
    scanf("%d", &n);
    printf("\nEnter the transitions: ");
    for(i=0; i<n; i++){
        scanf("%s%c",a[i],&ch); // reading this space is important as it makes each transitions seperate, else it would be just a long string
    }
    do{
        m = 0;
        printf("\nEnter the character to find the epsilon closure:\n");
        scanf("%c", &c);
        epsilon(c);
        printf("\nThe epsilon closure is: { %c ",c);
        for(i=0; i<m; i++){
            printf(" %c ",f[i]);
        }
        printf("}");
        printf("\nDo you want to continue? [1/0]: "); 
        scanf("%d%c",&z,&ch);

    }while(z==1);

    return 0;
}

