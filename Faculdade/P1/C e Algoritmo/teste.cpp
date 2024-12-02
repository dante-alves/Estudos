#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*  10. Escreva um programa em C, com alocação de memória totalmente
dinâmica, para armazenar strings em uma matriz. Você deve capturar
do teclado o tamanho da maior string a ser armazenada e as dimensões
da matriz. Por exemplo, a maior string terá 124 caracteres e a matriz
será de 4x5  */

typedef struct{
	char string[124];
}t_String;

int main(){
	setlocale(0, "Portuguese");
	int l, c;
	
	// alocando as linhas -> 4 linhas
	t_String **matriz = (t_String **)malloc(sizeof(t_String*) * 4);
	
	for(l = 0; l < 4; l++)
		// alocando as colunas -> 5 colunas
		matriz[l] = (t_String *)malloc(sizeof(t_String) * 5);
	
	// ler os textos
	for(l = 0; l < 4; l++){
		for(c = 0; c < 5; c++){
			printf("Digite um texto: ");
			scanf("%124[^\n]", matriz[l][c].string);
			fflush(stdin);
		}
	}
	// limpar o terminal
	system("cls");
	
	// imprimir os textos
	for(l = 0; l < 4; l++){
		for(c = 0; c < 5; c++)
			printf("%s\n", matriz[l][c].string);
		
	}
	
	free(matriz);
	
	return 0;
}
