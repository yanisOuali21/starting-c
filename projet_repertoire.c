#include <stdio.h>
#include <string.h>

#define MAX_PERSONNES 100

// Structure pour représenter une personne
typedef struct {
    char nom[50];
    char telephone[15];
} Personne;

// Variables globales
Personne repertoire[MAX_PERSONNES];
int nombre_personnes = 0;

// Fonction pour ajouter une personne
void Creer_Enregistrement() {
    if (nombre_personnes >= MAX_PERSONNES) {
        printf("Répertoire plein, impossible d'ajouter une nouvelle personne.\n");
        return;
    }

    Personne nouvelle_personne;
    printf("Entrez le nom : ");
    scanf("%s", nouvelle_personne.nom);

    printf("Entrez le numéro de téléphone : ");
    scanf("%s", nouvelle_personne.telephone);

    repertoire[nombre_personnes] = nouvelle_personne;
    nombre_personnes++;
    printf("Personne ajoutée avec succès !\n");
}

// Fonction pour afficher le contenu du répertoire
void Affiche_Repertoire() {
    if (nombre_personnes == 0) {
        printf("Le répertoire est vide.\n");
        return;
    }

    printf("Contenu du répertoire :\n");
    for (int i = 0; i < nombre_personnes; i++) {
        printf("%d. Nom : %s, Téléphone : %s\n", i + 1, repertoire[i].nom, repertoire[i].telephone);
    }
}

// Fonction pour rechercher une personne par nom
void Recherche() {
    char nom_recherche[50];
    printf("Entrez le nom à rechercher : ");
    scanf("%s", nom_recherche);

    int trouve = 0;
    for (int i = 0; i < nombre_personnes; i++) {
        if (strcmp(repertoire[i].nom, nom_recherche) == 0) {
            printf("Personne trouvée : Nom : %s, Téléphone : %s\n", repertoire[i].nom, repertoire[i].telephone);
            trouve = 1;
            break;
        }
    }

    if (!trouve) {
        printf("Aucune personne trouvée avec le nom \"%s\".\n", nom_recherche);
    }
}

// Fonction pour retirer une personne par nom
void Retirer() {
    char nom_retirer[50];
    printf("Entrez le nom de la personne à retirer : ");
    scanf("%s", nom_retirer);

    int index = -1;
    for (int i = 0; i < nombre_personnes; i++) {
        if (strcmp(repertoire[i].nom, nom_retirer) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Aucune personne trouvée avec le nom \"%s\".\n", nom_retirer);
        return;
    }

    // Supprimer l'entrée et réorganiser le tableau
    for (int i = index; i < nombre_personnes - 1; i++) {
        repertoire[i] = repertoire[i + 1];
    }
    nombre_personnes--;
    printf("Personne retirée avec succès !\n");
}

// Fonction pour charger le répertoire depuis un fichier
void Charger_Repertoire() {
    FILE *fichier = fopen("repertoire.txt", "r");
    if (fichier == NULL) {
        printf("Erreur : Impossible de lire le fichier.\n");
        return;
    }

    nombre_personnes = 0;
    while (fscanf(fichier, "%s %s", repertoire[nombre_personnes].nom, repertoire[nombre_personnes].telephone) != EOF) {
        nombre_personnes++;
        if (nombre_personnes >= MAX_PERSONNES) {
            printf("Attention : Le fichier contient plus d'entrées que la capacité maximale (%d).\n", MAX_PERSONNES);
            break;
        }
    }

    fclose(fichier);
    printf("Répertoire chargé avec succès (%d entrées).\n", nombre_personnes);
}

// Fonction principale
int main() {
    int Action;

    while (1) {
        printf("\nQue voulez-vous faire :\n");
        printf("* Ajouter une personne         (1)\n");
        printf("* Afficher le répertoire       (2)\n");
        printf("* Faire une recherche par nom  (3)\n");
        printf("* Retirer une personne par nom (4)\n");
        printf("* Charger le répertoire        (5)\n");
        printf("* Terminer                     (6)\n");

        scanf("%d", &Action);

        switch (Action) {
            case 1:
                Creer_Enregistrement();
                break;
            case 2:
                Affiche_Repertoire();
                break;
            case 3:
                Recherche();
                break;
            case 4:
                Retirer();
                break;
            case 5:
                Charger_Repertoire();
                break;
            case 6:
                printf("Terminé...\n");
                return 0;
            default:
                printf("Option invalide. Veuillez réessayer.\n");
        }
    }

    return 0;
}
