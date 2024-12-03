#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

//EX10 - 3 Matrizes 3x3

int main () {
	setlocale(0, "Portuguese");
	
	int A[3][3], B[3][3], C[3][3];
	int l, c;
	
	srand(time(NULL));
	//Matriz A
	printf("Matriz A\n");
	for (l = 0; l < 3; l++) {
		for (c = 0; c < 3; c++){
			A[l][c] = rand() % 10;
			printf("%2d ", A[l][c]);
		}
		printf("\n");
	}

	printf("\nMatriz B\n");
	//Matriz B
	for (l = 0; l < 3; l++) {
		for (c = 0; c < 3; c++){
			B[l][c] = rand() % 10;
			printf("%2d ", B[l][c]);
		}
		printf("\n");
	}
	
	printf("\nMatriz C\n");
	//Matriz C
	for (l = 0; l < 3; l++) {
		for (c = 0; c < 3; c++){
			C[l][c] = A[l][c] + B[l][c];
			printf("%2d ", C[l][c]);
		}
		printf("\n");
	}
}
