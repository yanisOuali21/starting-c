#include <stdio.h>

int main() {
    int entier = 1;         // Déclaration d'un entier
    int *pointeur = &entier; // Déclaration d'un pointeur pointant vers l'entier

    // Affiche la valeur initiale de l'entier
    printf("Valeur initiale de l'entier : %d\n", entier);

    // Utilise le pointeur pour modifier la valeur de l'entier
    *pointeur = 4;

    // Affiche la valeur de l'entier après modification
    printf("Valeur modifiée de l'entier : %d\n", entier);

    return 0;
}
