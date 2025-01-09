#include <stdio.h>

int main() {
    // Déclaration d'un tableau de 10 entiers
    int tableau[10] = {12, 34, 56, 78, 90, 23, 45, 67, 89, 11};
    int *ptr = tableau;  // Déclaration d'un pointeur sur le tableau

    // Demander à l'utilisateur d'entrer un nombre
    int nombre;
    printf("Entrez un nombre à rechercher : ");
    scanf("%d", &nombre);

    // Recherche de l'élément dans le tableau
    int trouve = 0;  // Variable pour indiquer si l'élément est trouvé

    for (int i = 0; i < 10; i++) {
        if (*(ptr + i) == nombre) {
            trouve = 1;
            break;
        }
    }

    // Affichage du résultat
    if (trouve) {
        printf("L'élément %d est présent dans le tableau.\n", nombre);
    } else {
        printf("L'élément %d n'est pas présent dans le tableau.\n", nombre);
    }

    return 0;
}
