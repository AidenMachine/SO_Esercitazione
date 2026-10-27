/* Calcolare la traccia (la somma degli elementi sulla diagonale
principale) di una matrice quadrata NxN passata come
buffer contiguo, utilizzando un singolo ciclo for invece del
canonico doppio ciclo annidato, sfruttando la formula del row-major
order.  

TEMPO MASSIMO = 15 minuti

Sapendo che il C memorizza le matrici in Row-Major Order (in modo lineare e contiguo in memoria):   
1) Ricava l'indice lineare in cui risiede l'elemento generico m[i][i].   
2) Completa la funzione matrix_trace affinché calcoli la traccia eseguendo un solo ciclo di iterazione (senza annidare cicli per righe e colonne). */

#include <stdio.h>

#define N 3

int matrix_trace(const int *mat, size_t n) {
    // TODO: calcolare la traccia con un singolo ciclo for
}

int main(void) {
    int grid[N][N] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // grid[0][0] = 1, grid[1][1] = 5, grid[2][2] = 9
    int tr = matrix_trace((const int *)grid, N);
    printf("Traccia: %d\n", tr); 
    // Output atteso: 15 (1 + 5 + 9)

    return 0;
}
