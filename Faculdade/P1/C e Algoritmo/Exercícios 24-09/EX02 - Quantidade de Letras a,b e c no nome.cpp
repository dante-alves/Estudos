#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>

//EX02 - Quantidade de Letras a, b e c no nome

int main () {
	char nome1[256], nome2[256], nome3[256], nomeCompleto[256] = {""};
	int contA = 0, contB = 0, contC = 0;

	printf("Qual seu nome completo? ");
	
	/*Método podre de pegar o nome completo
	scanf("%s %s %s", nome1, nome2, nome3); 
	
	//Concatenando o nome
	strcat(nomeCompleto, nome1);
	strcat(nomeCompleto, " ");
	strcat(nomeCompleto, nome2);
	strcat(nomeCompleto, " ");
	strcat(nomeCompleto, nome3); */	
	
	
	//Método bom de pegar o nome completo
	fgets(nomeCompleto, sizeof nomeCompleto, stdin);
	
	int i = 0;
	
	//Adicionar as letras aos contadores
	while (nomeCompleto[i] != '\0') {
			switch (tolower(nomeCompleto[i])) { //tolower() pra deixar todas as letras em minúsculo
			case 'a': 
				contA++;
			break;
			case 'b':
				contB++;
			break;
			case 'c':
				contC++;
		}
		i++;
	}
	
	printf ("A = %d ,B = %d e C = %d", contA, contB, contC);
	
	return 0;
}
