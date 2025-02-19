#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "C:\Users\Dante\Desktop\Estudos\Linguagem C\headers\ler_string.h"

// Aula 231 - Verificar se uma express�o matem�tica est� mal formada com PILHA

// estrutura do n�
typedef struct no{
	char ch;
	struct no *proximo;	
}No;

// fun��o para adicionar item na pilha
No* push(No *pilha, char valor){
	No *novo = (No *)malloc(sizeof(No));
	
	if(novo){
		novo->ch = valor;
		novo->proximo = pilha;
		return novo;
	}
	else
		printf("\nErro ao alocar mem�ria!\n");
	return NULL;
}

// fun��o para remover item da pilha
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

// procedimento imprimir a pilha
void imprimir_pilha(No *pilha){
	if(pilha){
		printf("\nPILHA\n");
		while(pilha){
			printf("\t%c\n", pilha->ch);
			pilha = pilha->proximo;
		}
	}
	else
		printf("\nPilha Vazia!\n");
}

int forma_par(char f, char d){
	switch(f){
		case ')':
			if(d == '(')
				return 1;
			else
				return 0;
			break;
		case ']':
			if(d == '[')
				return 1;
			else
				return 0;
			break;
		case '}':
			if(d == '{')
				return 1;
			else
				return 0;
			break;
		case '(':
			if(d == ')')
				return 1;
			else
				return 0;
			break;
		case '[':
			if(d == ']')
				return 1;
			else
				return 0;
			break;
		case '{':
			if(d == '}')
				return 1;
			else
				return 0;
	}
}

int verifica_expressao(char string[]){
	No *pilha = NULL, *remover;
	int i;
	
	while(string[i] != '\0'){
		if(string[i] == '{' || string[i] == '[' || string[i] == '('){
			pilha = push(pilha, string[i]);
			imprimir_pilha(pilha);
		}
		else if(string[i] == '}' || string[i] == ']' || string[i] == ')'){
			// verificar se tem algum caracter de abertura empilhado. Se n�o, e tem um de fechamento, significa que a express�o est� mal formada
			if(pilha == NULL){ 
				printf("\tEXPRESS�O MAL FORMADA!\n");
				return 1;
			}
			
			// se tem o caracter de abertura, continua a fun��o, remove o caracter empilhado, e verifica se forma par
			remover = pop(&pilha);
						
			if(forma_par(string[i], remover->ch) == 0){
				printf("\tExpress�o mal formada.\n");
				return 1; // express�o est� mal formada
			}
			
			free(remover);
		}
		i++;
	}
	
	if(pilha)imprimir_pilha(pilha);
	
	if(pilha){
		printf("\tExpress�o MAL formada.\n");
		return 1;
	}
	else{
		printf("\tExpress�o bem formada.\n");
		return 0;
	}
}

int main(){
	setlocale(0, "Portuguese");
	char string[50];
	
	printf("Insira uma express�o matem�tica para verificar se est� correta: ");
	scanf("%49[^\n]", string);
	
	printf("\nRetorno: %d\n", verifica_expressao(string));
	
	return 0;
}

