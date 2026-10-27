void reverse_array(int *arr, size_t n) {
    if (!arr || n <= 1) return;

    int *left = arr;            // Punta al primo elemento
    int *right = arr + (n - 1); // Punta all'ultimo elemento

    while (left < right) {      // Confronto tra puntatori dello stesso array
        int temp = *left;
        *left = *right;
        *right = temp;

        left++;                 // Avanza di sizeof(int) byte
        right--;                // Arretra di sizeof(int) byte
    }
}
