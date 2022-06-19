//na teoriq raboti, na praktika to be tested

double findDeterminant(int r, int c, double matrix[r][c]){
    return 1;
}

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


void findMoM(int size, double matrix[size][size], double MoM[size][size]) {
    for(int c = 0; c < size; c++) {
        for(int r = 0; r < size; r++) {
            double a[size-1][size-1];
            findSmallerMatrix(c, r, size, matrix, a);
            int d = findDeterminant(size-1, size-1, a);
            MoM[c][r] = d;
        }
    }
}
//tva iskah da go include-na ot drug file, ma se chupi

void swap(double *xp, double *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

double** findInverse(int size, double matrix[size][size]) {
    double res[size][size];
    //MoM
    findMoM(size, matrix, res);
    //MoC
    for(int c = 0; c < size; c++) {
        for(int r = 0; r < size; r++) {
            if((c + r) % 2) {
                res[c][r] *= -1;
            }
        }
    }
    //Adj
    for(int c = 0; c < size; c++) {
        for(int r = 0; r < size; r++) {
            if(c > r) {
                swap(&res[c][r], &res[r][c]);
            }
        }
    }
    //A-1
    double d = findDeterminant(size, size, res);
    for(int c = 0; c < size; c++) {
        for(int r = 0; r < size; r++) {
            if(c > r) {
                res[c][r] *= d;
            }
        }
    }
}



void main(){}
