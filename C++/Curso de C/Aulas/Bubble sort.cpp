#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Procedimento para atribuir valores aleatórios ao vetor (não repetidos)
void randomNaoRepetidos(int vet[], int tam){
	int atribui, i = 0, j;
	
	srand(time(NULL));
	
	do{
		atribui = 1;
		vet[i] = rand() % 100;
		
		for(int j = 0; j < i; j++){ // Percorre todo o vetor para verificar se já tem o valor dentro do vetor.
			if(vet[j] == vet[i])
				atribui = 0;
		}
		
		if(atribui == 1)
			i++;
	}while(i < tam);
}

//Procedimento para deixar em ordem crescente por meio do bubbleSort
void bubbleSort(int vet[], int tam){
	int i, troca, aux;
	do{
		troca = 0;
		
		for(i = 0; i < tam - 1; i++){
			if(vet[i] > vet[i + 1]){
				aux = vet[i];
				vet[i] = vet[i + 1];
				vet[i + 1] = aux;
				
				troca = 1;
			}
		}
	}while(troca);
}

int main(){
	int tam = 30;
	int i, vet[tam];

	randomNaoRepetidos(vet, tam);
	
	//Imprimir vetor
	for(i = 0; i < tam; i++)
		printf("%d ", vet[i]);

	bubbleSort(vet, tam);
	
	printf("\n\n");
	
	//Imprimir vetor
	for(i = 0; i < tam; i++)
		printf("%d ", vet[i]);
	
	return 0;
}
