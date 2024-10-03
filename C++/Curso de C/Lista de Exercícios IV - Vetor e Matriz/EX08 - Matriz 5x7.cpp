#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
//EX08 - Matriz 5x7

int main () {
	int matriz[5][7];
	int linha, coluna, soma = 0;
	
	srand(time(NULL));
	
	for (linha = 0; linha < 5; linha++) {
		for (coluna = 0; coluna < 7; coluna++) {
			
		matriz[linha][coluna] = rand() % 100;
		printf("%2d ", matriz[linha][coluna]);
		}
		printf("\n");
	}
	
	for (linha = 0; linha < 5; linha++) {
		for (coluna = 0; coluna < 7; coluna++) {
			soma += matriz[linha][coluna];
		}
	}
	printf("\nA soma dos valores na matriz e igual a: %d", soma);
}
