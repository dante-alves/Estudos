#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <string.h>

//EX11 - Diagonal principal de uma matriz

int main () {
	setlocale(0, "Portuguese");
	int tam = 5;
	int m[tam][tam];
	int l, c;
	char espaco[50] = {"   "};
		
	srand(time(NULL));
	
	printf("\nMATRIZ\n");
	for (l = 0; l < tam; l++) {
		for (c = 0; c < tam; c++) {
			m[l][c] = rand() % 10;
			printf("%2d ", m[l][c]);
		}
		printf("\n");
	}
	
	/*Forma que pensei
	printf("\nDIAGONAL PRINCIPAL\n");
	c = 0;
	for (l = 0; l < tam; l++) {
			printf("%2d", m[l][c]);
			printf("\n");
			printf("%s", espaco);
			c++;
			strcat(espaco, "   ");
	}*/
	
	//Outra forma
	for (l = 0; l < tam; l++) {
		for (c = 0; c < tam; c++) {
			if (l == c)
				printf("%2d ", m[l][c]);
			else 
				printf("   ");
		}
		printf("\n");
	}
	
	printf("\n\nValores da diagonal principal: ");
	for (l = 0; l < tam; l++)
		printf("%d ", m[l][l]);
		
	return 0;
}
