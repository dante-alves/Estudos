#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Aula 205 - Função que inverte um nome

//Função que retorna um ponteiro de char com o nome invertido
char* inverterNome(char nome[]){
	int i = 0, tam = strlen(nome); //tam == tamanho do vetor nome
	
	//Declarando uma nova variável de ponteiro do tipo char, alocando memória dinâmica para ela
	char *novo = (char *)malloc((tam + 1) * sizeof(char)); //tam + 1 para adicionar um caractere a mais que será ocupado pelo final de string \0
	
	int fim = tam - 1; //Variável que vai definir a posição final da string

	//Inverter o nome
	for(i = 0; i < tam; i++){
		novo[fim] = nome[i];
		fim--;
	}
	novo[i] = '\0'; //Adicionar o fim da string
	
	return novo;
}


int main(){
	char nome[30];
	char *invertido;
	
	printf("Digite um nome: ");
	scanf("%30[^\n]", nome);
	scanf("%c");
	
	printf("\nNome original: %s\n", nome);
	
	invertido = inverterNome(nome);
	
	printf("\nNome invertido: %s\n", invertido);
	
	return 0;
}
