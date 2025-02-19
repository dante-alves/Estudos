#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*Aula 242 - Lista encadeada, lista duplamente encadeada e lista circular
	O que é uma lista?
	- Uma estrutura que permite 
		- inserir no início, meio e fim
		- inserir ordenado
		- remoção no início, meio e fim
		- busca
		
  Aula 243 - Como inserir no início de uma lista simplesmente encadeada
  Aula 244 - Como inserir no fim de uma lista simplesmente encadeada
  Aula 245 - Como inserir no meio de uma lista simplesmente encadeada
*/
typedef struct no{
	int valor;
	struct no *proximo;	
}No;

// procedimento para inserir no início da lista
void inserir_no_inicio(No **lista, int num){
	No *novo = (No *)malloc(sizeof(No));
	
	if(novo){
		novo->valor = num;
		novo->proximo = *lista;
		*lista = novo;
	}
	else
		printf("\nErro ao alocar memória!\n");
}

// procedimento para inserir no fim da lista
void inserir_no_fim(No **lista, int num){
	No *novo = (No *)malloc(sizeof(No));
	No *aux;
	if(novo){
		novo->valor = num;
		novo->proximo = NULL;
		
		// se a lista estiver vazia
		if(*lista == NULL)
			*lista = novo;
		// se não estiver vazia
		else{
			aux = *lista;
			while(aux->proximo)
				aux = aux->proximo;
			
			aux->proximo = novo;
		}
	}
	else
		printf("\nErro ao alocar memória!\n");
}

// procedimento para inserir no meio da lista
void inserir_no_meio(No **lista, int id, int num){
	No *novo = (No *)malloc(sizeof(No));
	No *aux;
	int i;
	
	id--;
	
	if(novo){
		novo->valor = num;
		
		// se a lista estiver vazia
		if(*lista == NULL){
			novo->proximo = NULL;
			*lista = novo;
			printf("\n\tA lista estava vazia. Elemento adicionado como primeiro da lista.\n");
		}
		//se não estiver vazia
		else{
			aux = *lista;
			i = 1;
			// percorrer a lista
			while(i < id && aux->proximo != NULL){
				aux = aux->proximo;
				i++;				
			}
			if(i != id)
				printf("\n\tPosição ainda não existente na lista. O elemento foi adicionado ao final da lista.\n");
			
			novo->proximo = aux->proximo;
			aux->proximo = novo;	
		}
	}
	else
		printf("\nErro ao alocar memória!\n");
}

void imprimir_lista(No *lista){
	if(lista){
		printf("\n\t---------- LISTA ----------\n\t");
		while(lista){
			printf("%2d ", lista->valor);
			lista = lista->proximo;
		}
		printf("\n\t---------- LISTA ----------\n");
	}
	else
		printf("\n\tLista vazia!\n");
}
int main(){
	setlocale(0, "Portuguese");
	No *lista = NULL;
	int opcao, num, id;
	
	do{
		printf("\n\t1 - Inserir no inicio\n\t2 - Inserir no fim\n\t3 - Inserir no meio\n\t4 - Imprimir lista\n\t0 - Sair\n\tInforme: ");
		scanf("%d", &opcao);
		
		switch(opcao){
			case 0:
				printf("\n\tGoodbye my friend!\n");
				break;
			case 1:
				printf("\n\tDigite o valor a ser inserido: ");
				scanf("%d", &num);
				inserir_no_inicio(&lista, num);
				break;
			case 2:
				printf("\n\tDigite o valor a ser inserido: ");
				scanf("%d", &num);
				inserir_no_fim(&lista, num);
				break;
			case 3:
				printf("\n\tEm qual posição deseja inserir o novo elemento? ");
				scanf("%d", &id);
				
				printf("\n\tDigite o valor a ser inserido: ");
				scanf("%d", &num);
				inserir_no_meio(&lista, id, num);
				break;
			case 4:
				imprimir_lista(lista);
				break;
			default:
				printf("\n\tOpção inválida! Informe outra opção:\n");
		}
	} while(opcao != 0);
	return 0;
}
