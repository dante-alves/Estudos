#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

//EX13 - Transposta de uma Matriz - A tranposta é outra matriz que tem as linhas n

int main () {
	int tamL = 5, tamC = 4;
	int m[tamL][tamC], mT[tamC][tamL], l, c;
	
	srand(time(NULL));
	
	printf("\n MATRIZ\n");
	for (l = 0; l < tamL; l++) {
		for (c = 0; c < tamC; c++) {
			m[l][c] = rand() % 10;
			printf("%2d ", m[l][c]);
		}
		printf("\n");
	}
	
	printf("\n\n TRANSPOSTA\n");
	
	/*for (l = 0; l < tamL; l++) {
		for (c = 0; c < tamC; c++) 
			mT[c][l] = m[l][c];
	}
	
	for (l = 0; l < tamC; l++) {
		for (c = 0; c < tamL; c++) {
			printf("%2d ", mT[l][c]);
		}
		printf("\n");
	} 
	*/
	
	//Forma que já atribui o valor e printa direto
	for (l = 0; l < tamC; l++) {
		for (c = 0; c < tamL; c++) {
			mT[l][c] = m[c][l];
			printf("%2d ", mT[l][c]);
		}
		printf("\n");
		
	}
}
