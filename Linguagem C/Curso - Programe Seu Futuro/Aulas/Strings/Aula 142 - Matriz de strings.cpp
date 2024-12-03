#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

//Aula 142 - Matriz de strings

int main() {
	setlocale(0, "Portuguese");
	char nomes[5][25];
	int l;
	for (l = 0; l < 5; l++){
		printf("Digite o %dº nome: ", l + 1);
		scanf("%25[^\n]", nomes[l])	;
		scanf("%c");
	}
	
	for(l = 0; l < 5; l++){
		printf("\nNome %d: %s", l + 1, nomes[l]);
	}
	return 0;
}
