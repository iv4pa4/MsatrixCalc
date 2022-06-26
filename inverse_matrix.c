#include <stdio.h>

void printMatrix(int rows, int columns, double matrix[rows][columns]) {
    printf("\n");
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			printf(" %F ", matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");
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

double findDeterminant(int n, double matrix[n][n]) {
    if(n == 2) {  //tva bachka
        return matrix[0][0]*matrix[1][1] - matrix[0][1]*matrix[1][0];
    }
    if(n == 3) {  //tva bachka
        double c[3];
        double res;
        for(int i = 0; i < 3; i++) {
            double temp[2][2];
            findSmallerMatrix(i, 0, 3, matrix, temp);
            c[i] = findDeterminant(2, temp);
            if(i == 1) {
                c[i] *= -1;
            }
            res += matrix[i][0]*c[i];
        }
        return res;
    }
    if(n == 4) {
        double c[4];
        double res;
        for(int i = 0; i < 4; i++) {
            double temp[3][3];
            findSmallerMatrix(i, 0, 4, matrix, temp);
            c[i] = findDeterminant(3, temp);
            if(i % 2) {
                c[i] *= -1;
            }
            res += matrix[i][0]*c[i];
            printf("\n");
        }
        return res;
    }
}

void findMoM(int size, double matrix[size][size], double MoM[size][size]) {
    for(int c = 0; c < size; c++) {
        for(int r = 0; r < size; r++) {
            double a[size-1][size-1];
            findSmallerMatrix(c, r, size, matrix, a);
            double d = findDeterminant(size-1, a);
            MoM[c][r] = d;
        }
    }
}

void swap(double *xp, double *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void transposeMatrix(int c, int r, double matrix[c][r], double res[r][c]) {
    for(int i = 0; i < c; i++) {
        for(int j = 0; j < r; j++) {
            res[j][i] = matrix[i][j];
        }
    }
}

void multiplyByScalar(int rows, int columns,double userMatrix[rows][columns], double result[rows][columns], double scalar) {
    for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
		result[i][j]=userMatrix[i][j]*scalar;
		}
		
	}

}

void divideByScalar(int c, int r, double matrix[c][r], double res[c][r], double scalar) {
    if(scalar) {
        double a = 1 / scalar;
        multiplyByScalar(r, c, matrix, res, a);
    }
}

void findInverse(int size, double matrix[size][size], double res[size][size]) {
    double temp[size][size];
    //MoM
    findMoM(size, matrix, temp);
    //MoC
    for(int c = 0; c < size; c++) {
        for(int r = 0; r < size; r++) {
            if((c + r) % 2) {
                temp[c][r] *= -1;
            }
        }
    }
    //Adj
    transposeMatrix(size, size, temp, res);
    //A^-1
    double d = findDeterminant(size, matrix);
    divideByScalar(size, size, res, res, d);
}



void main(){
    double mat[3][3] = {{ 3,  0,  2 }, 
                        { 2,  0, -2 }, 
                        { 0,  1,  1 }};
    double res[3][3];
    
    findInverse(3, mat, res);
    printMatrix(3, 3, res);
}
