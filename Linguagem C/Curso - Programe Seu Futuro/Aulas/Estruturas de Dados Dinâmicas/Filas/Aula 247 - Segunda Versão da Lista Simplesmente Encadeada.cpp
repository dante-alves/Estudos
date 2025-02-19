#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/* Aula 247 - Segunda Versão da Lista Simplesmente Encadeada
*/
typedef struct no{
	int valor;
	struct no *proximo;	
}No;

typedef struct{
	No *inicio;
	int tam;
}Lista;
// procedimento para criar a lista
void criar_lista(Lista *lista){
	lista->inicio = NULL;
	lista->tam = 0;
}

// procedimento para inserir no início da lista
void inserir_no_inicio(Lista *lista, int num){
	No *novo = (No *)malloc(sizeof(No));
	
	if(novo){
		novo->valor = num;
		novo->proximo = lista->inicio;
		lista->inicio = novo;
		lista->tam++;
	}
	else
		printf("\nErro ao alocar memória!\n");
}

// procedimento para inserir no fim da lista
void inserir_no_fim(Lista *lista, int num){
	No *novo = (No *)malloc(sizeof(No));
	No *aux;
	if(novo){
		novo->valor = num;
		novo->proximo = NULL;
		
		// se a lista estiver vazia
		if(lista->inicio == NULL)
			lista->inicio = novo;
		// se não estiver vazia
		else{
			aux = lista->inicio;
			while(aux->proximo)
				aux = aux->proximo;
			
			aux->proximo = novo;
		}
		
		lista->tam++;
	}
	else
		printf("\nErro ao alocar memória!\n");
}

// procedimento para inserir no meio da lista
void inserir_no_meio(Lista *lista, int id, int num){
	No *novo = (No *)malloc(sizeof(No));
	No *aux;
	int i;
	
	id--;
	
	if(novo){
		novo->valor = num;
		
		// se a lista estiver vazia
		if(lista->inicio == NULL){
			novo->proximo = NULL;
			lista->inicio = novo;
			printf("\n\tA lista estava vazia. Elemento adicionado como primeiro da lista.\n");
		}
		//se não estiver vazia
		else{
			aux = lista->inicio;
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
		lista->tam++;
	}
	else
		printf("\nErro ao alocar memória!\n");
}

void imprimir_lista(Lista lista){
	No *no = lista.inicio;
	if(no){
		printf("\n\t---------- LISTA ----------\n\t");
		while(no){
			printf("%2d ", no->valor);
			no = no->proximo;
		}
		printf("\n\t---------- LISTA ----------\n");
	}
	else
		printf("\n\tLista vazia!\n");
}
int main(){
	setlocale(0, "Portuguese");
	Lista lista;
	int opcao, num, id;
	
	criar_lista(&lista);
	
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
