#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*Aula 258 - Lista Circular
*/
typedef struct no{
	int valor;
	struct no *proximo;	
}No;

typedef struct{
	No *inicio;
	No *fim;
	int tam;
}Lista;
// procedimento para criar lista
void criar_lista(Lista *lista){
	lista->inicio = lista->fim = NULL;
	lista->tam = 0;
}
// procedimento para inserir no início da lista
void inserir_no_inicio(Lista *lista, int num){
	No *novo = (No *)malloc(sizeof(No));
	
	if(novo){
		novo->valor = num;
		novo->proximo = lista->inicio;
		lista->inicio = novo;
		
		if(lista->fim == NULL) // se a lista estiver vazia, fim e início vão receber novo
			lista->fim = novo;
		
		lista->fim->proximo = lista->inicio;
		
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
		
		// se a lista estiver vazia
		if(lista->inicio == NULL)
			inserir_no_inicio(lista, num);
		// se não estiver vazia
		else{
			lista->fim->proximo = novo;
			lista->fim = novo;
			lista->fim->proximo = lista->inicio;
			lista->tam++;
		}
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
			inserir_no_inicio(lista, num);
			printf("\n\tA lista estava vazia. Elemento adicionado como primeiro da lista.\n");
		}
		//se não estiver vazia
		else{
			aux = lista->inicio;
			i = 1;
			// percorrer a lista
			while(i < id && aux->proximo != lista->inicio){
				aux = aux->proximo;
				i++;				
			}
			if(i != id)
				printf("\n\tPosição ainda não existente na lista. O elemento foi adicionado ao final da lista.\n");
			
			novo->proximo = aux->proximo;
			aux->proximo = novo;	
			
			lista->tam++;
		}
	}
	else
		printf("\nErro ao alocar memória!\n");
}

// procedimento para inserir ordenado
void inserir_ordenado(Lista *lista, int num){
	No *novo = (No *)malloc(sizeof(No));
	
	if(novo){
		novo->valor = num;
		// lista vazia?
		if(lista->inicio == NULL){
			inserir_no_inicio(lista, num);
		}// é menor?
		else if(novo->valor < lista->inicio->valor){
			inserir_no_inicio(lista, num);
		}// é maior?
		else{
			No *aux = lista->inicio;
			
			// caminha na lista enquanto o novo->valor for maior 
			while(aux->proximo != lista->inicio && novo->valor > aux->proximo->valor)
				aux = aux->proximo;
			// se não encontrar nenhum que novo seja menor, novo vai para o fim da lista
			if(aux->proximo == lista->inicio)
				inserir_no_fim(lista, num);
			else{ // se novo é menor do que algum
				novo->proximo = aux->proximo;
				aux->proximo = novo;
				lista->tam++;
			}
		}
	}
	else
		printf("\n\tErro ao alocar memória!\n");
}

void imprimir_lista(Lista lista){
	No *no = lista.inicio;
	
	if(no){
		printf("\n\tTamanho da lista: %d", lista.tam);
		printf("\n\t---------- LISTA ----------\n\t");
		do{
			printf("%2d ", no->valor);
			no = no->proximo;
		}while(no != lista.inicio);
		
		printf("\n\t---------- LISTA ----------\n");
	}
	else
		printf("\n\tLista vazia!\n");
}
No* remover_elemento(Lista *lista){
	int num;
	No *aux, *remover = NULL;
	
	if(lista->inicio){
		imprimir_lista(*lista);
		
		printf("\n\tInforme qual elemento deseja remover: ");
		scanf("%d", &num);
		
		if(lista->inicio == lista->fim && lista->inicio->valor == num){
			remover = lista->inicio;
			lista->inicio = lista->fim = NULL;
			lista->tam--;
		}
		else if(lista->inicio->valor == num){
			remover = lista->inicio;
			lista->inicio = remover->proximo;
			lista->fim->proximo = lista->inicio;
			lista->tam--;
		}
		else{
			aux = lista->inicio;
			while(aux->proximo != lista->inicio && aux->proximo->valor != num)
				aux = aux->proximo;
			
			if(aux->proximo->valor == num){
				if(aux->proximo == lista->fim){
					remover = aux->proximo;
					aux->proximo = remover->proximo;
					lista->fim = aux;
				}
					
				else{
					remover = aux->proximo;
					aux->proximo = remover->proximo;
				}
				lista->tam--;
			}
			
			else
				printf("\n\tValor não encontrado!\n");
		}
	}
	else
		printf("\n\tLista vazia!\n");
		
	return remover;
}

No* buscar(Lista *lista){
	int num;
	No *aux = lista->inicio;
	
	
	if(aux){
		printf("\n\tDigite o valor a ser buscado: ");
		scanf("%d", &num);

		do{
			if(aux->valor == num)
				return aux;
			aux = aux->proximo;
		}while(aux != lista->inicio);
		
	}
	else
		printf("\n\tLista vazia!\n");
		
	return NULL;
}
int main(){
	setlocale(0, "Portuguese");
	Lista lista;
	No *remover, *buscado;
	int opcao, num, id;
	
	
	criar_lista(&lista);
	
	do{
		printf("\n\t1 - Inserir no inicio\n\t2 - Inserir no fim\n\t3 - Inserir no meio\n\t4 - Inserir ordenado\n\t5 - Remover elemento\n\t6 - Imprimir lista\n\t7 - Buscar elemento\n\t0 - Sair\n\n\tInforme: ");
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
				printf("\n\tDigite o valor a ser inserido: ");
				scanf("%d", &num);
				inserir_ordenado(&lista, num);
				break;
			case 5:
				remover = remover_elemento(&lista);
				if(remover){
					printf("\n\tElemento %d removido.\n", remover->valor);
					free(remover);
				}
				break;
			case 6:
				imprimir_lista(lista);
				break;
			case 7:
				buscado = buscar(&lista);
				if(buscado)
					printf("\n\tValor %d encontrado.\n", buscado->valor);
				break;
			default:
				printf("\n\tOpção inválida! Informe outra opção:\n");
		}
	} while(opcao != 0);
	return 0;
}
