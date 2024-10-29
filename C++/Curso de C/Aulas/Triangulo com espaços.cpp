#include <stdio.h>
#include <stdlib.h>

//Aula 171 - Tri�ngulo com espa�os do lado esquerdo

int main(){
	int i, l, j;
	
	//Imprimir o tri�ngulo
	for (l = 1; l <= 8; l++){
		for (i = 1; i <= l; i++)
			printf("*");
		printf("\n"); //Pular pra pr�xima linha
	}
	
	printf("\n\n\n");
	
	//Tri�ngulo invertido
	printf("Triangulo invertido:\n\n");
	
	//Imprimir o tri�ngulo invertido
	for (l = 1; l <= 8; l++){
		
		//Adicionar os espa�os equivalentes a cada linha (na primeira, 8 espa�os, na segunda, 7 espa�os, e assim sucessivamente)
		for (j = 7; j >= l; j--){
				printf(" ");
		}
		
		//Imprimir o tri�ngulo
		for (i = 1; i <= l; i++)
			printf("*");
		printf("\n");
	}
	
}
