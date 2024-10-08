#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Aula 132 e 133 e 135- Identificado o fim de uma string em C e como descobrir o tamanho da string

int main () {
	
	char palavras[20];
	int i = 0, tamanho;
	
	fgets(palavras, sizeof palavras, stdin);
	
	//Trocar o \n enviado ao final da string por um \0 ----> Só é necessário em C
	//palavras[strcspn(palavras, "\n")] = '\0'; ------ Função para fazer a troca
	
	//scanf("%20[^\n]", palavras);
	
	while (palavras[i] != '\0'){
		printf("%d = %c\n", i, palavras[i]);
		i++;
		//Forma manual de fazer a troca do \n do fgets.
		if (palavras[i] == '\n')
			palavras[i] = '\0';
	}
	
	tamanho = i;
	//OU 
	tamanho = strlen(palavras);
	
	printf("A string tem um tamanho de %d caracteres", tamanho);

	return 0;
}
