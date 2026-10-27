/*
Esercizio 5 - Ruotare un array

Completa swap e ruota_destra: sposta gli elementi dell'array di k posizioni
verso destra. Gli elementi che escono dal fondo rientrano all'inizio.
La rotazione deve essere in place: modifica lo stesso array, senza
crearne un altro. Gli scambi devono usare puntatori: swap riceve due
indirizzi e scambia i valori con *a e *b. Nella rotazione muovi i
puntatori con ++ e --, senza usare a[i] per leggere o scrivere le celle.

Esempi:
- [1, 2, 3, 4, 5], k = 2 diventa [4, 5, 1, 2, 3].
- Se k = 0, l'array resta uguale.
- Se k supera n, conta solo il resto k % n.

n e k sono non negativi. Se n = 0, non fare nulla.
Tempo massimo O(n), memoria aggiuntiva O(1). Non usare ricorsione.
Il main stampa il risultato e quello atteso per tre prove.
*/

#include <stdio.h>

void swap(int *a, int *b)
{
    // TODO
}

void ruota_destra(int *a, int n, int k)
{
    // TODO
}

void stampa(const int a[], int n)
{
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main(void)
{
    int a[] = {1, 2, 3, 4, 5};
    int b[] = {10, 20, 30, 40};
    int c[] = {2, 4, 6, 8, 10, 12};

    ruota_destra(a, 5, 2);
    printf("Prova 1 - risultato: ");
    stampa(a, 5);
    printf("Atteso:             4 5 1 2 3\n\n");

    ruota_destra(b, 4, 0);
    printf("Prova 2 - risultato: ");
    stampa(b, 4);
    printf("Atteso:             10 20 30 40\n\n");

    ruota_destra(c, 6, 8);
    printf("Prova 3 - risultato: ");
    stampa(c, 6);
    printf("Atteso:             10 12 2 4 6 8\n");
    return 0;
}
