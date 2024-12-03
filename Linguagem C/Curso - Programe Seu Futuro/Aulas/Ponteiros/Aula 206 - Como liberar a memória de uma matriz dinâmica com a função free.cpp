#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Aula 206 Como liberar a memória de uma matriz dinâmica com a função free?

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
	
	//Liberando a memória
	
	//Primeiro, libera cada linha da matriz
	for(i = 0; i < 4; i++)
		free(m[i]);
	
	//Por fim, libera a variável ponteiro para ponteiro
	free(m);
	
	
}
