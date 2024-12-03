#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

//EX03 - Trocar os últimos valores pelos primeiros no vetor

int main () {
	setlocale(LC_ALL, "Portuguese");
	int i, aux, fim = 19, N[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20}, auxi[20];


	printf("Vetor antes da alteração: ");
	for (i = 0; i < 20; i++) {
		printf("%d ", N[i]);
	}
	
//Formas que mais gostei	
	printf("\n\nVetor após a alteração: ");
	for (i = 0; i < 10; i++) {
		aux = N[i];
		N[i] = N[fim];
		N[fim] = aux;
		fim --;
	}
	for (i = 0; i < 20; i++) {
		printf("%d ", N[i]);
	}
	
//Formas que mais gostei
	printf("\n\nVetor após a alteração: ");
	for (i = 0; i < 10; i++) {
		aux = N[i];
		N[i] = N[19 - i];
		N[19 - i] = aux;
		printf("%d ", N[i]);
	}
	for (i = 10; i < 20; i++) {
		printf("%d ", N[i]);
	}
	
/*	ESSE JEITO FOI GAMBIARRA, NÃO VALE	
	printf("\n\nVetor após a alteração: ");
	for (i =19; i >= 0; i--) {
		printf ("%d ", N[i]);
	}
*/ 	

	/*printf("\n\nVetor após a alteração: ");
	for (i = 0; i < 10; i++) {
		auxi[i] = N[i];
		N[i] = N[19 - i];
		printf ("%d ", N[i]);
	}
	for (i = 10; i < 20; i++) {
		N[i] = auxi[19 - i];
		printf ("%d ", N[i]);
	}*/
	
}
