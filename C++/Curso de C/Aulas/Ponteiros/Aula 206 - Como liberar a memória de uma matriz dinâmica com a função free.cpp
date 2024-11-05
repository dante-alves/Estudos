#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Aula 206 Como liberar a mem�ria de uma matriz din�mica com a fun��o free?

int main(){
	int **m;
	int i, j;
	
	m = (int **) malloc(4 * sizeof(int*));
	
	for(i = 0; i < 4; i++)
		*(m + i) = (int *) malloc(3 * sizeof(int));
	
	srand(time(NULL));
	
	for(i = 0; i < 4; i++){
		for(j = 0; j < 3; j++)
			*((*m + i) + j) = rand() % 100;
	}
	
	for(i = 0; i < 4; i++){
		for(j = 0; j < 3; j++)
			printf("%2d ", *((*m + i) + j));
		printf("\n");
	}
	
	//Liberando a mem�ria
	
	//Primeiro, libera cada linha da matriz
	for(i = 0; i < 4; i++)
		free(m[i]);
	
	//Por fim, libera a vari�vel ponteiro para ponteiro
	free(m);
	
	
}
