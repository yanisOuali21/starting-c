#include <stdio.h>

int main() {
    // Déclaration et initialisation du tableau de 6 entiers
    int tableau[6] = {34, 12, 25, 9, 56, 18};
    int *ptr1, *ptr2, temp;

    // Tri à bulles avec des pointeurs
    for (int i = 0; i < 6 - 1; i++) {
        for (int j = 0; j < 6 - i - 1; j++) {
            ptr1 = tableau + j;       // Pointeur sur l'élément courant
            ptr2 = tableau + j + 1;  // Pointeur sur l'élément suivant

            if (*ptr1 > *ptr2) {
                // Échange des éléments en utilisant une variable temporaire
                temp = *ptr1;
                *ptr1 = *ptr2;
                *ptr2 = temp;
            }
        }
    }

    // Affichage du tableau trié
    printf("Tableau trié en ordre croissant : ");
    for (int i = 0; i < 6; i++) {
        printf("%d ", *(tableau + i));
    }
    printf("\n");

    return 0;
}
