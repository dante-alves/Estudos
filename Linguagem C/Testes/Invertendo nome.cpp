#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
	//Iniciando as vari�veis
	char nome[50], *invertido[10];
	int i, j;
	char *token;
	
	i = j = 0;
	
	//Lendo o nome
	printf("Digite seu nome: ");
	fgets(nome, sizeof nome, stdin);
	
	//Removendo o \n do final do fgets
	nome[strcspn(nome, "\n")] = '\0';
	
	//Printar o nome
	printf("%s", nome);

	token = strtok(nome, " "); //token recebe o primeiro nome
	while (token) {
		invertido[i++] = token; //o ponteiro invertido recebe o primeiro nome na primeira posi��o e vai pra pr�xima posi��o do array de ponteiro
		
		token = strtok(NULL, " "); //token recebe o pr�ximo nome
	}
	
	//Printar o nome ao contr�rio
	for (j = i - 1; j >= 0; j--) {
		printf("\n%s", invertido[j]);
	}
}
