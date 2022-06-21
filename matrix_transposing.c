void transpose_matrix(int c, int r, double matrix[c][r], double res[r][c]) {
    for(int i = 0; i < c; i++) {
        for(int j = 0; j < r; j++) {
            res[r][c] = matrix[c][r];
        }
    }
}
