/*
Esercizio 3 - Matrice a spirale

Completa stampa_spirale: stampa la matrice in senso orario, partendo
in alto a sinistra e andando verso il centro, senza ripetere elementi.
La matrice e' un array contiguo; il main prova 2x2, 3x4 e 5x5.
Tempo O(righe * colonne), memoria aggiuntiva O(1).

LOGICA DELLA SOLUZIONE

r e c sono il numero di righe e colonne. Gli indici correnti sono
i (riga) e j (colonna). Ne muoviamo soltanto uno alla volta.
All'inizio andiamo a destra: i resta fermo, j aumenta.
Quando j raggiunge bump_destra, abbiamo finito la riga superiore:
spostiamo bump_alto di uno e iniziamo a scendere, tenendo j fermo.
Quando i raggiunge bump_basso, abbiamo finito la colonna destra:
spostiamo bump_destra di uno e iniziamo ad andare a sinistra.
Poi risaliamo, poi torniamo a destra, sempre stringendo il bordo finito.

Servono quattro limiti per ricordare i bordi rimasti: alto, basso,
sinistra e destra. Non basta ricordare solo i due massimi, perche' anche
i bordi alto e sinistro si spostano verso il centro.
La direzione dice quale indice muovere e in quale verso:
0 = destra, 1 = giu', 2 = sinistra, 3 = su.
Ci fermiamo dopo r * c stampe.
*/

#include <stdio.h>

void stampa_spirale(const int *matrice, int r, int c)
{
    int i = 0, j = 0; // Partiamo dalla cella in alto a sinistra.
    int direzione = 0; // All'inizio ci muoviamo verso destra.

    int bump_alto = 0; // Prima riga ancora da visitare.
    int bump_basso = r - 1; // Ultima riga ancora da visitare.
    int bump_sinistra = 0; // Prima colonna ancora da visitare.
    int bump_destra = c - 1; // Ultima colonna ancora da visitare.

    for (int stampati = 0; stampati < r * c; stampati++) {
        printf("%d ", matrice[i * c + j]); // Stampa la cella corrente.

        // Dopo l'ultima cella non serve piu' muovere gli indici.
        if (stampati == r * c - 1) {
            break;
        }

        if (direzione == 0) { // Stiamo andando a destra: riga e' ferma.
            if (j == bump_destra) { // Bump! La riga superiore e' finita.
                bump_alto++; // La escludiamo dai prossimi giri.
                direzione = 1; // Ora dobbiamo scendere.
                i++; // Primo passo in basso; colonna resta ferma.
            } else {
                j++; // Nessun bump: continuiamo a destra.
            }
        } else if (direzione == 1) { // Scendiamo: colonna e' ferma.
            if (i == bump_basso) { // Bump! La colonna destra e' finita.
                bump_destra--; // La escludiamo dai prossimi giri.
                direzione = 2; // Ora dobbiamo andare a sinistra.
                j--; // Primo passo a sinistra; riga resta ferma.
            } else {
                i++; // Nessun bump: continuiamo a scendere.
            }
        } else if (direzione == 2) { // Andiamo a sinistra: riga e' ferma.
            if (j == bump_sinistra) { // Bump! La riga inferiore e' finita.
                bump_basso--; // La escludiamo dai prossimi giri.
                direzione = 3; // Ora dobbiamo salire.
                i--; // Primo passo in alto; colonna resta ferma.
            } else {
                j--; // Nessun bump: continuiamo a sinistra.
            }
        } else { // Saliamo: colonna e' ferma.
            if (i == bump_alto) { // Bump! La colonna sinistra e' finita.
                bump_sinistra++; // La escludiamo dai prossimi giri.
                direzione = 0; // Ricominciamo verso destra, un giro piu' interno.
                j++; // Primo passo a destra; riga resta ferma.
            } else {
                i--; // Nessun bump: continuiamo a salire.
            }
        }
    }
    printf("\n"); // Fine della spirale.
}


int main(void)
{
    // Gli array contengono le righe della matrice una dopo l'altra.
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

    // Proviamo la matrice 2x2 e confrontiamo visivamente le due righe.
    printf("Matrice 2x2\nRisultato: ");
    stampa_spirale(m2, 2, 2);
    printf("Atteso:    1 2 4 3\n\n");

    // Proviamo la matrice 3x4 e confrontiamo visivamente le due righe.
    printf("Matrice 3x4\nRisultato: ");
    stampa_spirale(m3, 3, 4);
    printf("Atteso:    1 2 3 4 8 12 11 10 9 5 6 7\n\n");

    // Proviamo la matrice 5x5 e confrontiamo visivamente le due righe.
    printf("Matrice 5x5\nRisultato: ");
    stampa_spirale(m5, 5, 5);
    printf("Atteso:    1 2 3 4 5 10 15 20 25 24 23 22 21 16 11 6 7 8 9 14 19 18 17 12 13\n");

    return 0; // Fine del programma.
}
