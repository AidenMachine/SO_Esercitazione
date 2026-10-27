/*
Esercizio 6 - Un thread scrive, l'altro legge e somma

Completa scrittore e lettore. Il main prepara gia' due thread e un
semaforo. I thread condividono l'array numeri e la variabile somma.

Lo scrittore deve:
- riempire l'array usando sempre numeri[i] = i * i, per i da 0 a n_elementi-1;
- segnalare al lettore che tutti i numeri sono pronti usando sem_post.

Il lettore deve:
- aspettare il segnale dello scrittore usando sem_wait;
- leggere i n_elementi elementi e salvare il loro totale in somma.

Il semaforo pronto parte da zero: il lettore non puo' leggere prima
che lo scrittore abbia finito. Non basta creare lo scrittore per primo:
l'ordine di esecuzione dei thread lo decide il sistema operativo.
Non usare sleep, cicli di attesa attiva o una variabile "finito".

Esempio: con n_elementi = 4, lo scrittore mette [0, 1, 4, 9] nell'array;
il lettore aspetta che sia pronto e poi produce somma = 14.
Il main prova 4, 6 e 10 elementi e stampa risultato e atteso.

Ogni thread richiede O(n_elementi) tempo di calcolo e O(1) memoria aggiuntiva,
escluso l'array condiviso gia' fornito. L'attesa del semaforo non e' inclusa
nel tempo di calcolo. Serve un sistema POSIX, come Linux. Compila con -pthread.
*/

#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <errno.h>

int numeri[10]; // Memoria condivisa dai due thread.
int n_elementi; // Quanti elementi usare nella prova corrente.
int somma; // Il lettore scrive qui il risultato.
sem_t pronto; // Lo scrittore segnala che l'array puo' essere letto.

void *scrittore(void *arg)
{
    // TODO
    return NULL; // Richiesto dalla firma delle funzioni eseguite dai thread.
}

void *lettore(void *arg)
{
    // TODO
    return NULL;
}

// Questo codice e' gia' pronto: completa solo le due funzioni sopra.
void prova(int n, int atteso)
{
    n_elementi = n;
    somma = 0;
    for (int i = 0; i < n_elementi; i++) {
        numeri[i] = 0;
    }

    if (sem_init(&pronto, 0, 0) == -1) { // Condiviso tra thread, valore iniziale zero.
        perror("sem_init");
        exit(1);
    }

    pthread_t t_scrittore, t_lettore;
    // Avviamo prima il lettore: dovra' aspettare i dati dello scrittore.
    if (pthread_create(&t_lettore, NULL, lettore, NULL) != 0) {
        fprintf(stderr, "Errore nella creazione del lettore.\n");
        exit(1);
    }
    if (pthread_create(&t_scrittore, NULL, scrittore, NULL) != 0) {
        fprintf(stderr, "Errore nella creazione dello scrittore.\n");
        exit(1);
    }

    // Il main aspetta entrambi prima di leggere somma o iniziare un'altra prova.
    if (pthread_join(t_scrittore, NULL) != 0 || pthread_join(t_lettore, NULL) != 0) {
        fprintf(stderr, "Errore nell'attesa dei thread.\n");
        exit(1);
    }
    if (sem_destroy(&pronto) == -1) { // Non ci sono piu' thread che lo usano.
        perror("sem_destroy");
        exit(1);
    }

    printf("Con %d elementi - risultato: %d, atteso: %d\n", n, somma, atteso);
}

int main(void)
{
    prova(4, 14);
    prova(6, 55);
    prova(10, 285);
    return 0;
}
