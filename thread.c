#include <stdio.h>
#include <pthread.h>

#define ITERATIONS 100

// Fonction pour le thread qui imprime "Bonjour"
void* printBonjour(void* arg) {
    for (int i = 0; i < ITERATIONS; i++) {
        printf("Bonjour\n");
    }
    return NULL;
}

// Fonction pour le thread qui imprime "Au revoir"
void* printAuRevoir(void* arg) {
    for (int i = 0; i < ITERATIONS; i++) {
        printf("Au revoir\n");
    }
    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    // Création des threads
    if (pthread_create(&thread1, NULL, printBonjour, NULL) != 0) {
        perror("Erreur lors de la création du thread 1");
        return 1;
    }

    if (pthread_create(&thread2, NULL, printAuRevoir, NULL) != 0) {
        perror("Erreur lors de la création du thread 2");
        return 1;
    }

    // Attente de la fin des threads
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}
