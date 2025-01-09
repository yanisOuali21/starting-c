#include <stdio.h> 

int main (){

    int nbr , totale =1 , i = 1;
    printf("entrez un nombre: ");
    scanf("%d", &nbr);
    while (i <= nbr){
        totale = totale * i;
        i++;
    }
    printf("le resultat est %d ", totale );
    
}
