#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

/* Aula 143 - Pal�ndromos

arara
asa
ama
osso
radar
reviver

*/

int main (){
	setlocale(0, "Portuguese");
	
	//Vari�veis
	char palavra[50] = {"arara"};
	int i, j, tam, palindromo = 0;
	
	//Inicializando vari�veis
	tam = strlen(palavra);
	j = tam - 1;
		
	/*Verificando se a palavra � um pal�ndromo
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
		printf("A palavra � um pal�ndromo.");
	else 
		printf("A palavra n�o � um pal�ndromo.");
	return 0;
}
