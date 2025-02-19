#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*Aula 255 - Exercício - Como criar duas listas (par e ímpar) a partir de uma lista
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

// procedimento para inserir ordenado
void inserir_ordenado(No **lista, int num){
	No *novo = (No *)malloc(sizeof(No));
	
	if(novo){
		novo->valor = num;
		// lista vazia?
		if(*lista == NULL){
			novo->proximo = NULL;
			*lista = novo;
		}// é menor?
		else if(novo->valor < (*lista)->valor){
			novo->proximo = *lista;
			*lista = novo;
		}// é maior?
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
		printf("\n\tErro ao alocar memória!\n");
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
				printf("\n\tValor não encontrado!\n");
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
			printf("\n\tValor não encontrado!\n");
	}
	else
		printf("\n\tLista vazia!\n");
		
	return no;
}

void gerar_impar_par(No **listaImpar, No **listaPar, No **listaC){
	No *auxC;
	
	if(*listaC){
		auxC = *listaC;
		
		while(auxC){
			if(auxC->valor % 2 == 0)
				inserir_no_fim(listaPar, auxC->valor);
			else
				inserir_no_fim(listaImpar, auxC->valor);
			auxC = auxC->proximo;
		}
		printf("\n\tLista Ímpar:\n");
		imprimir_lista(*listaImpar);
		
		printf("\n\tLista Par:\n");
		imprimir_lista(*listaPar);
	}
	else
		printf("\n\tLista Vazia!\n");

}
int main(){
	setlocale(0, "Portuguese");
	No *listaA, *listaB, *listaC, *remover, *buscado, **endereco_lista;
	int opcao, num, id;
	
	listaA = listaB = listaC = NULL;
	
	do{
		printf("\n\t1 - Inserir no inicio\n\t2 - Inserir no fim\n\t3 - Inserir no meio\n\t4 - Inserir ordenado\n\t5 - Remover elemento"
		"\n\t6 - Imprimir lista\n\t7 - Buscar elemento\n\t8 - Gerar Listas Ímpar e Par\n\t0 - Sair\n\n\tInforme: ");
		scanf("%d", &opcao);
		
		endereco_lista = &listaC;
		

		switch(opcao){
			case 0:
				printf("\n\tGoodbye my friend!\n");
				break;
			case 1:
				printf("\n\tDigite o valor a ser inserido: ");
				scanf("%d", &num);
				inserir_no_inicio(endereco_lista, num);
				break;
			case 2:
				printf("\n\tDigite o valor a ser inserido: ");
				scanf("%d", &num);
				inserir_no_fim(endereco_lista, num);
				break;
			case 3:
				printf("\n\tEm qual posição deseja inserir o novo elemento? ");
				scanf("%d", &id);
				
				printf("\n\tDigite o valor a ser inserido: ");
				scanf("%d", &num);
				inserir_no_meio(endereco_lista, id, num);
				break;
			case 4:
				printf("\n\tDigite o valor a ser inserido: ");
				scanf("%d", &num);
				inserir_ordenado(endereco_lista, num);
				break;
			case 5:
				remover = remover_elemento(endereco_lista);
				if(remover){
					printf("\n\tElemento %d removido.\n", remover->valor);
					free(remover);
				}
				break;
			case 6:
				imprimir_lista(*endereco_lista);
				break;
			case 7:
				buscado = buscar(endereco_lista);
				if(buscado)
					printf("\n\tValor %d encontrado.\n", buscado->valor);
				break;
			case 8:
				gerar_impar_par(&listaA, &listaB, &listaC);
				break;
			default:
				printf("\n\tOpção inválida! Informe outra opção:\n");
		}
	} while(opcao != 0);
	return 0;
}
