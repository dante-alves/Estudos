#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Aula 161 - Como somar os valores de um vetor com Função Recursiva

int soma (int vet[], int i) {
	 if (i == 0)
	 	return vet[i];
	else 
		return vet[i] + soma(vet, i - 1);
}

int main() {
	int vet[5], tam;
	
	for (int i = 0; i < 5; i++) {
		printf("Insira o valor na posicao %d: ", i);
		scanf("%d", &vet[i]);
	}
	
	tam = sizeof(vet) / sizeof(vet[0]);
	
	printf("\n%d\n", tam);
	
	printf("A soma dos valores do vetor eh igual a: %d", soma(vet, tam - 2));
}
