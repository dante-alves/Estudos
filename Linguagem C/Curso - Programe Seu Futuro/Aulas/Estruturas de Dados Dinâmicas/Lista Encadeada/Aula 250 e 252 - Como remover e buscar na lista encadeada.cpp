#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*Aula 250 - Como remover na lista encadeada
  Aula 252 - Como realizar busca na lista encadeada
*/
typedef struct no{
	int valor;
	struct no *proximo;	
}No;

// procedimento para inserir no in�cio da lista
void inserir_no_inicio(No **lista, int num){
	No *novo = (No *)malloc(sizeof(No));
	
	if(novo){
		novo->valor = num;
		novo->proximo = *lista;
		*lista = novo;
	}
	else
		printf("\nErro ao alocar mem�ria!\n");
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
		// se n�o estiver vazia
		else{
			aux = *lista;
			while(aux->proximo)
				aux = aux->proximo;
			
			aux->proximo = novo;
		}
	}
	else
		printf("\nErro ao alocar mem�ria!\n");
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
		//se n�o estiver vazia
		else{
			aux = *lista;
			i = 1;
			// percorrer a lista
			while(i < id && aux->proximo != NULL){
				aux = aux->proximo;
				i++;				
			}
			if(i != id)
				printf("\n\tPosi��o ainda n�o existente na lista. O elemento foi adicionado ao final da lista.\n");
			
			novo->proximo = aux->proximo;
			aux->proximo = novo;	
		}
	}
	else
		printf("\nErro ao alocar mem�ria!\n");
}

// procedimento para inserir ordenado
void inserir_ordenado(No **lista, int num){
	No *novo = (No *)malloc(sizeof(No));
	
	if(novo){
		novo->valor = num;
		// lista vazia?
		if(*lista == NULL){
			novo->proximo = NULL;
			*lista = novo;
		}// � menor?
		else if(novo->valor < (*lista)->valor){
			novo->proximo = *lista;
			*lista = novo;
		}// � maior?
		else{
			No *aux = *lista;
			
			// caminha na lista enquanto o novo->valor for maior 
			while(aux->proximo && novo->valor > aux->proximo->valor)
				aux = aux->proximo;
			
			novo->proximo = aux->proximo;
			aux->proximo = novo;
		}
	}
	else
		printf("\n\tErro ao alocar mem�ria!\n");
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
No* remover_elemento(No **lista){
	int num;
	No *aux, *remover = NULL;
	
	if(*lista){
		imprimir_lista(*lista);
		
		printf("\n\tInforme qual elemento deseja remover: ");
		scanf("%d", &num);
		
		if((*lista)->valor == num){
			remover = *lista;
			*lista = remover->proximo;
		}
		else{
			aux = *lista;
			while(aux->proximo && aux->proximo->valor != num)
				aux = aux->proximo;
			
			if(aux->proximo == NULL)
				printf("\n\tValor n�o encontrado!\n");
			else{
				remover = aux->proximo;
				aux->proximo = remover->proximo;
			}
		}
	}
	else
		printf("\n\tLista vazia!\n");
		
	return remover;
}

No* buscar(No **lista){
	int num;
	No *aux, *no = NULL;
	
	
	if(*lista){
		printf("\n\tDigite o valor a ser buscado: ");
		scanf("%d", &num);
		
		aux = *lista;
		while(aux && aux->valor != num)
			aux = aux->proximo;
		
		if(aux != NULL)		
			no = aux;
		else
			printf("\n\tValor n�o encontrado!\n");
	}
	else
		printf("\n\tLista vazia!\n");
		
	return no;
}
int main(){
	setlocale(0, "Portuguese");
	No *lista = NULL, *remover, *buscado;
	int opcao, num, id;
	
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
				printf("\n\tEm qual posi��o deseja inserir o novo elemento? ");
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
				printf("\n\tOp��o inv�lida! Informe outra op��o:\n");
		}
	} while(opcao != 0);
	return 0;
}
