#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

//EX12 - Diagonal secundaria de uma matriz 7 X 7

int main () {
	int tam = 7;
	int mat[tam][tam], l, c;
	
	srand(time(NULL));
	
	printf("\nMATRIZ\n");
	for (l = 0; l < tam; l++) {
		for (c = 0; c < tam; c++) {
			mat[l][c] = rand() % 10;
			printf("%2d ", mat[l][c]);
		}
		printf("\n");
	}
	
	printf("\nDIAGONAL SECUNDARIA\n");
	for (l = 0; l < tam; l++) {
		for (c = 0; c < tam; c++){
			if (l + 1 + c == tam)
				printf("%2d", mat[l][c]);
			else
				printf("   ");	
		}
		printf("\n");
	}
	
	printf("\n\nValores da diagonal secundaria: ");
	for (l = 0; l < tam; l++)
		printf("%d ", mat[l][tam - 1 - l]);
}
