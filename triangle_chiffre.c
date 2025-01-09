#include <stdio.h>


int main (){

int n,i,c; 
    
    printf("donner un nombre : ");
    scanf("%d",&n);
    for (i=1; i <= n; i++){
        for (c=1; c <= i; c++){
            printf("%d", i);
        }
        printf("\n");
    }
        

}




