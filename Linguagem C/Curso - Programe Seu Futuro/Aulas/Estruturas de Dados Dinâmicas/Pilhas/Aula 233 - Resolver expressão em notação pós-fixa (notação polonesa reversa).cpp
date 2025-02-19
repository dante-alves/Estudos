#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "C:\Users\Dante\Desktop\Estudos\Linguagem C\headers\ler_string.h"

// Aula 233 - Resolver expressão em notação pós-fixa (notação polonesa reversa)

typedef struct no{
	float num;
	struct no *proximo;	
}No;

// função para adicionar item na pilha
No* push(No *pilha, float valor){
	No *novo = (No *)malloc(sizeof(No));
	
	if(novo){
		novo->num = valor;
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


float operacao(float a, float b, char x){
	switch(x){
		case '+':
			return a + b;
			break;
		case '-':
			return a - b;
			break;
		case '*':
			return a * b;
			break;
		case '/':
			return a / b;
			break;
		default:
			return 0.0;
			
	}
}

// procedimento para calcular a expressão
float pos_fixa(char string[]){
	int i = 0;

	float num;
	char *pt;
	No *n1, *n2, *pilha = NULL;
	
	pt = strtok(string, " ");
	
	while(pt){
		if(pt[0] == '+' || pt[0] == '-' || pt[0] == '*' || pt[0] == '/'){
			n1 = pop(&pilha);
			n2 = pop(&pilha);
			num = operacao(n2->num, n1->num, pt[0]);
			pilha = push(pilha, num);
			
			free(n1);
			free(n2);		
		}
		else{
			// transformando o valor em string para tipo float
			num = strtol(pt, NULL, 10); // o primeiro valor é a variável onde está armazenada a string -> o segundo é a variável para armazenar outras strings após o valor -> o último valor é a base numérica utilizada - 10 = decimal
			pilha = push(pilha, num);
		}
		pt = strtok(NULL, " ");
	}
	
	// enviando o valor final da pilha como resultado
	n1 = pop(&pilha);
	num = n1->num;
	free(n1);
	
	return num;
}

int main(){
	setlocale(0, "Portuguese");
	char exp[50] = {"5 3 2 + * 4 / 6 -"};
	
	printf("Resultado da expressão %s: ", exp);
	printf("%.2f\n", pos_fixa(exp));
	
	return 0;
}
