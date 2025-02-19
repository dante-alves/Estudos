#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/* Aula 229 - Como simular a recursão com uma estrutura de dados PILHA
*/

typedef struct no{
	int n;
	struct no *proximo;	
}No;

// função para adicionar item na pilha
No* push(No *pilha, int num){
	No *novo = (No *)malloc(sizeof(No));
	
	if(novo){
		novo->n = num;
		novo->proximo = pilha;
		return novo;
	}
	else
		printf("\nErro ao alocar memória!");
	return NULL;
}

// função para remover item da pilha
No* pop(No **pilha){
	No *remover;
	
	if(*pilha){
		remover = *pilha;
		*pilha = remover->proximo;
		return remover;
	}
	else
		printf("\nPilha Vazia!");
	return NULL;
}

void imprimir_pilha(No *pilha){
	if(pilha){
		printf("\nPILHA\n");
		while(pilha){
			printf("%d ", pilha->n);
			pilha = pilha->proximo;
			
			if(pilha != NULL)
				printf("x ");
		}
	}
	else
		printf("\nPilha Vazia!");
}

int fatorial(int num){
	No *remover, *pilha = NULL;
	
	// empilhar os valores de N a 1
	while(num > 0){
		pilha = push(pilha, num);
		num--;
	}
	
	imprimir_pilha(pilha);
	
	num++;
	
	while(pilha){
		remover = pop(&pilha);
		num = num * remover->n;
		free(remover);
	}
	
	printf("= %d\n", num);
	
	return num;
}

int main(){
	setlocale(0, "Portuguese");
	int num;
	
	printf("Insira um número para calcular o fatorial: ");
	scanf("%d", &num);
	
	printf("\nO fatorial de %d! é: %d.\n", num, fatorial(num));
	return 0;
}
