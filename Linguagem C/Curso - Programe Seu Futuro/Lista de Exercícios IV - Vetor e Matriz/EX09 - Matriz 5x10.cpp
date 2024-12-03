#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

//EX09 - Matriz 5x10

int main () {
	int mat[5][10], somaL[5], somaC[10];
	int l, c;
	
	srand(time(NULL));
	
	for (l = 0; l < 5; l++) {
		for (c = 0; c < 10; c++){
			mat[l][c] = rand() % 10;
			printf("%2d ", mat[l][c]);
		}
		printf("\n");
	}
	
	//Somar os valores de cada linha	
	for (l = 0; l < 5; l++) {
		somaL[l] = 0;
		for (c = 0; c < 10; c++){
			somaL[l] += mat[l][c];
		}
		printf("\nSoma da linha %d: %d", l, somaL[l]);
	}
	printf("\n\n------------------------------------\n");
	//Somar os valores de cada coluna
	for (c = 0; c < 10; c++) {
		somaC[c] = 0;
		for (l = 0; l < 5; l++) {
			somaC[c] += mat[l][c];
		}
		printf("\nSoma da coluna %d: %d", c, somaC[c]);
	}
}
