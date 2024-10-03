#include <stdio.h>
#include <locale.h>
/*EX09 - Solução
Gere uma matriz 3x4 de inteiros, e peça para o usuário do programa
preenchê-la. Após preenchida,
a) Informe qual foi o maior número encontrado na matriz.
b) Informe qual foi o menor número encontrado na matriz.
*/

int main(){
	setlocale(0, "Portuguese");
	int m[3][4] = {0};
	int maior = m[0][0], menor = 2147483647, l, c;
	
	//Ler os valores da matriz e verificar o maior e menor valor.
	for(l = 0; l < 3; l++) {
		for(c = 0; c < 4; c++) {
			printf("Insira o valor na posição [%d][%d]: ", l, c);
			scanf("%d", &m[l][c]);
			//Pegar o maior valor
			if (m[l][c] > maior)
				maior = m[l][c];
			//Pegar o menor valor
			if (m[l][c] < menor)
				menor = m[l][c];
		}
	}
	//Printar a matriz que foi definida
	printf("\nMatriz\n");
	for(l = 0; l < 3; l++){
		for(c = 0; c < 3; c++) 
			printf("%2d ", m[l][c]);
		printf("%2d\n", m[l][c]);
	}
	
	//A) e B) - Informando o maior e menor valor
	printf("\nO maior número encontrado na matriz foi %d, enquanto o menor foi %d.", maior, menor);
	return 0;
}

