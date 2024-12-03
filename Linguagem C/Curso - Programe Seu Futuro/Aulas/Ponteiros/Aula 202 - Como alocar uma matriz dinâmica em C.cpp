#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Aula 202 - Como alocar uma matriz dinâmica em C

	vetor de vetores-> int* -> 10 27 30
					   int* -> 11 75 49
					   int* -> 43 82 10
					   int* -> 12 47 62

*/

int main(){
	int **mat, i, j;
	
	mat = (int **)malloc(4 * sizeof(int*)); //4 linhas
	
	for(i = 0; i < 4; i++)
		mat[i] = (int *)malloc(3 * sizeof(int)); //3 colunas
		
	srand(time(NULL));
	
	for(i = 0; i < 4; i++){
		for(j = 0; j < 3; j++){
			*((*mat + i)+ j) = rand() % 100; //Com aritmética de ponteiros
			//ou mat[i][j] = rand() % 100;
		}
	}
	
	for(i = 0; i < 4; i++){
		for(j = 0; j < 3; j++){
			printf("%2d ",*((*mat + i)+ j)); //Com aritmética de ponteiros
			//ou printf("%2d ", mat[i][j]);
		}
		printf("\n");
	}
	return 0;
}
