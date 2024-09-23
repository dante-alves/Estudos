#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <math.h>

//EX02 - Soma de vetores aleatórios

int main () {
	setlocale(LC_ALL, "Portuguese");
	int i, vet1[25], vet2[25], vet3[25];
	
	//Gerar os valores aleatórios
	srand(time(NULL));
	for (i = 0; i < 25; i++) {
		//Primeiro Vetor
		vet1[i] = rand() % 100;
		
		//Segundo Vetor
		vet2[i] = rand() % 100;
		
		//Terceiro Vetor
		vet3[i] = vet1[i] + vet2[i];
	}
	
	printf ("Vetor 1: ");
	for (i = 0; i < 25; i++) {
		printf("%5d ", vet1[i]);
	}
	
	printf("\n\nVetor 2: ");
	for (i = 0; i < 25; i++) {
		printf("%5d ", vet2[i]);
	}
	
	printf("\n\nVetor 3: ");
	for (i = 0; i < 25; i++) {
		printf("%5d ", vet3[i]);
	}
	
	return 0;
}
