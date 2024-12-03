#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Aula 169 - Struct de Struct

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


int main() {
	//Definindo variável pessoa1 do tipo Pessoa
	Pessoa pessoa1;
	
	printf("%d\n", sizeof(Pessoa)); //O tamanho dá 68 bytes, sendo 2 deles a memória necessária para executar as structs criadas.
	
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
	
	printf("Nome: %s\nIdade: %d\nSexo: %c\nData de nascimento: %d/%d/%d", pessoa1.nome, pessoa1.idade, pessoa1.sexo, pessoa1.dataNasc.dia, pessoa1.dataNasc.mes, pessoa1.dataNasc.ano);
	
	return 0;
}

