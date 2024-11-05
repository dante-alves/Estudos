#include <stdio.h>
#include <stdlib.h>
//EX01 - Faça um programa em C que crie (com alocação estática), preencha com os dados obtidos do teclado e imprima o vetor representado abaixo:
/*	1 2 3 4 5 6 7 8 9 10
	0 1 2 3 4 5 6 7 8 9
*/

int main(){
	int tam = 10;
	int vet[tam], i;
	
	for(i = 0; i < tam; i++){
		printf("Digite o valor na posicao %d: ", i);
		scanf("%d", &vet[i]);
	}
	
	for(i = 0; i < tam; i++){
		printf("\n\nValor na posicao %d: %d", i, vet[i]);
	}
	
	return 0;	
}
