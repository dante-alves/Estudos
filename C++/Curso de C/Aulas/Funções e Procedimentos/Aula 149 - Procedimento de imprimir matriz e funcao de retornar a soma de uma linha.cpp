#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

//Aula 149 e 150 - Procedimento de imprimir matriz e fun��o de retornar a soma de uma linha e uma coluna da matriz

//Definindo o tamanho
int tam = 5;
	//Eu tamb�m poderia definir a matriz como global aqui, e a� n�o precisaria pass�-la como par�metro nas fun��es.

//Procedimento para gerar e imprimir a matriz
void gerarMatriz(int mat[][5]) {
	
	srand(time(NULL));
	
	for (int l = 0; l < tam; l++){
		for (int c = 0; c < tam; c++) {
			mat[l][c] = rand() % 10;
			printf("%3d ", mat[l][c]);
		}
		printf("\n");
	}
}

//Fun��o para retornar a soma da linha
int somaLinha(int mat[][5], int linha) {
	int l = linha, soma = 0;
	
	for (int c = 0; c < tam; c++) {
		soma += mat[l][c];
	}
	return soma;
}

//Fun��o para retornar a soma da coluna
int somaColuna(int mat[][5], int coluna) {
	
	int c = coluna, soma = 0;
	
	for (int l = 0; l < tam; l++) {
		soma += mat[l][c];
	}
	return soma;
}

int main() {
	setlocale(0, "Portuguese");

	int mat[5][5], escolha, resultado;
	
	//Procedimento para gerar e imprimir a matriz
	gerarMatriz(mat);
	
	//Qual linha para retornar a soma
	printf("\nDe qual linha voc� gostaria de obter a soma (de 0 a 4)? ");
	scanf("%d", &escolha);
	
	//Fun��o para retornar a soma da linha
	resultado = somaLinha(mat, escolha);

	printf("\nA soma da linha %d totaliza %d.", escolha, resultado);
	
	//Qual coluna para retornar a soma
	printf("\n\nE de qual coluna voc� gostaria de obter a soma (de 0 a 4)? ");
	scanf("%d", &escolha);
	
	//Fun��o para retornar a soma da coluna
	resultado = somaColuna(mat, escolha);
	
	printf("\nA soma da coluna %d totaliza %d.", escolha, resultado);
	return 0;
}
