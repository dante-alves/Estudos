#include <stdio.h>
#include <locale.h>

/*EX08 - Solução
Escreva um algoritmo em C que faça a apresentação formatada de:
a) um quadrado de tamanho 5x5. Exemplo:
X X X X X
X X X X X
X X X X X
X X X X X
X X X X X
b) Pergunte ao usuário qual o tamanho do quadrado que ele quer que
seja desenhado, e o desenhe.
*/

int main(){
	setlocale(0, "Portuguese");
	int tam = 5;
	int l, c;
	
	//A) Gerar o quadrado 5x5
	printf("Quadrado 5x5\n\n");
	for(l = 0; l < tam; l++) {
		printf("\t");
		for(c = 0; c < tam - 1; c++)
			printf("X ");
		printf("X\n");
	}
	
	//B) Perguntar qual tamanho quer que o quadrado tenha
	printf("\nQual tamanho você deseja que o quadrado possua? ");
	scanf("%d", &tam);
	
	//Gerar o quadrado do tamanho escolhido
	printf("\nQuadrado %dx%d\n\n", tam, tam);
	for(l = 0; l < tam; l++) {
		printf("\t");
		for(c = 0; c < tam - 1; c++)
			printf("X ");
		printf("X\n");
	}
	return 0;
}

