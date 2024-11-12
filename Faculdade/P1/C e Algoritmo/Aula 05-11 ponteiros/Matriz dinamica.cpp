#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	int i;
	int linha = 3, coluna = 2;
	int l, c;
	
	srand(time(NULL));	
	
	printf("Insira quantas linhas a matriz terá: ");
	scanf("%d", &linha);
	
	printf("Insira quantas colunas a matriz terá: ");
	scanf("%d", &coluna);	
	
	//Alocando as linhas
	int **mat = (int **)malloc(linha * sizeof(int *));
	
	for(l = 0; l < linha; l++){
		//Alocando as colunas
		mat[l] = (int *)malloc(coluna * sizeof(int));
		
		//Atribuindo valores
		for(c = 0; c < coluna; c++)
			*(*(mat + l) + c) = rand() % 100;
	}
	
	//Printar a matriz
	for(l = 0; l < linha; l++){
		for(c = 0; c < coluna; c++)
			printf("%2d ", *(*(mat + l) + c));
		
		printf("\n");
	}
	
	//Liberar a memória
	if(mat != NULL){
		for(l = 0; l < linha; l++){
			if(mat != NULL)
				free(*(mat + l));
		}
		free(mat);	
	}
	
	return 0;
}
