#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

/*Faça uma função recursiva que permita somar os elementos de um vetor de
inteiros.*/
int somaVet(int vet[], int i){
	if(i == 0)
		return vet[i];
	else
		return vet[i] + somaVet(vet, i - 1);
}

int main(){
	setlocale(0, "Portuguese");
	
	int vet[10], i;
	
	srand(time(NULL));
	
	printf("Vetor: ");
	
	for(i = 0; i < 10; i++){
		vet[i] = rand() % 10;
		printf("%d ", vet[i]);
	}
	
	printf("\nSoma do Vetor: %d", somaVet(vet, i - 1));
	
	return 0;
}
