#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COMPTES 100
#define MAX_LONGUEUR_MDP 50

// Structure pour stocker les informations d'un compte
typedef struct {
    char service[50]; // Le nom du service (ex : Gmail, Facebook)
    char username[50]; // Nom d'utilisateur
    char password[MAX_LONGUEUR_MDP]; // Mot de passe
} Compte;

// Variables globales
Compte comptes[MAX_COMPTES];
int nombre_comptes = 0;

// Fonction pour vérifier la robustesse d'un mot de passe
int Verifier_Robustesse(const char *mdp) {
    int longueur = strlen(mdp);
    int majuscule = 0, minuscule = 0, chiffre = 0, caractere_special = 0;

    if (longueur < 8) return 0; // Trop court

    for (int i = 0; i < longueur; i++) {
        if (isupper(mdp[i])) majuscule = 1;
        else if (islower(mdp[i])) minuscule = 1;
        else if (isdigit(mdp[i])) chiffre = 1;
        else caractere_special = 1;
    }

    return (majuscule && minuscule && chiffre && caractere_special);
}

// Fonction pour ajouter un compte
void Ajouter_Compte() {
    if (nombre_comptes >= MAX_COMPTES) {
        printf("Erreur : Limite de comptes atteinte.\n");
        return;
    }

    Compte nouveau_compte;
    printf("Entrez le nom du service : ");
    scanf(" %[^\n]", nouveau_compte.service);

    printf("Entrez le nom d'utilisateur : ");
    scanf(" %[^\n]", nouveau_compte.username);

    printf("Entrez le mot de passe : ");
    scanf(" %[^\n]", nouveau_compte.password);

    if (!Verifier_Robustesse(nouveau_compte.password)) {
        printf("Mot de passe non sécurisé. Veuillez utiliser au moins 8 caractères, une majuscule, une minuscule, un chiffre et un caractère spécial.\n");
        return;
    }

    comptes[nombre_comptes] = nouveau_compte;
    nombre_comptes++;
    printf("Compte ajouté avec succès !\n");
}

// Fonction pour afficher tous les compte
void Afficher_Comptes() {
    if (nombre_comptes == 0) {
        printf("Aucun compte enregistré.\n");
        return;
    }

    printf("Liste des comptes enregistrés :\n");
    Compte *ptr = comptes; // Pointeur pour parcourir le tableau
    for (int i = 0; i < nombre_comptes; i++) {
        printf("%d. Service : %s, Nom d'utilisateur : %s\n", i + 1, ptr->service, ptr->username);
        ptr++; // Incrémentation du pointeur pour passer au compte suivant
    }
}


// Fonction pour récupérer un mot de passe
void Recuperer_Mot_De_Passe() {
    char service_recherche[50];
    printf("Entrez le nom du service : ");
    scanf(" %[^\n]", service_recherche);

    for (int i = 0; i < nombre_comptes; i++) {
        if (strcmp(comptes[i].service, service_recherche) == 0) {
            printf("Service : %s, Nom d'utilisateur : %s, Mot de passe : %s\n",
                   comptes[i].service, comptes[i].username, comptes[i].password);
            return;
        }
    }
    printf("Aucun compte trouvé pour ce service.\n");
}

// Fonction principale
int main() {
    int Action;

    while (1) {
        printf("\nQue voulez-vous faire :\n");
        printf("* Ajouter un compte                  (1)\n");
        printf("* Afficher tous les comptes          (2)\n");
        printf("* Récupérer un mot de passe          (3)\n");
        printf("* Quitter                            (4)\n");

        scanf("%d", &Action);

        switch (Action) {
            case 1:
                Ajouter_Compte();
                break;
            case 2:
                Afficher_Comptes();
                break;
            case 3:
                Recuperer_Mot_De_Passe();
                break;
            case 4:
                printf("Au revoir !\n");
                return 0;
            default:
                printf("Option invalide. Veuillez réessayer.\n");
        }
    }

    return 0;
}
