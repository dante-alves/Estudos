#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

/*
	Faça um algoritmo que armazene em memória os seguintes dados:
		Nome
		Endereço - composto por Rua, Número e Cidade
		Pessoa Física ou Jurídica
		CPF ou CNPJ (union)
		Idade
	
	Os valores devem ser capturados do teclado para um grupo de TRÊS pessoas e/ou empresas.
	Mostrar os dados armazenados separados por pessoa
*/

typedef struct{
	char rua[50];
	char num[10];
	char cidade[50];
}t_Endereco;

enum t_PessoaFJ{
	pessoaFisica = 0,
	pessoaJuridica = 1
};

union t_Documento{
	char cpf[11];
	char cnpj[14];
};

typedef struct{
	char nome[50];
	t_Endereco endereco;
	enum t_PessoaFJ pessoaFJ;
	union t_Documento doc;
	int idade;
}t_Cadastro;

int main(){
	setlocale(0, "Portuguese");
	
	t_Cadastro cadastro[3];
	
	char enderecoGeral[3][110];
	
	int i;
	
	for(i = 0; i < 3; i++){
		strcpy(enderecoGeral[i], "Rua ");
	}
		
	for(i = 0; i < 3; i++){
		printf("\n%dº Cadastro\n", i + 1);
		printf("-----------------------\n");
		printf("Nome: ");
		scanf("%50[^\n]", cadastro[i].nome);
		scanf("%c");
		
		printf("Endereço:\n");
		
		printf("  Rua: ");
		scanf("%50[^\n]", cadastro[i].endereco.rua);
		scanf("%c");
		
		printf("  Numero: ");
		scanf("%10[^\n]", cadastro[i].endereco.num);
		scanf("%c");
		
		printf("  Cidade: ");
		scanf("%50[^\n]", cadastro[i].endereco.cidade);
		scanf("%c");
		
		strcat(enderecoGeral[i], cadastro[i].endereco.rua);
		strcat(enderecoGeral[i], ", ");
		strcat(enderecoGeral[i], cadastro[i].endereco.num);
		strcat(enderecoGeral[i], " - ");
		strcat(enderecoGeral[i], cadastro[i].endereco.cidade);
		
		printf("Pessoa Fisica[ 0 ] / Pessoa Jurídica [ 1 ]\n");
		scanf("%d", &cadastro[i].pessoaFJ);
		scanf("%c");
		
		switch(cadastro[i].pessoaFJ){
			case pessoaFisica:
				printf("CPF: ");
				scanf("%s", cadastro[i].doc.cpf);
				scanf("%c");
				
				printf("Idade: ");
				scanf("%d", &cadastro[i].idade);
				scanf("%c");
			break;
			case pessoaJuridica:
				printf("CNPJ: ");
				scanf("%s", cadastro[i].doc.cnpj);
				scanf("%c");
		}
	}
	
	system("cls");
	
	printf("DADOS CADASTRADOS");
	printf("\n-----------------------");
	for(i = 0; i < 3; i++){
		printf("\n%dº Cadastro\n", i + 1);
		printf("-----------------------\n");
		printf("Nome: %s\nEndereço: %s\n", cadastro[i].nome, enderecoGeral[i]);
		switch(cadastro[i].pessoaFJ){
			case 0:
				printf("CPF: %s\nIdade: %d\n", cadastro[i].doc.cpf, cadastro[i].idade);
			break;
			case 1:
				printf("CNPJ: %s", cadastro[i].doc.cnpj);
		}
	}
	return 0;
}
