#include <stdio.h>


int main(){
    int tab[10]; 
    int nbr;
    int i;
    int compteur = 0 ;

    

    printf("Entrez 10 nombres :\n");
    for (i = 0; i < 10; i++) {
        scanf("%d", &tab[i]);
    }

    printf("donne un nombre a rechercher");
    scanf("%d", &nbr);
    
    for (i = 0; i < 10; i++) {
        if (tab[i] == nbr) {
            compteur +=1;
    }
    }
    printf("le nombre d apparition est de %d", compteur );

}