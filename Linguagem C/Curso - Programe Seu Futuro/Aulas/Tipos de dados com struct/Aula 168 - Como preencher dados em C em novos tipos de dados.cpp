#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Aula 168 - Como preencher dados em C em novos tipos de dados*/



typedef struct{ //Sempre começa com typedef struct
	int idade;
	char sexo;
	char nome[50];
}Pessoa; //nome do tipo


int main() {
	//Definindo variável pessoa1 do tipo Pessoa
	Pessoa pessoa1;
	
	//lendo os valores os valores à variável pessoa1
	printf("Digite o nome: ");
	fgets(pessoa1.nome, 50, stdin);
	pessoa1.nome[strcspn(pessoa1.nome, "\n")] = '\0';
	
	printf("\nDigite a idade: ");
	scanf("%d", &pessoa1.idade);
	scanf("%c");
	
	printf("\nDigite o sexo (M ou F): ");
	scanf(" %c", &pessoa1.sexo);
	
	printf("Nome: %s\nIdade: %d\nSexo: %c", pessoa1.nome, pessoa1.idade, pessoa1.sexo);
	
	return 0;
}
