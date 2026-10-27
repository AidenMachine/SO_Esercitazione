/*
Esercizio 4 - Somme con i processi

Completa solo esegui_figlio. Il main crea gia' 5 figli con fork e li
aspetta con waitpid. Ogni figlio chiama la funzione tre volte, una per
matrice. m e' la matrice corrente, r e c sono le sue dimensioni.

A ogni chiamata, il figlio con indice f_id deve:
- sommare la riga f_id, se esiste;
- sommare la colonna f_id, se esiste;
- stampare il proprio indice e le due somme.
Se una riga o colonna manca, saltala senza stampare nulla per quella
somma. Se mancano entrambe, non stampare nulla per quella matrice.

Gli indici partono da zero: f_id e' sia l'indice della riga sia quello
della colonna da sommare. Non e' il PID restituito da fork.

Tre esempi per capire cosa deve fare il figlio:

- Matrice 5x5, f_id = 2: somma e stampa la riga 2 e la colonna 2.
- Matrice 3x4, f_id = 3: somma e stampa solo la colonna 3.
  La riga 3 non esiste, quindi per la riga non fa nulla.
- Matrice 2x2, f_id = 2: non esistono ne' la riga 2 ne' la colonna 2,
  quindi non fa nulla e non stampa nulla.

Finito l'esercizio, cambiare la variabile n_trials a 10 per eseguire piu' prove.
*/

#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

void esegui_figlio(int f_id, const int m[], int r, int c)
{
    //TODO
}

void main_fn(int ordine_figli[])
{
    fflush(stdout); // Non duplica nei nuovi figli le stampe delle esecuzioni precedenti.
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

    int pid_figli[5]; // PID del figlio 0, del figlio 1, ecc.

    for (int f_id = 0; f_id < 5; f_id++) { 
        // Crea un figlio per ogni indice da 0 a 4.
        
        // fork crea un processo figlio: padre e figlio continuano da questa chiamata.
        // Nel figlio pid vale 0; nel padre contiene il PID (identificativo) del figlio.
        // Se pid vale -1, la creazione e' fallita. f_id e' invece il nostro indice 0 -> 4

        int pid = fork();
        if (pid == -1) {
            perror("fork");
            exit(1); // Termina il programma in caso di errore nella creazione del figlio.
        }
        if (pid == 0) {
            // Le stampe mostrano come si alternano i figli.
            for (int passo = 0; passo < 100; passo++) {
                printf("Figlio %d: passo %d\n", f_id, passo);
                fflush(stdout); // Stampa subito: altrimenti i messaggi possono restare nel buffer e uscire a blocchi.
            }
            
            //TODO

            printf("Figlio %d terminato\n", f_id);
            exit(0);
        }
        pid_figli[f_id] = pid; //RACCOLTA PID: Il padre ricorda il PID associato a questo indice.
    }

    // Il padre aspetta 5 figli. -1 significa "un figlio qualsiasi",
    // NULL ignora il codice di uscita e 0 fa aspettare finche' un figlio termina.
    for (int posizione = 0; posizione < 5; posizione++) {
        int pid_terminato = waitpid(-1, NULL, 0);
        if (pid_terminato == -1) {
            perror("waitpid");
            exit(1);
        }

        // RACCOLTA PID:Cerchiamo a quale f_id corrisponde il PID restituito da waitpid.
        for (int f_id = 0; f_id < 5; f_id++) {
            if (pid_figli[f_id] == pid_terminato) {
                ordine_figli[posizione] = f_id;
                break;
            }
        }
    }

    // Queste righe vengono stampate soltanto dal padre, dopo l'attesa.
    printf("\nAtteso (riga, colonna), in ordine di figlio:\n");
    printf("2x2: (3, 4), (7, 6)\n");
    printf("3x4: (10, 15), (26, 18), (42, 21); figlio 3: solo colonna = 24\n");
    printf("5x5: (15, 55), (40, 60), (65, 65), (90, 70), (115, 75)\n");
    // L'ordine e' gia' salvato nell'array ricevuto dal main.
}

int main(void)
{
    int n_trials = 1;
    int ordini[n_trials][5]; // Una riga per ogni prova.

    for (int prova = 0; prova < n_trials; prova++) {
        main_fn(ordini[prova]);
    }

    // Stampiamo tutti gli ordini soltanto dopo l'ultima prova.
    for (int prova = 0; prova < n_trials; prova++) {
        printf("\nProva %d - ordine dei figli raccolti: [", prova + 1);
        for (int i = 0; i < 5; i++) {
            if (i > 0) {
                printf(", ");
            }
            printf("%d", ordini[prova][i]);
        }
        printf("]\n");
    }
    return 0;
}
