#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

/*EX07 - Crie um programa em C que receba um vetor de números reais com 100 elementos.
Escreva uma função recursiva que inverta ordem dos elementos presentes no vetor.*/

void imprimeInvertido(int vet[], int i){
	
	if(i == 0)
		printf("%d ", vet[i]);
	else{
		printf("%d ", vet[i]);
		imprimeInvertido(vet, i - 1);
	}
}

void inverteVetor(int vet[], int fim){
	int aux, i = 0;
	if(i >= fim)
	        return;
	        
        aux = vet[i];
        vet[i] = vet[fim];
	vet[fim] = aux; 
	
	inverteVetor(vet, i++, fim--);	
}

int main(){
	int tam = 10;
	int vet[tam];
	int i;	
	
	srand(time(NULL));
	
	for(i = 0; i < tam; i++)
		vet[i] = rand() % 100;
	
	int fim = i - 1;
	
	printf("Vetor original: ");
	for(i = 0; i < tam; i++)
		printf("%d ", vet[i]);
	
	
	printf("\nVetor invertido: ");
	
	imprimeInvertido(vet, i - 1);
	
	inverteVetor(vet, fim);
	
	printf("\nVetor invertidasso: ");
	for(i = 0; i < tam; i++)
		printf("%d ", vet[i]);
	
	return 0;
}
