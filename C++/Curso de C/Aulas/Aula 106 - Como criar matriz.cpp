#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

//Aula 106 - Como criar matriz

int main () {
	int mat[2][2];
	int mat1[2][2] = {1, 2, 3, 4};
	int mat2[][3] = {1,2,3,4,5,6,7,8,9}; //Se não informa a quantidade de colunas e linhas, tem que colocar os valores, que aí automaticamente o computador vai definir quantas linhas ou colunas são. 
	// E se tivesse por exemplo até o valor 7, o programa iria definir 3 linhas e 3 colunas, mas o 8 e 9 seriam preenchidos por 0.
	
	int  mat3[3][3] = {0}; //Nesse caso, as 3 linhas e 3 colunas serão preenchidos com 0 automaticamente.
	
	for (int i = 0; i < 2; i++){
		for (int c = 0; c < 2; c++)
		printf("%d ", mat1[i][c]);
		
		printf("\n");
	}
	//Como adicionar valores aleatórios à matriz
	
	srand(time(NULL));
	for (int f = 0; f < 3; f++) {
		for (int j = 0; j < 3; j++) {
			mat3[f][j] = rand() % 100;
			printf ("%d ", mat3[f][j]);
		}
		printf("\n");
	}
}
