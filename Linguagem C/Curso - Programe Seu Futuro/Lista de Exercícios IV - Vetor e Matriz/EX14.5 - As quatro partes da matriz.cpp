#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

//EX14.5 - As quatro partes da matriz

/*	  0  1  2  3
	0 1  2  3  4
	1 5  6  7  8		1,0
	2 9 10 11 12		2,0 ; 2,1
	3 13 14 15 16		3,0 ; 3,1 ; 3,2  
						A coluna é sempre menor que a linha
						
						E acima da diagonal principal?
						0,1 ; 0,2 ; 0,3
						1,2 ; 1,3 ;
						2,3
						A linha é sempre menor que a coluna
*/
int main () {
	int tam = 4;
	int mat[tam][tam], l, c;
	
	setlocale(0, "Portuguese");
	
	srand(time(NULL));
	
	//Atribuir os valores e printar a matriz
	printf("\n MATRIZ\n");
	for (l = 0; l < tam; l++) {
		for (c = 0; c < tam; c++) {
			mat[l][c] = rand() % 10;
			printf("%2d ", mat[l][c]);
		}
		printf("\n");
	}
	//Lógica para mostrar acima da diagonal principal
	printf("\n\nAcima da diagonal principal\n");
	for (l = 0; l < tam; l++) {
		for (c = 0; c < tam; c++) {
			if (l < c) 
				printf("%2d ", mat[l][c]);
			else 
				printf("   ");
		}
		printf("\n");
	}
	
	//Lógica para mostrar a diagonal principal
	printf("\n\n Diagonal Principal\n");
	for (l = 0; l < tam; l++) {
		for (c = 0; c < tam; c++) {
			if (l == c) 
				printf("%2d ", mat[l][c]);
			else 
				printf("   ");
		}
		printf("\n");
	}
	
	//Lógica para mostrar a diagonal secundária
	printf("\n\n Diagonal Secundária\n");
	for (l = 0; l < tam; l++) {
		for (c = 0; c < tam; c++) {
			if (l + 1 + c  == tam) 
				printf("%2d ", mat[l][c]);
			else 
				printf("   ");
		}
		printf("\n");
	}
	
	//Lógica para mostrar abaixo da diagonal principal
	printf("\n\nAbaixo da diagonal principal\n");
	for (l = 0; l < tam; l++) {
		for (c = 0; c < tam; c++) {
			if (c < l) 
				printf("%2d ", mat[l][c]);
			else 
				printf("   ");
		}
		printf("\n");
	}
	
	return 0;
}
