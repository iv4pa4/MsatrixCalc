void swap(double *xp, double *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void transpose_matrix(int c, int r, double matrix[c][r], double res[r][c]) {
    for(int i = 0; i < c; i++) {
        for(int j = 0; j < r; j++) {
            swap(&res[j][i], &matrix[i][j]);
        }
    }
}
