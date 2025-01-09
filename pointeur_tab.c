#include <stdio.h>

int main() {
    int tableau[5] = {10, 20, 30, 40, 50}; // Déclaration et initialisation d'un tableau de 5 entiers
    int *pointeur = tableau;              // Le pointeur pointe sur le premier élément du tableau

    // Affiche chaque élément du tableau en utilisant le pointeur
    printf("Les éléments du tableau sont :\n");
    for (int i = 0; i < 5; i++) {
        printf("Élément %d : %d\n", i + 1, *(pointeur + i)); // Accès via le pointeur
    }

    return 0;
}
