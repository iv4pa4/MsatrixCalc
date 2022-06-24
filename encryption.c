#include <stdio.h>
#include <stdlib.h>

void encryption(char* inputFile, char* outputFile) {
	char ch;
	int num = 0;
	FILE* f1, * f2;
	f1 = fopen(inputFile, "r");

	if (f1 == NULL) {
		printf("Not such a file...\n");
		exit(0);
	}
	else {
		f2 = fopen(outputFile, "w");
		ch = fgetc(f1);
		while (ch != EOF) {
			num = (int)ch;
			num = num + 23;
			fprintf(f2, "%c", num);
			ch = fgetc(f1);
		}
		fclose(f2);
	}
	fclose(f1);
}

void decryption(char* inputFile, char* outputFile) {
	char ch;
	int num = 0;
	FILE* f1, * f2;
	f1 = fopen(inputFile, "r");

	if (f1 == NULL) {
		printf("Not such a file...\n");
		exit(0);
	}
	else {
		f2 = fopen(outputFile, "w");
		ch = fgetc(f1);
		while (ch != EOF) {
			num = (int)ch;
			num = num  - 23;
			fprintf(f2, "%c", num);
			ch = fgetc(f1);
		}
		fclose(f2);
	}
	fclose(f1);
}



int main(void) {
	
	char inputFile[20];
	char outputFile[20];
	char ch;
	int num = 0;

	printf("Enter your input file name\n");
	scanf("%s", inputFile);
	printf("Enter your output file name\n");
	scanf("%s", outputFile);
	//encryption(inputFile, outputFile);
	decryption(inputFile, outputFile);
	
	
}