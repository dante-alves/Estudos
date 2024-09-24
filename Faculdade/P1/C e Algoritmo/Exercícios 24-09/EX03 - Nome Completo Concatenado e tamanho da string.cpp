#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
	char nome1[256], nome2[256], nome3[256], nome4[256], nomeCompleto[256] = {""};

//EX03 - Nome Completo Concatenado e tamanho da string

	printf("Qual seu nome completo? ");
	

	scanf("%s %s %s %s", nome1, nome2, nome3, nome4); 
	
	//Concatenando o nome
	strcat(nomeCompleto, nome1);
	strcat(nomeCompleto, " ");
	strcat(nomeCompleto, nome2);
	strcat(nomeCompleto, " ");
	strcat(nomeCompleto, nome3); 
	strcat(nomeCompleto, " ");
	strcat(nomeCompleto, nome4); 
	
	printf("O tamanho da string eh de %d dígitos.\n", strlen(nomeCompleto));
	
	//Printar os dígitos separados
	for (int i = 0; i < 19; i++)
		printf("%c", nomeCompleto[i]);
}
