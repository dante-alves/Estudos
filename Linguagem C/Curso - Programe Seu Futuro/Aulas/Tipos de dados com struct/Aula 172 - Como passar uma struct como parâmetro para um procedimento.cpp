#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Aula 172 - Como passar uma struct como parâmetro para um procedimento

//struct para data de nascimento
typedef struct{
	int dia, mes, ano;
}DataNasc;

typedef struct{ //Sempre começa com typedef struct
	DataNasc dataNasc; //variável para armazenar a data de nascimento com uma variável do tipo DataNasc
	int idade;
	char sexo;
	char nome[50];
}Pessoa; //nome do tipo

void imprimirPessoa(Pessoa p){ 
	printf("Nome: %s\nIdade: %d\nSexo: %c\nData de nascimento: %d/%d/%d", p.nome, p.idade, p.sexo, p.dataNasc.dia, p.dataNasc.mes, p.dataNasc.ano);
}

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
	
	printf("\nData de nascimento (XX/XX/XXXX): ");
	scanf("%d/%d/%d", &pessoa1.dataNasc.dia, &pessoa1.dataNasc.mes, &pessoa1.dataNasc.ano);
	
	printf("\nDigite o sexo (M ou F): ");
	scanf(" %c", &pessoa1.sexo);
	
	imprimirPessoa(pessoa1);
	
	return 0;
}

