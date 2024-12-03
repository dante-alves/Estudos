#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Aula 173 - Como criar uma função que retorna uma struct

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
	
	printf("Digite o nome: ");
	fgets(p.nome, 50, stdin);
	p.nome[strcspn(p.nome, "\n")] = '\0';
	
	printf("\nDigite a idade: ");
	scanf("%d", &p.idade);
	scanf("%c");
	
	printf("\nData de nascimento (XX/XX/XXXX): ");
	scanf("%d/%d/%d", &p.dataNasc.dia, &p.dataNasc.mes, &p.dataNasc.ano);
	
	printf("\nDigite o sexo (M ou F): ");
	scanf(" %c", &p.sexo);
	
	return p;
}

//Procedimento para printar a pessoa
void imprimirPessoa(Pessoa p){ 
	printf("Nome: %s\nIdade: %d\nSexo: %c\nData de nascimento: %d/%d/%d", p.nome, p.idade, p.sexo, p.dataNasc.dia, p.dataNasc.mes, p.dataNasc.ano);
}

int main() {
	//Definindo variável pessoa1 do tipo Pessoa
	Pessoa pessoa1;
	
	pessoa1 = coletarDados();
	
	imprimirPessoa(pessoa1);
	
	return 0;
}
