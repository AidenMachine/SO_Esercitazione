// SOLUZIONE_1
int matrix_trace(const int *mat, size_t n) {
    if (!mat || n == 0) return 0;

    int sum = 0;
    for (size_t i = 0; i < n; i++) {
        sum += *(mat + i * (n + 1));
    }
    return sum;
}

// SOLUZIONE_2
int matrix_trace(const int *mat, size_t n) {
    if (!mat || n == 0) return 0;

    int sum = 0;
    const int *p = mat;
    for (size_t i = 0; i < n; i++) {
        sum += *p;
        p += (n + 1); // Salta direttamente al prossimo elemento della diagonale
    }
    return sum;
}
