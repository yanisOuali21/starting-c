#include <stdio.h>

int main() {
    int tab[10]; // Tableau de 10 entiers
    int max, min; // Variables pour le maximum et le minimum
    int c; // Variable temporaire pour le tri
    int i, j; // Variables de boucle

    // Saisie des 10 nombres
    printf("Entrez 10 nombres :\n");
    for (i = 0; i < 10; i++) {
        scanf("%d", &tab[i]);
    }

    // Initialisation de min et max avec la première valeur du tableau
    min = max = tab[0];

    // Recherche des valeurs minimale et maximale
    for (i = 1; i < 10; i++) {
        if (tab[i] < min) {
            min = tab[i];
        }
        if (tab[i] > max) {
            max = tab[i];
        }
    }

    printf("Le min est : %d\n", min);
    printf("Le max est : %d\n", max);

    // Tri du tableau (tri par sélection)
    for (i = 0; i < 10 - 1; i++) {
        for (j = i + 1; j < 10; j++) {
            if (tab[i] > tab[j]) {
                c = tab[i];
                tab[i] = tab[j];
                tab[j] = c;
            }
        }
    }

    // Affichage du tableau trié
    printf("Tableau trié : ");
    for (i = 0; i < 10; i++) {
        printf("%d ", tab[i]);
    }
    printf("\n");

    return 0; // Fin du programme
}
