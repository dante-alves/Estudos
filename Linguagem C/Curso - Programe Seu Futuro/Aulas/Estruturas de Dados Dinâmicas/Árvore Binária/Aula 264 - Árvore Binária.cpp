#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Aula 264 - Árvore Binária

/*
	O primeiro nó de uma árvore é a RAIZ
	Os nós do meio são FILHOS (também podem ser chamados de RAIZ da SUB-ÁRVORE) 
	Os últimos nós são as FOLHAS (apontam para NULL)
	
	Princípio da Árvore Binária 
	Elementos menores são adicionados à esquerda, e elementos maiores à direita
*/

typedef struct no{
	struct no *direita;
	struct no *esquerda;
	int valor, altura;	
}No;

No* inserir(No *arvore, int num){
	No *novo = (No *)malloc(sizeof(No));
	
	if(novo){
		
		if(arvore == NULL){
			novo->valor = num;
			novo->direita = NULL;
			novo->esquerda = NULL;
			novo->altura = 0;
			
			return novo;
		}
		
		if(num < arvore->valor){ // caso o número seja menor, vai para a ESQUERDA
			arvore->esquerda = inserir(arvore->esquerda, num);
		}
		else{ // se não, vai para a DIREITA
			arvore->direita = inserir(arvore->direita, num);
		}
		return arvore;
	}
	else
		printf("\nErro ao alocar memória.");
	
	return NULL;
}


// inserir sem retorno
void inserir2(No **arvore, int num){
	if(*arvore == NULL){
		*arvore = (No *)malloc(sizeof(No));
		(*arvore)->valor = num;
		(*arvore)->esquerda = NULL;
		(*arvore)->direita = NULL;
	}
	else{
		if(num < (*arvore)->valor)
			inserir2(&((*arvore)->esquerda), num);
		else
			inserir2(&((*arvore)->direita), num);
	}
}

// inserir sem recursão, só iterativo
void inserir3(No **arvore, int num){
	No *aux = *arvore;
	while(aux){
		if(num < aux->valor)
			arvore = &aux->esquerda;
		else
			arvore = &aux->direita;
		
		aux = *arvore;
	}
	aux = (No *)malloc(sizeof(No));
	aux->valor = num;
	aux->esquerda = NULL;
	aux->direita = NULL;
	
	*arvore = aux;
}

int imprimir(No *arvore){
	if(arvore){
		imprimir(arvore->esquerda);
		printf("%d ", arvore->valor);
		imprimir(arvore->direita);
	}
	return 0;
}


No *busca_recursiva(No *arvore, int num){
	
	if(arvore == NULL)
		return NULL;
		
	if(arvore->valor == num)
		return arvore;
	
	if(arvore->valor > num)
		return busca_recursiva(arvore->esquerda, num);
	else
		return busca_recursiva(arvore->direita, num);
}

No* busca_iterativa(No *arvore, int num){
	No *aux;
	
	while(arvore){
		if(num < arvore->valor)
			arvore = arvore->esquerda;
		else if(num > arvore->valor)
			arvore = arvore->direita;
		else
			return arvore;
	}
	
	return NULL;
}

int calcularAltura(No *arvore){
	
	if(arvore == NULL)
		return -1;
	else{
		int esq = calcularAltura(arvore->esquerda);
		int dir = calcularAltura(arvore->direita);
		
		if(esq > dir)
			return esq + 1;
		else
			return dir + 1;
	}
}

int contarNos(No *arvore){
	if(arvore == NULL)
		return 0;
	else
		return 1 + contarNos(arvore->esquerda) + contarNos(arvore->direita);
	
	// return (arvore == NULL) ? 0 : 1 + contarNos(arvore->esquerda) + contarNos(arvore->direita);
}

int contarFolhas(No *arvore){
	if(arvore == NULL)
		return 0;
	else if(arvore->esquerda == NULL && arvore->direita == NULL)
		return 1;
	else	
		return contarFolhas(arvore->esquerda) + contarFolhas(arvore->direita);
	
}

int ehFolha(No *arvore){
	return (arvore->direita == NULL && arvore->esquerda == NULL);
}

No* remover(No *arvore, int num){
	if(arvore == NULL)
	{
		printf("\n\tValor não encontrado!\n");
		return NULL;
	}
	if(arvore->valor == num){
		if(ehFolha(arvore)){
			free(arvore);
			printf("\n\tElemento %d removido.\n", num);
			return NULL;
		}
		else
		{
			if(arvore->direita && arvore->esquerda)
			{
				No *aux = arvore->esquerda;
				
				while(aux->direita != NULL)
					aux = aux->direita;
				
				arvore->valor = aux->valor;
				aux->valor = num;
				arvore->esquerda = remover(arvore->esquerda, num);
				
				return arvore;	
			}
			else
			{
				No *filho;
				
				if(arvore->direita)
					filho = arvore->direita;	
				else if(arvore->esquerda)
					filho = arvore->esquerda;
				
				free(arvore);
				
				return filho;
			}
		}
		
	}
		
		if(num > arvore->valor)
			arvore->direita = remover(arvore->direita, num);
		else
			arvore->esquerda = remover(arvore->esquerda, num);	
		
		return arvore;
}



int main(){
	setlocale(0, "Portuguese");
	
	No *arvore = NULL;
	No *buscado;
	int valor, opc, altura;
	
	
	arvore = inserir(arvore, 10);
	arvore = inserir(arvore, 5);
	arvore = inserir(arvore, 12);
	arvore = inserir(arvore, 8);
	arvore = inserir(arvore, 3);
	arvore = inserir(arvore, 11);
	arvore = inserir(arvore, 15);
	
	
	do{
		printf("\n\t1 - Inserir\n\t2 - Imprimir\n\t3 - Buscar\n\t4 - Altura\n\t5 - Contar Nós\n\t6 - Contar Folhas\n\t7 - Remover\n\t0 - Sair\n\n\tInforme: ");
		scanf("%d", &opc);
		
		switch(opc){
			case 1:
				printf("\n\tDigite um valor: ");
				scanf("%d", &valor);
				arvore = inserir(arvore, valor);
				break;
			case 2:
				printf("\n\t");
				imprimir(arvore);
				printf("\n");
				break;
			case 3:
				printf("\n\tQual valor deseja buscar? ");
				scanf("%d", &valor);
				buscado = busca_iterativa(arvore, valor);
				
				if(buscado)
					printf("\n\tValor %d encontrado.\n", buscado->valor);
				else
					printf("\n\tValor não encontrado!\n");
					
				break;
			case 4:
				altura = calcularAltura(arvore);
				printf("\n\tAltura: %d\n", altura);
				break;
			case 5:
				printf("\n\tNós: %d\n", contarNos(arvore));
				break;
			case 6:
				printf("\n\tFolhas: %d\n", contarFolhas(arvore));
				break;
			case 7:
				printf("\n\tQual valor quer remover? ");
				scanf("%d", &valor);
				remover(arvore, valor);
				break;
			case 0: printf("\n\tGood morning, and in case I don't see ya, good afternoon, good evening, and good night.\n"); 
				break;
			default: printf("\n\tOpção inválida.\n"); 
		}
	}while(opc != 0);
	return 0;
}
