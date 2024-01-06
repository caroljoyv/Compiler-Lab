//header files
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

//global declarations
char a[10][10], f[10]; 
int n, m=0,i,j,z;


// first function
void first(char c){
    //check if c is a terminal,if so, first is c
    if(islower(c)){
        f[m++] = c;
    }
    for(i=0;i<n;i++){
        if(a[i][0] == c){
            if(islower(a[i][2])){
                f[m++] = a[i][2];
            }
            else{
                first(a[i][2]);
            }
        }
    }
}

//follow function
void follow(char c){
    if(a[0][0] == c){
        f[m++] = '$';
    }
    for(i=0;i<n;i++){
        for(j=0;j<strlen(a[i]);j++){
            if(a[i][j] == c){
                if(a[i][j++] != '\0'){
                    int temp = m;  // if the first set has epsilon in it
                    first(a[i][j++]);
                    for(int k=temp; k<m; k++){
                        if(f[k]=='e'){
                            follow(a[i][0]);
                        }
                    }
                }
                if(a[i][j++] == '\0' && c != a[i][0]){
                    follow(a[i][0]);
                    
                }
            }
        }
    }
}

//main function
int main(){
    char c, ch;
    printf("Enter the number of production rules: \n");
    scanf("%d",&n);
    printf("\nEnter the production rules: \n");
    for(i=0;i<n;i++){
        scanf("%s%c",a[i],&ch);
    }

    do{
        printf("\nEnter the character: ");
        scanf("%c",&c);
        first(c);
        printf("\n First(%c) = { ",c);
        for(i=0;i<m;i++){
            printf( "%c ",f[i]);
        }
        printf("}");

        //clear f[10] and m
        strcpy(f," ");
        m = 0;

        follow(c);
        printf("\n Follow(%c) = {",c);
        for(i=0;i<m;i++){
            printf("%c",f[i]);
        }
        printf("}");
        printf("\nDO you want to continue [1/0]: ");
        scanf("%d%c", &z,&c);

    }while(z == 1);


    return 0;
}