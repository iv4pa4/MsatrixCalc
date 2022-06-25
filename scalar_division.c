//NOTE: make multiply work with doubles

void divideByScalar(int c, int r, double matrix[c][r], double res[c][r], double scalar) {
    if(scalar) {
        double a = 1 / scalar;
        multiplyByScalar(r, c, matrix, res, a);
    }
}

void main(){}
