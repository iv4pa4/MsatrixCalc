#include <stdio.h>

void multiplyByScalar(int rows, int columns,int userMatrix[rows][columns], int scalar) {
    for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
		userMatrix[i][j]=userMatrix[i][j]*scalar;
		}
		
	}

}
void divideByScalar(int rows, int columns,int userMatrix[rows][columns], int scalar) {
    if(scalar==0){
        printf("Invalid scalar<0\n");
    }else{
         for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
		userMatrix[i][j]=userMatrix[i][j]/scalar;
		}
		
	}
    }

}
void multiplyByMatrix(int rows1, int columns1, int rows2, int columns2, int matrix1[rows1][columns1], int matrix2[rows2][columns2], int result[rows1][columns1])
    {
        
        for(int i=0; i<rows1; i++){
            for(int j=0;j<columns2; j++){
                for(int k=0; k<columns1; k++){
                  result[i][j]+=matrix1[i][k]*matrix2[k][j];
                }
            }
        }
    }
   
int findDeterminand2x2(int rows, int columns, int matrix[rows][columns]){
	int determinand = 0;
	if (rows == 2 && columns == 2) {
		determinand = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
	}
	return determinand;
}


void printMatrix(int rows, int columns, int matrix[rows][columns]) {
    printf("\n");
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			printf(" %d ", matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int main(void) {
	
	int matrix2[5][3];
	int mMmatrix[3][5];
	int doublematrix[2][2];
	
	int result[3][5];
	int cnt = 1;
    doublematrix[0][0]=45;
    doublematrix[0][1]=12;
    doublematrix[1][0]=2;
    doublematrix[1][1]=1;
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 5; j++) {
			mMmatrix[i][j] = cnt;
			cnt++;
		}
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 3; j++) {
			matrix2[i][j] = cnt+2*3;
			cnt++;
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 5; j++) {
			result[i][j] = 0;
		}
	}
	 printMatrix(2, 2, doublematrix);
	 //printMatrix(5, 3, matrix2);
	//int determinand=findDeterminand2x2(2,2,doublematrix);
	//printf("%d", determinand);
	//multiplyByMatrix(3,5,5,3,mMmatrix,matrix2,result);
	//printMatrix(rows, columns, matrix);
    //printMatrix(3, 5, result);
	//printMatrix(5, 3, result);
	//multiplyByScalar(3, 5, mMmatrix, 5);
	//printMatrix(3, 5, mMmatrix);
	//divideByScalar(3, 5, mMmatrix, 0);
	//printMatrix(3, 5, mMmatrix);

}