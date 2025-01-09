#include <stdio.h>

int main() {
    // Déclaration et initialisation des deux tableaux
    int tableau1[5] = {1, 2, 3, 4, 5};
    int tableau2[5] = {5, 4, 3, 2, 1};

    // Déclaration du tableau pour stocker les résultats de l'addition
    int tableau_resultat[5];

    // Pointeurs pour parcourir les tableaux
    int *ptr1 = tableau1;
    int *ptr2 = tableau2;
    int *ptr_result = tableau_resultat;

    // Addition des éléments correspondants des deux tableaux
    for (int i = 0; i < 5; i++) {
        *(ptr_result + i) = *(ptr1 + i) + *(ptr2 + i);
    }

    // Affichage des deux tableaux d'origine et du tableau résultat
    printf("Tableau 1 : ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", *(ptr1 + i));
    }
    printf("\n");

    printf("Tableau 2 : ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", *(ptr2 + i));
    }
    printf("\n");

    printf("Tableau Résultat : ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", *(ptr_result + i));
    }
    printf("\n");

    return 0;
}
