#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

//Aula 174 - Como criar um array de struct

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

//Função para coletar os dados da pessoa
Pessoa coletarDados(){
	Pessoa p;
	
	printf("\nDigite o nome: ");
	fgets(p.nome, 50, stdin);
	p.nome[strcspn(p.nome, "\n")] = '\0';
	
	printf("\nDigite a idade: ");
	scanf("%d", &p.idade);
	scanf("%c");
	
	printf("\nData de nascimento (XX/XX/XXXX): ");
	scanf("%d/%d/%d", &p.dataNasc.dia, &p.dataNasc.mes, &p.dataNasc.ano);
	scanf("%c");
	
	printf("\nDigite o sexo (M ou F): ");
	scanf("%c", &p.sexo);
	scanf("%c");
	return p;
}

//Procedimento para printar a pessoa
void imprimirPessoa(Pessoa p){ 
	printf("\nNome: %s\nIdade: %d\nSexo: %c\nData de nascimento: %d/%d/%d\n", p.nome, p.idade, p.sexo, p.dataNasc.dia, p.dataNasc.mes, p.dataNasc.ano);
}

int main() {
	//Definindo variável pessoa1 do tipo Pessoa
	setlocale(0, "Portuguese");
	Pessoa pessoa[3];
	int i;
	
	for (i = 0; i < 3; i++){
		printf("Cadastro nº %d:\n", i);
		pessoa[i]= coletarDados();
	}
	
	printf("\n-----------------------\n")
	
	for (i = 0; i < 3; i++)
		imprimirPessoa(pessoa[i]);
	return 0;
}
