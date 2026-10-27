/*
Esercizio 3 - Matrice a spirale

Completa stampa_spirale: deve stampare gli elementi della matrice in
senso orario, partendo dall'angolo in alto a sinistra e andando verso
il centro. Ogni elemento va stampato una sola volta.

La matrice e' passata come array contiguo, insieme a righe e colonne.
Il main prova tre matrici: 2x2, 3x4 e 5x5, e stampa l'ordine atteso.

Tempo: O(righe * colonne). Memoria aggiuntiva: O(1).
Non usare un secondo array o la ricorsione.
*/

#include <stdio.h>

void stampa_spirale(const int *matrice, int r, int c)
{
    //TODO
}


int main(void)
{
    int m2[] = {
        1, 2,
        3, 4
    };

    int m3[] = {
        1,  2,  3,  4,
        5,  6,  7,  8,
        9, 10, 11, 12
    };

    int m5[] = {
         1,  2,  3,  4,  5,
         6,  7,  8,  9, 10,
        11, 12, 13, 14, 15,
        16, 17, 18, 19, 20,
        21, 22, 23, 24, 25
    };

    printf("Matrice 2x2\nRisultato: ");
    stampa_spirale(m2, 2, 2);
    printf("Atteso:    1 2 4 3\n\n");

    printf("Matrice 3x4\nRisultato: ");
    stampa_spirale(m3, 3, 4);
    printf("Atteso:    1 2 3 4 8 12 11 10 9 5 6 7\n\n");

    printf("Matrice 5x5\nRisultato: ");
    stampa_spirale(m5, 5, 5);
    printf("Atteso:    1 2 3 4 5 10 15 20 25 24 23 22 21 16 11 6 7 8 9 14 19 18 17 12 13\n");

    return 0;
}
