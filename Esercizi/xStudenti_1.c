/* Scrivere una funzione che inverta l'ordine degli elementi di un vettore sul posto (in-place),
   con il vincolo rigido di non usare mai l'operatore di indicizzazione [], impiegando unicamente 
   due puntatori (start ed end), il confronto tra indirizzi (start < end) e la dereferenziazione. 
   
   TEMPO MASSIMO = 15 minuti
   
   REGOLE:
   
   - È vietato l'uso dell'operatore di indicizzazione [] all'interno della funzione.   
   - È vietato allocare un secondo array di appoggio (l'inversione deve avvenire in-place).   
   - Bisogna utilizzare due puntatori mobili: uno posizionato all'inizio dell'array e uno 
   posizionato sull'ultimo elemento valido. */
   
#include <stdio.h>

void reverse_array(int *arr, size_t n) {
    // TODO: implementare la logica con aritmetica dei puntatori
}

int main(void) {
    int data[] = {1, 2, 3, 4, 5, 6};
    size_t n = sizeof(data) / sizeof(data[0]);

    reverse_array(data, n);

    for (size_t i = 0; i < n; i++) {
        printf("%d ", *(data + i));
    }
    printf("\n");
    // Output atteso: 6 5 4 3 2 1
    return 0;
}
