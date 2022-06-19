void divide_by_scalar(int c, int r, double matrix[c][r], double scalar) {
    if(scalar) {
        double a = 1 / scalar;
        multiplyByScalar(r, c, matrix, a); //tuka trqbva da se razberem s ivka che leko ne bachka tui
    }
}

void main(){}
