#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Aula 205 - Procedimento que inverte um nome
int lerNome(char nome[]){
	printf("Digite um nome: ");
	scanf("%30[^\n]", nome);
	scanf("%c");
	
	return strlen(nome);
}

void inverterNome(char nome[], char invertido[], int tam){
	int i = 0;
	
	
	
	while(nome[i] != '\0'){
		invertido[--tam] = nome[i++];
	}
	invertido[i] = '\0';
	
	/*OUTRA FORMA DE FAZER
	int fim = tam - 1;
	char aux;
	for(i = 0; i < tam/2; i++){
		aux = nome[i];
		nome[i] = nome[fim];
		nome[fim] = aux;
	}*/
	
}

void imprimirResultado(char nome[], char invertido[]){
	printf("\nNome original: %s", nome);
	printf("\nNome invertido: %s", invertido);
}
int main(){
	char nome[30], invertido[30];
	
	inverterNome(nome, invertido, lerNome(nome));
	
	imprimirResultado(nome, invertido);
	
	return 0;
}
