#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "pilha.h"
/*Aula 230 - Como criar arquivos de cabeçalho .h na linguagem C
	-> Salve o arquivo como .h
	-> Compile sem rodar
*/

// calcular o fatorial
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
