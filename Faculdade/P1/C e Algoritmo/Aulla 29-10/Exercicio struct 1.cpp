#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct{
	char nome[50];
	char cidade[50];
	float faturamento;
}Loja;

int main(){
	setlocale(0, "Portuguese");
	
	Loja loja;	
	
	printf("Digite nome, cidade e faturamento da loja: ");
	scanf("%s %s %f", loja.nome, loja.cidade, &loja.faturamento);
	
	printf("Dados da loja: \n%s\n%s\n%.2f", loja.nome, loja.cidade, loja.faturamento);
	return 0;
}
