#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <math.h>

//EX01 - Vetor e Quadrado do Vetor 

int main () {
	setlocale(LC_ALL, "Portuguese");
	int i, vet1[10], vet2[10];
	
	//Coletar os valores
	for (i = 0; i < 10; i++) {
		printf("Insira o valor na posição %d: ", i);
		scanf("%d", &vet1[i]);
		
		//Valores ao quadrado 
		vet2[i] = pow(vet1[i], 2);
	}
	
	printf ("Vetor 1: ");
	for (i = 0; i < 10; i++) {
		printf("%3d ", vet1[i]);
	}
	
	printf("\nVetor 2: ");
	for (i = 0; i < 10; i++) {
		printf("%3d ", vet2[i]);
	}
	
	return 0;
}
