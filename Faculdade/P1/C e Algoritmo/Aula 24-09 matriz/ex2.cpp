#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main () {
	setlocale(0, "Portuguese");
	
	int matriz1[3][3];
	int i = 0, j = 0;
	
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
		
			printf("Insira um valor: ");
			scanf("%d", &matriz1[i][j]);
		}
	} 
	
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 2; j++) {
			printf("%d - ", matriz1[i][j]);
		}
		
		printf("%d\n", matriz1[i][j]);
	} 
}
