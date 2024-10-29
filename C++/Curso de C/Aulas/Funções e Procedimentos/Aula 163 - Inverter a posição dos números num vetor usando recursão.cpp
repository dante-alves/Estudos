#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Aula 163 - Inverter a posição dos números num vetor usando recursão

void imprimir(int v[], int i) {
	if (i == 0)
		printf("%d, ", v[i]);
	else {
		imprimir(v, i - 1);
		printf("%d, ", v[i]);
	}
}

void inverter(int v[], int inicio, int fim) {
	int aux;
	
	if (inicio < fim){
		aux = v[inicio];
		v[inicio] = v[fim];
		v[fim] = aux;
		inverter(v, inicio+1, fim-1);
	}
	
}


int main() {
	setlocale(LC_ALL, "Portuguese");
	int v[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	
	
	printf("Vetor original: ");
	imprimir(v, 9);
	
	inverter (v, 0, 9);
	
	printf("\nVetor invertido: ");
	imprimir(v, 9);
	return 0;
}
