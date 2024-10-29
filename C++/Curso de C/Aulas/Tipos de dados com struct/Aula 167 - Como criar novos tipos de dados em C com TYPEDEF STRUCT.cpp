#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Aula 167 - Como criar novos tipos de dados em C com TYPEDEF STRUCT
Seria por exemplo criar tipos para armazenar nomes de vários alunos, com informações sobre o mesmo, por exemplo.

Posso criar um tipo "aluno", "pessoa", "carro" e etc...*/


//Criar um tipo pessoa - nome (vetor de caracteres), sexo (um único caracter), idade (número inteiro)
typedef struct{ //Sempre começa com typedef struct
	int idade;
	char sexo;
	char nome[50];
}Pessoa; //nome do tipo

/*Outra forma menos prática
struct pessoa2{
	int idade;
	char sexo;
	char nome[50];
};*/

int main() {
	//Definindo variável pessoa1 do tipo Pessoa
	Pessoa pessoa1;
	
	//adicionando os valores à variável pessoa1
	pessoa1.idade = 15;
	strcpy(pessoa1.nome, "Clara");
	pessoa1.sexo = 'F';
	
	printf("Nome: %s\nIdade: %d\nSexo: %c", pessoa1.nome, pessoa1.idade, pessoa1.sexo);
	
	return 0;
}
