#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

//EX07 - Vetor em ordem crescente

int main () {
	setlocale(0, "Portuguese");
	int num[100], aux, i, j;

	//Randomizar os números	
	srand(time(NULL));
	
	//Atribuir números aleatórios ao vetor
	for (i = 0; i < 100; i++) 
		num[i] = rand() % 100;
	
	//Printar o vetor na ordem gerada
	printf("\nDesordenado\n");
	for (i = 0; i < 99; i++)
		printf("%d, ", num[i]);
	
	printf("%d.\n", num[i]);
	
	//Ordenar os números
	for (i = 0; i < 100; i++) {
		for (j = 0; j < 100; j++) {
			if (num[i] < num[j]) {
				aux = num[i];
				num[i] = num[j];
				num[j] = aux;
			}
		}
	}
	
	//Printar os números em ordem crescente
	printf("\nOrdem Crescente\n");
	for (i = 0; i < 99; i++) {
		printf("%d, ", num[i]);
	}
	printf("%d.\n", num[i]);
}
