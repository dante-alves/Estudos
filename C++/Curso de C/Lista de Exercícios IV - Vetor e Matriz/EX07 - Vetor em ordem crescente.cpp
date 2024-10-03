#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

//EX07 - Vetor em ordem crescente

int main () {
	setlocale(0, "Portuguese");
	int num[100], aux, i, j, troca, contador = 0;

	//Randomizar os números	
	srand(time(NULL));
	
	//Atribuir números aleatórios ao vetor
	for (i = 0; i < 100; i++) 
		num[i] = rand() % 1000;
	
	//Printar o vetor na ordem gerada
	printf("\nDesordenado\n");
	for (i = 0; i < 99; i++)
		printf("%3d, ", num[i]);
	
	printf("%3d.\n", num[i]);
	
	/*Ordenar os números - A forma que eu descobri mas que me deixa muito confuso:
	for (i = 0; i < 100; i++) {
		for (j = 0; j < 100; j++) {
			contador++;
			if (num[i] < num[j]) {
				aux = num[i];
				num[i] = num[j];
				num[j] = aux;
			}
		}
	}*/
	
	/*
	for (i = 0; i < 99; i++) {
		for (j = 0; j < 100 - i - 1; j++) {
			contador++;
			if (num[j] > num[j + 1]){
				aux = num[j];
				num[j] = num[j + 1];
				num[j + 1] = aux;
			}
		}
	}*/

	
	//Melhor forma: 
	do {
		troca = 0;
		contador++;
		for (i = 0; i < 99; i++) {
			if (num[i] > num[i + 1]) {
				aux = num[i];
				num[i] = num[i + 1];
				num[i + 1] = aux;
				troca = 1;
			}

		}
	} while (troca);
	
	printf("\nContador: %3d\n", contador);
	
	//Printar os números em ordem crescente
	printf("\nOrdem Crescente\n");
	for (i = 0; i < 99; i++) {
		printf("%3d, ", num[i]);
	}
	printf("%3d.\n", num[i]);
}
