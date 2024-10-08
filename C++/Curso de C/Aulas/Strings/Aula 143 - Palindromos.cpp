#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

/* Aula 143 - Palíndromos

arara
asa
ama
osso
radar
reviver

*/

int main (){
	setlocale(0, "Portuguese");
	
	//Variáveis
	char palavra[50] = {"arara"};
	int i, j, tam, palindromo = 0;
	
	//Inicializando variáveis
	tam = strlen(palavra);
	j = tam - 1;
		
	/*Verificando se a palavra é um palíndromo
	for (i = 0; i < tam; i++) { 
		if (palavra[i] != palavra[--tam])
			palindromo = 1;
	}*/
	
	//OU
	while (tam >= i) {
		if (palavra[i++] != palavra[--tam])
			palindromo = 1;
	}
	
	//Resultado
	if (palindromo == 0) 
		printf("A palavra é um palíndromo.");
	else 
		printf("A palavra não é um palíndromo.");
	return 0;
}
