#include <stdio.h>
#include <stdlib.h>

//Aula 171 - Triângulo com espaços do lado esquerdo

int main(){
	int i, l, j;
	
	//Imprimir o triângulo
	for (l = 1; l <= 8; l++){
		for (i = 1; i <= l; i++)
			printf("*");
		printf("\n"); //Pular pra próxima linha
	}
	
	printf("\n\n\n");
	
	//Triângulo invertido
	printf("Triangulo invertido:\n\n");
	
	//Imprimir o triângulo invertido
	for (l = 1; l <= 8; l++){
		
		//Adicionar os espaços equivalentes a cada linha (na primeira, 8 espaços, na segunda, 7 espaços, e assim sucessivamente)
		for (j = 7; j >= l; j--){
				printf(" ");
		}
		
		//Imprimir o triângulo
		for (i = 1; i <= l; i++)
			printf("*");
		printf("\n");
	}
	
}
