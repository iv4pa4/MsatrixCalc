#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*double findDeterminant(int n, double matrix[n][n]) { return 0; }
void findSmallerMatrix(int c, int r, int size, double matrix[size][size], double sM[size - 1][size - 1]) {}
void findMoM(int size, double matrix[size][size], double MoM[size][size]) {}
void transposeMatrix(int c, int r, double matrix[c][r], double res[r][c]) {}
void multiplyByScalar(int rows, int columns, double userMatrix[rows][columns], double result[rows][columns], double scalar) {}
void divideByScalar(int c, int r, double matrix[c][r], double res[c][r], double scalar) {}
void findInverse(int size, double matrix[size][size], double res[size][size]) {}
void multiplyByMatrix(int rows1, int columns1, int rows2, int columns2, int matrix1[rows1][columns1], int matrix2[rows2][columns2], int result[rows1][columns1]) {}
void printMatrix(int rows, int columns, int matrix[rows][columns]) {}*/

int main() 
{
	char answer[20];
	char operation[20];

	printf("Load matrix from file: L\n");
	printf("Operate with matrixes: O\n");
	scanf("%19s", answer);

	if (answer[0] == 'L' || answer[0] == 'l') {
		printf("Enter name of file \n");
		char name[100];
		int row[20];
		int col[20];
		scanf("%s", name);
		printf("How many rows? \n");
		scanf("%d", row);
		printf("How many columns? \n");
		scanf("%d", col);
		FILE* file;
		file = fopen(name, "r");
		int num = 0;
		//double matrix[row][col];
		double matrix[4][4];
		for (int i = 0; i < row[0]; i++) {

			for (int j = 0; j < col[0]; j++) {

				fscanf(file, "%d", &num);

				matrix[i][j] = num;

			}

		}

		fclose(file);

		printf("What operation do you want to use?:\n");
		printf("Multiply by scalar: MS\n");
		printf("Divide by scalar: DS\n");
		printf("Multiply by matrix: MM\n");
		printf("Find determinand: FD\n");
		printf("Find inverse matrix: FI\n");
		printf("Transpose matrix: TM\n");
		scanf("%19s", operation);

		if (operation[0] == 'MS' || operation[0] == 'ms') {
			printf("Enter name of file \n");
			char name[100];
			int row[20];
			int col[20];
			double scalar[20];
			scanf("%s", name);
			printf("How many rows? \n");
			scanf("%d", row);
			printf("How many columns? \n");
			scanf("%d", col);
			FILE* file;
			file = fopen(name, "r");
			int num = 0;
			double matrix[row][col];
			double result[row][col];
			for (int i = 0; i < row[0]; i++) {
				for (int j = 0; j < col[0]; j++) {
					fscanf(file, "%d", &num);
					matrix[i][j] = num;
				}
			}
			fclose(file);
			printf("Enter scalar \n");
			scanf("%f", scalar);
			multiplyByScalar(row, col, matrix, result, scalar);
			printMatrix(row, col, result);
		}
		if (operation[0] == 'DS' || operation[0] == 'ds') {
			printf("Enter name of file \n");
			char name[100];
			int row[20];
			int col[20];
			double scalar[20];
			scanf("%s", name);
			printf("How many rows? \n");
			scanf("%d", row);
			printf("How many columns? \n");
			scanf("%d", col);
			FILE* file;
			file = fopen(name, "r");
			int num = 0;
			double matrix[row][col];
			double result[row][col];
			for (int i = 0; i < row[0]; i++) {
				for (int j = 0; j < col[0]; j++) {
					fscanf(file, "%d", &num);
					matrix[i][j] = num;
				}
			}
			fclose(file);
			printf("Enter scalar \n");
			scanf("%f", scalar);
			divideByScalar(col, row, matrix, result, scalar);
			printMatrix(row, col, result);
		}
		if (operation[0] == 'MM' || operation[0] == 'mm') {
			printf("Enter name of file1 \n");
			char name1[100];
			int row1[20];
			int col1[20];
			scanf("%s", name1);
			printf("How many rows? \n");
			scanf("%d", row1);
			printf("How many columns? \n");
			scanf("%d", col1);
			FILE* file;
			file = fopen(name1, "r");
			int num1 = 0;
			double matrix1[row][col];
			double matrix2[row][col];
			for (int i = 0; i < row1[0]; i++) {
				for (int j = 0; j < col1[0]; j++) {
					fscanf(file, "%d", &num1);
					matrix1[i][j] = num1;
				}
			}
			fclose(file);

			printf("Enter name of file1 \n");
			char name2[100];
			int row2[20];
			int col2[20];
			scanf("%s", name2);
			printf("How many rows? \n");
			scanf("%d", row2);
			printf("How many columns? \n");
			scanf("%d", col2);
			FILE* file2;
			file = fopen(name2, "r");
			int num2 = 0;
			double matrix2[row][col];
			double result[row][col];
			for (int i = 0; i < row2[0]; i++) {
				for (int j = 0; j < col2[0]; j++) {
					fscanf(file, "%d", &num2);
					matrix2[i][j] = num2;
				}
			}
			fclose(file2);
			multiplyByMatrix(row1, col1, row2, col2, matrix1[row1][col1], matrix2[row2][col2], int result[row1][col1])
		}
		if (operation[0] == 'FD' || operation[0] == 'fd') {
			printf("Enter name of file \n");
			char name[100];
			int row[20];
			int col[20];
			double scalar[20];
			scanf("%s", name);
			printf("How many rows? \n");
			scanf("%d", row);
			printf("How many columns? \n");
			scanf("%d", col);
			FILE* file;
			file = fopen(name, "r");
			int num = 0;
			double matrix[row][col];
			double result[row][col];
			for (int i = 0; i < row[0]; i++) {
				for (int j = 0; j < col[0]; j++) {
					fscanf(file, "%d", &num);
					matrix[i][j] = num;
				}
			}
			fclose(file);
			result = findDeterminant(result, matrix);
			printMatrix(row, col, matrix);
		}
		if (operation[0] == 'FI' || operation[0] == 'fi') {
			printf("Enter name of file \n");
			char name[100];
			int row[20];
			int col[20];
			double scalar[20];
			scanf("%s", name);
			printf("How many rows? \n");
			scanf("%d", row);
			printf("How many columns? \n");
			scanf("%d", col);
			FILE* file;
			file = fopen(name, "r");
			int num = 0;
			double matrix[row][col];
			double result[row][col];
			for (int i = 0; i < row[0]; i++) {
				for (int j = 0; j < col[0]; j++) {
					fscanf(file, "%d", &num);
					matrix[i][j] = num;
				}
			}
			fclose(file);
			findInverse(row, matrix, result);
			printMatrix(row, col, result);
		}
		if (operation[0] == 'TM' || operation[0] == 'tm') {

			printf("Enter name of file \n");
			char name[100];
			int row[20];
			int col[20];
			double scalar[20];
			scanf("%s", name);
			printf("How many rows? \n");
			scanf("%d", row);
			printf("How many columns? \n");
			scanf("%d", col);
			FILE* file;
			file = fopen(name, "r");
			int num = 0;
			double matrix[row][col];
			double result[row][col];
			for (int i = 0; i < row[0]; i++) {
				for (int j = 0; j < col[0]; j++) {
					fscanf(file, "%d", &num);
					matrix[i][j] = num;
				}
			}
			fclose(file);
			transposeMatrix(col, row, matrix, result);
			printMatrix(row, col, result);
		}
	}


	}
	if (answer[0] == 'O' || answer[0] == 'o') {
		printf("What operation do you want to use?:\n");
		printf("Multiply by scalar: MS\n");
		printf("Divide by scalar: DS\n");
		printf("Multiply by matrix: MM\n");
		printf("Find determinand: FD\n");
		printf("Find inverse matrix: FI\n");
		printf("Transpose matrix: TM\n");
		scanf("%19s", operation);

		if (operation[0] == 'MS' || operation[0] == 'ms') {
			printf("Enter name of file \n");
			char name[100];
			int row[20];
			int col[20];
			double scalar[20];
			scanf("%s", name);
			printf("How many rows? \n");
			scanf("%d", row);
			printf("How many columns? \n");
			scanf("%d", col);
			FILE* file;
			file = fopen(name, "r");
			int num = 0;
			double matrix[row][col];
			double result[row][col];
			for (int i = 0; i < row[0]; i++) {
				for (int j = 0; j < col[0]; j++) {
					fscanf(file, "%d", &num);
					matrix[i][j] = num;
				}
			}
			fclose(file);
			printf("Enter scalar \n");
			scanf("%f", scalar);
			multiplyByScalar(row, col, matrix, result, scalar);
			printMatrix(row, col, result);
		}
		if (operation[0] == 'DS' || operation[0] == 'ds') {
			printf("Enter name of file \n");
			char name[100];
			int row[20];
			int col[20];
			double scalar[20];
			scanf("%s", name);
			printf("How many rows? \n");
			scanf("%d", row);
			printf("How many columns? \n");
			scanf("%d", col);
			FILE* file;
			file = fopen(name, "r");
			int num = 0;
			double matrix[row][col];
			double result[row][col];
			for (int i = 0; i < row[0]; i++) {
				for (int j = 0; j < col[0]; j++) {
					fscanf(file, "%d", &num);
					matrix[i][j] = num;
				}
			}
			fclose(file);
			printf("Enter scalar \n");
			scanf("%f", scalar);
			divideByScalar(col, row, matrix, result, scalar);
			printMatrix(row, col, result);
		}
		if (operation[0] == 'MM' || operation[0] == 'mm') {
			printf("Enter name of file1 \n");
			char name1[100];
			int row1[20];
			int col1[20];
			scanf("%s", name1);
			printf("How many rows? \n");
			scanf("%d", row1);
			printf("How many columns? \n");
			scanf("%d", col1);
			FILE* file;
			file = fopen(name1, "r");
			int num1 = 0;
			double matrix1[row][col];
			double matrix2[row][col];
			for (int i = 0; i < row1[0]; i++) {
				for (int j = 0; j < col1[0]; j++) {
					fscanf(file, "%d", &num1);
					matrix1[i][j] = num1;
				}
			}
			fclose(file);

			printf("Enter name of file1 \n");
			char name2[100];
			int row2[20];
			int col2[20];
			scanf("%s", name2);
			printf("How many rows? \n");
			scanf("%d", row2);
			printf("How many columns? \n");
			scanf("%d", col2);
			FILE* file2;
			file = fopen(name2, "r");
			int num2 = 0;
			double matrix2[row][col];
			double result[row][col];
			for (int i = 0; i < row2[0]; i++) {
				for (int j = 0; j < col2[0]; j++) {
					fscanf(file, "%d", &num2);
					matrix2[i][j] = num2;
				}
			}
			fclose(file2);
			multiplyByMatrix(row1, col1, row2, col2, matrix1[row1][col1],matrix2[row2][col2], int result[row1][col1])
		}
		if (operation[0] == 'FD' || operation[0] == 'fd') {
			printf("Enter name of file \n");
			char name[100];
			int row[20];
			int col[20];
			double scalar[20];
			scanf("%s", name);
			printf("How many rows? \n");
			scanf("%d", row);
			printf("How many columns? \n");
			scanf("%d", col);
			FILE* file;
			file = fopen(name, "r");
			int num = 0;
			double matrix[row][col];
			double result[row][col];
			for (int i = 0; i < row[0]; i++) {
				for (int j = 0; j < col[0]; j++) {
					fscanf(file, "%d", &num);
					matrix[i][j] = num;
				}
			}
			fclose(file);
			result = findDeterminant(result, matrix);
			printMatrix(row, col, matrix);
		}
		if (operation[0] == 'FI' || operation[0] == 'fi') {
			printf("Enter name of file \n");
			char name[100];
			int row[20];
			int col[20];
			double scalar[20];
			scanf("%s", name);
			printf("How many rows? \n");
			scanf("%d", row);
			printf("How many columns? \n");
			scanf("%d", col);
			FILE* file;
			file = fopen(name, "r");
			int num = 0;
			double matrix[row][col];
			double result[row][col];
			for (int i = 0; i < row[0]; i++) {
				for (int j = 0; j < col[0]; j++) {
					fscanf(file, "%d", &num);
					matrix[i][j] = num;
				}
			}
			fclose(file);
			findInverse(row, matrix, result);
			printMatrix(row, col, result);
		}
		if (operation[0] == 'TM' || operation[0] == 'tm') {

			printf("Enter name of file \n");
			char name[100];
			int row[20];
			int col[20];
			double scalar[20];
			scanf("%s", name);
			printf("How many rows? \n");
			scanf("%d", row);
			printf("How many columns? \n");
			scanf("%d", col);
			FILE* file;
			file = fopen(name, "r");
			int num = 0;
			double matrix[row][col];
			double result[row][col];
			for (int i = 0; i < row[0]; i++) {
				for (int j = 0; j < col[0]; j++) {
					fscanf(file, "%d", &num);
					matrix[i][j] = num;
				}
			}
			fclose(file);
			transposeMatrix(col, row, matrix, result);
			printMatrix(row, col, result);
		}
	}


	return(0);
}