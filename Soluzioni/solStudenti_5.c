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

LOGICA DELLA SOLUZIONE

Possiamo ruotare l'array facendo tre inversioni.
Esempio con [1, 2, 3, 4, 5] e k = 2:
1. Invertiamo tutto:                 [5, 4, 3, 2, 1].
2. Invertiamo i primi k elementi:    [4, 5, 3, 2, 1].
3. Invertiamo gli altri n-k elementi:[4, 5, 1, 2, 3].

Per invertire un pezzo usiamo due puntatori, uno a sinistra e uno a
destra. Passiamo gli indirizzi a swap, poi avviciniamo i puntatori finche'
si incontrano. Dereferenziare con * permette di modificare le celle originali. Basta una variabile temporanea per ogni scambio.
Tre passaggi lineari danno comunque O(n) tempo e O(1) memoria aggiuntiva.
*/

#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a; // Legge il valore puntato da a e lo salva.
    *a = *b; // Scrive nella prima cella il valore della seconda.
    *b = temp; // Completa lo scambio nella seconda cella.
}

void ruota_destra(int *a, int n, int k)
{
    if (n == 0) { // Nessun elemento: non calcoliamo indirizzi o k % n.
        return;
    }
    k = k % n; // Ignora i giri completi.
    if (k == 0) { // L'array e' gia' nella posizione richiesta.
        return;
    }

    int *sinistra = a; // Punta al primo elemento.
    int *destra = a + n - 1; // Punta all'ultimo elemento.
    while (sinistra < destra) { // Inverte tutto l'array.
        swap(sinistra, destra); // Passa gli indirizzi delle celle da scambiare.
        sinistra++; // Avanza di un int, non di un byte.
        destra--; // Arretra di un int.
    }

    sinistra = a; // Inizio dei primi k elementi.
    destra = a + k - 1; // Fine dei primi k elementi.
    while (sinistra < destra) {
        swap(sinistra, destra); // Inverte il primo pezzo.
        sinistra++;
        destra--;
    }

    sinistra = a + k; // Inizio degli elementi rimasti.
    destra = a + n - 1; // Fine dell'array.
    while (sinistra < destra) {
        swap(sinistra, destra); // Inverte il secondo pezzo.
        sinistra++;
        destra--;
    }
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
