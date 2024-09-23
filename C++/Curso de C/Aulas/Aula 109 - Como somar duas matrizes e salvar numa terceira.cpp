#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Aula 109 - Como Somar duas matrizes e salvar numa terceira

int main () {
	int mat1[3][3] = {5, 4, 3, 10,7,15,20,1,2}, mat2[3][3] = {6, 3, 9, 10, 4, 23, 5, 14, 12}, mat3[3][3];
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			
			mat3[i][j] = mat1[i][j] + mat2[i][j];
			
			printf("%d ", mat3[i][j]);
		}
		printf("\n");
	}
}
