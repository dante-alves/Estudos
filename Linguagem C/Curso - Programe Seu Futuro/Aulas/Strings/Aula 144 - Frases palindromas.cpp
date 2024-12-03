#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

/*Aula 144 - Frases palindromas
- subi no onibus
- a grama e amarga
- a mae te ama
*/

int main() {
	setlocale(0, "Portuguese");
	
	char frase[100] = {"subi no onibus"}, copia[100];
	char *ptr;
	int tam, i, j = 0, palindromo = 0;

	tam = strlen(frase);
	printf("%s\n", frase);
	
	//Removendo os espaços da frase
	for (i = 0; i < tam; i++) {
		if (frase[i] != ' ')
			frase[j++] = frase[i];
	}
	frase[j] = '\0';
	
	/* OUTRA FORMA COM DUAS VARIÁVEIS
	for (i = 0; i < tam; i++) {
		if (frase[i] != ' ')
			copia[j++] = frase[i];
	}
	copia[j] = '\0';*/
	
	
	//Redefinindo o tamanho sem espaços agora
	tam = strlen(frase);
	
	j = tam - 1;
	
	//Printando letra por letra e verificando se é palíndromo
	for (i = 0; i < tam; i++) { 
	
		printf("\n%c | %c" , frase[i], frase[j]);
		
		if (frase[i] != frase[j])
			palindromo = 1;
		j--;
	}


	if (palindromo == 0)
		printf("\n\nA frase é um palíndromo.");
	else 
		printf("\n\nA frase não é um palíndromo.");
	
	return 0;
}
