#include <stdio.h>

int main() {
    // Déclaration et initialisation du tableau de 8 entiers
    int tableau[8] = {12, 45, 23, 89, 34, 7, 90, 21};
    int *ptr = tableau;  // Pointeur pour parcourir le tableau

    // Initialisation des variables pour le plus grand et le plus petit élément
    int plus_grand = *ptr;
    int plus_petit = *ptr;

    // Parcours du tableau avec le pointeur
    for (int i = 1; i < 8; i++) {
        if (*(ptr + i) > plus_grand) {
            plus_grand = *(ptr + i);
        }
        if (*(ptr + i) < plus_petit) {
            plus_petit = *(ptr + i);
        }
    }

    // Affichage des résultats
    printf("Le plus grand élément est : %d\n", plus_grand);
    printf("Le plus petit élément est : %d\n", plus_petit);

    return 0;
}
