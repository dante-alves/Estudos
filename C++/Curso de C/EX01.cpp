#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*EX01 - Escreva um procedimento que receba um vetor inteiro, seu tamanho e os endereços de duas
		variáveis inteiras, menor e maior, salve nestas variáveis o menor e o maior valor do vetor.
*/

//Procedimento para inicializar o vetor com números aleatórios
void inicializarVetor(int vet[], int tam){
	int i;
	srand(time(NULL));
	
	for(i = 0; i < tam; i++)
		vet[i] = rand() % 100;
}

//Procedimento para imprimir o vetor
void imprimir(int vet[], int tam){
	int i;
	for(i = 0; i < tam; i++)
		printf("%d ", vet[i]);
	
	printf("\n\n");
}

//Procedimento para identificar o menor e maior valor no vetor
void menorMaior(int vet[], int tam, int *menor, int *maior){
	int i;
	//Inicializando menor e maior com o primeiro valor do vetor
	*menor = vet[0];
	*maior = vet[0];
	
	for(i = 0; i < tam; i++){
		if(vet[i] < *menor)
			*menor = vet[i];
			
		if(vet[i] > *maior)
			*maior = vet[i];
	}
}

int main(){
	int tam = 10;
	int vet[tam], menor, maior;
	
	inicializarVetor(vet, tam);
	
	imprimir(vet, tam);
	
	menorMaior(vet, tam, &menor, &maior);
	
	printf("Menor valor: %d\nMaior valor: %d", menor, maior);
	return 0;
}
