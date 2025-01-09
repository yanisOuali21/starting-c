#include <stdio.h>

int main() {
    int nombres[10];
    int dejaVerifie[10] = {0}; // Pour marquer les nombres déjà vérifiés
    int i, j;
    int doublonTrouve = 0;

    // Demande à l'utilisateur de saisir 10 nombres
    printf("Entrez 10 nombres :\n");
    for (i = 0; i < 10; i++) {
        printf("Nombre %d : ", i + 1);
        scanf("%d", &nombres[i]);
    }

    // Vérifie et affiche chaque nombre répété une seule fois
    printf("Nombres répétés : ");
    for (i = 0; i < 10; i++) {
        if (dejaVerifie[i]) {
            continue; // Si le nombre a déjà été marqué comme répété, on passe
        }
        for (j = i + 1; j < 10; j++) {
            if (nombres[i] == nombres[j]) {
                if (!doublonTrouve) {
                    doublonTrouve = 1; // Indique qu'il y a au moins un doublon
                }
                printf("%d ", nombres[i]); // Affiche le nombre répété
                break; // On sort pour éviter de réafficher le même nombre
            }
        }
        // Marque toutes les occurrences de ce nombre comme vérifiées
        for (j = i; j < 10; j++) {
            if (nombres[i] == nombres[j]) {
                dejaVerifie[j] = 1;
            }
        }
    }

    // Si aucun doublon n'est trouvé
    if (!doublonTrouve) {
        printf("Aucun nombre répété.\n");
    } else {
        printf("\n");
    }

    return 0;
}
