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
	
	//Removendo os espa�os da frase
	for (i = 0; i < tam; i++) {
		if (frase[i] != ' ')
			frase[j++] = frase[i];
	}
	frase[j] = '\0';
	
	/* OUTRA FORMA COM DUAS VARI�VEIS
	for (i = 0; i < tam; i++) {
		if (frase[i] != ' ')
			copia[j++] = frase[i];
	}
	copia[j] = '\0';*/
	
	
	//Redefinindo o tamanho sem espa�os agora
	tam = strlen(frase);
	
	j = tam - 1;
	
	//Printando letra por letra e verificando se � pal�ndromo
	for (i = 0; i < tam; i++) { 
	
		printf("\n%c | %c" , frase[i], frase[j]);
		
		if (frase[i] != frase[j])
			palindromo = 1;
		j--;
	}


	if (palindromo == 0)
		printf("\n\nA frase � um pal�ndromo.");
	else 
		printf("\n\nA frase n�o � um pal�ndromo.");
	
	return 0;
}
