#include <stdio.h>

int main() {
    int nombres[100], taille, i, j;

    // Saisie des données
    printf("Entrez le nombre de nombres dans le tableau (max 100) : ");
    scanf("%d", &taille);

    printf("Entrez les %d nombres :\n", taille);
    for (i = 0; i < taille; i++) {
        scanf("%d", &nombres[i]);
    }

    // Affichage de l'histogramme
    printf("\nHistogramme des fréquences :\n");
    for (i = 0; i < taille; i++) {
        int compteur = 0;
        // Vérifie si le nombre a déjà été traité
        for (j = 0; j < i; j++) {
            if (nombres[i] == nombres[j]) {
                compteur = -1; // Marque comme déjà traité
                break;
            }
        }
        if (compteur == -1) continue; // Passe au suivant si déjà traité

        // Compte les occurrences
        for (j = 0; j < taille; j++) {
            if (nombres[i] == nombres[j]) {
                compteur++;
            }
        }

        // Affiche le nombre et ses étoiles
        printf("%d : ", nombres[i]);
        for (j = 0; j < compteur; j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
