#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*  10. Escreva um programa em C, com aloca��o de mem�ria totalmente
din�mica, para armazenar strings em uma matriz. Voc� deve capturar
do teclado o tamanho da maior string a ser armazenada e as dimens�es
da matriz. Por exemplo, a maior string ter� 124 caracteres e a matriz
ser� de 4x5  */

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
