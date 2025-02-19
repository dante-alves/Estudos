#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "C:\Users\Dante\Desktop\Estudos\Linguagem C\headers\ler_string.h"

// Aula 232 - Como inverter a ordem das letras de uma string com PILHAS

// estrutura do nó
typedef struct no{
	char ch;
	struct no *proximo;	
}No;

// função para adicionar item na pilha
No* push(No *pilha, char valor){
	No *novo = (No *)malloc(sizeof(No));
	
	if(novo){
		novo->ch = valor;
		novo->proximo = pilha;
		return novo;
	}
	else
		printf("\nErro ao alocar memória!\n");
	return NULL;
}

// função para remover item da pilha
No* pop(No **pilha){
	No *remover = NULL;
	
	if(*pilha){
		remover = *pilha;
		*pilha = remover->proximo;
	}
	else
		printf("\nPilha Vazia!\n");
		
	return remover;
}

// procedimento para inveter palavras
void inverter_palavras(char string[]){
	No *pilha = NULL, *remover;
	int i = 0;
	
	while(string[i] != '\0'){
		if(string[i] != ' ')
			pilha = push(pilha, string[i]);
		else{
			while(pilha){
				remover = pop(&pilha);
				printf("%c", remover->ch);
				free(remover);
			}
			printf(" ");
		}
		i++;
	}
	
	while(pilha){
		remover = pop(&pilha);
		printf("%c", remover->ch);
		free(remover);
	}
}

int main(){
	setlocale(0, "Portuguese");
	char string[50] = {"Mim de papai"};
	
	printf("Frase invertida: ");
	inverter_palavras(string);
	
	printf("\n\n%s", string);

	
	return 0;
}

