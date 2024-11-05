#include <stdio.h>
#include <stdlib.h>
//EX02 - Faça um programa em C que crie (com alocação dinâmica), preencha com os dados obtidos do teclado e imprima o vetor representado abaixo:
/*	1 2 3 4 5 6 7 8 9 10
	0 1 2 3 4 5 6 7 8 9
*/

int main(){
	int tam = 2;
	int *vet, i;
	
	vet = (int *)malloc(tam * sizeof(int));
	
	if(vet){
		for(i = 0; i < tam; i++){
			printf("Digite o valor na posicao %d: ", i);
			scanf("%d", &*(vet + i));
		}
		
		for(i = 0; i < tam; i++){
			printf("\n\nValor na posicao %d: %d", i, vet[i]);
		}
		free(vet);
	}
	else
		printf("Erro na alocação de memória! :(");

	
	int *vet2, *vet3;
	
	vet2 = (int *)malloc(tam * sizeof(int));
	vet3 = (int *)calloc(tam, sizeof(int));
	
	printf("\n\nVetor com malloc: ");
	for(i = 0; i < tam; i++){
		printf("%d ", vet2[i]);
	}
	
	printf("\n\nVetor com calloc: ");
	for(i = 0; i < tam; i++){
		printf("%d ", vet3[i]);
	}
	
	return 0;	
}
