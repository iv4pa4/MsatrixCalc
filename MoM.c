void findSmallerMatrix(int c, int r, int size, double matrix[size][size], double sM[size-1][size-1]) {
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            if(i!=c || j!=r) {
                if(i < c && j < r) {
                    sM[i][j] = matrix[i][j];
                }
                if(i > c && j < r) {
                    sM[i-1][j] = matrix[i][j];
                }
                if(i < c && j > r) {
                    sM[i][j-1] = matrix[i][j];
                }
                if(i > c && j > r) {
                    sM[i-1][j-1] = matrix[i][j];
                }
            }
        }
    }
}


double** findMoM(int size, double matrix[size][size]) {
    double MoM[size][size];
    for(int c = 0; c < size; c++) {
        for(int r = 0; r < size; r++) {
            double a[size-1][size-1];
            findSmallerMatrix(c, r, size, matrix, a);
            int d = findDeterminant(size-1, size-1, a);
            MoM[c][r] = d;
        }
    }
    return MoM;
}
void main(){}
