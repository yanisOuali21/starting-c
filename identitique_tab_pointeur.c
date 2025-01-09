#include <stdio.h>

int main() {
    // Déclaration et initialisation des deux tableaux
    int tableau1[5] = {10, 20, 30, 40, 50};
    int tableau2[5] = {10, 20, 30, 40, 50};

    // Pointeurs pour parcourir les tableaux
    int *ptr1 = tableau1;
    int *ptr2 = tableau2;

    // Variable pour vérifier si les tableaux sont identiques
    int identiques = 1; // Supposons qu'ils sont identiques

    // Comparaison des éléments correspondants des deux tableaux
    for (int i = 0; i < 5; i++) {
        if (*(ptr1 + i) != *(ptr2 + i)) {
            identiques = 0; // Ils ne sont pas identiques
            break;
        }
    }

    // Affichage du résultat
    if (identiques) {
        printf("Les tableaux sont identiques.\n");
    } else {
        printf("Les tableaux ne sont pas identiques.\n");
    }

    return 0;
}
