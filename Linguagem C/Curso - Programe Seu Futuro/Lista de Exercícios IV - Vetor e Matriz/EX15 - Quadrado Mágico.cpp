#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

//EX15 - Quadrado M�gico

int main () {
	setlocale(0, "Portuguese");
	int tam = 4;
	int mat[tam][tam], l, c, soma = 0, verificador = 0, teste = 0, valor[] = {8, 3, 4, 1, 5, 9, 6, 7, 2}, indice = 0, total = tam * 2 + 2;
	
	/*Adicionando os valores � matriz, pois n�o posso adicionar diretamente na declara��o de mat[tam][tam].
	(VALOREZ DE UMA MATRIZ DE TESTE QUE � UM QUADRADO M�GICO.)
	for (l = 0; l < tam; l++) {
		for (c = 0; c < tam; c++) {
			mat[l][c] = valor[indice++];
		}
	}*/
	
	srand(time(NULL));
	
	//Atribuir os valores e printar a matriz
	for (l = 0; l < tam; l++) {
		for (c = 0; c < tam; c++) {
			mat[l][c] = rand() % 10;
			printf("%d ", mat[l][c]);
		}
		printf("\n");
	}
	//Atribuir o valor da soma de uma linha
	for (c = 0; c < tam; c++){
		soma += mat[0][c];
	}
	
	//Testar se as linhas tem soma igual
	for (l = 0; l < tam; l++){
		teste = 0;
		for (c = 0; c < tam; c++) {
			teste += mat[l][c];
		}
		if (teste == soma)
			verificador++;
	}
	
	//Testar se as colunas tem soma igual
	for (c = 0; c < tam; c++) {
		teste = 0;
		for (l = 0; l < tam; l++){
			teste += mat[l][c];
		}
		if (teste == soma)
			verificador++;
	}
	
	//Testar se a diagonal principal tem soma igual
	teste = 0;
	for (l = 0; l < tam; l++){
		teste += mat[l][l];
	}
	if (teste == soma) {
		verificador++; 
	}
	//Testar se a diagonal secund�ria tem soma igual
	teste = 0;
	for (l = 0; l < tam; l++) {
		teste += mat[l][tam - l - 1];
	}
	if (teste == soma){
		verificador++;
	}
	
	if (verificador == total) {
		printf("\nA matriz � um Quadrado M�gico.");
		printf("\n\nSoma de cada linha, coluna e diagonal: %d\n", soma);
	}
	else {
		printf("\nA matriz N�O � um Quadrado M�gico.");
		printf("\n\nA Soma de cada linha, coluna e diagonal n�o � igual.");
	}
	
	
	return 0;
}
