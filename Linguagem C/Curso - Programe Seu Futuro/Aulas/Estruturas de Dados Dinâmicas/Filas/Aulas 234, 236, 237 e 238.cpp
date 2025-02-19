#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
/* Aula 234, 236, 237 e 238

Aula 234 - O que é uma fila?
	- Estrutura comum no mundo real formada sempre que a prestação de um serviço é mais lenta que a demanda
	- Novos elementos são adicionados ao final da fila
	
	- Inserir na fila (no final da fila)
		dado 1, ponteiro -> dado 2, ponteiro -> dado 3, NULL
	- Remover da fila (no início da fila)
		*remover = dado 1
		free(remover)
		dado 2, ponteiro -> dado 3, NULL
		
		typedef struct no{
			int dado;
			struct no *proximo;
		}No;
		
	- FIFO -> First-In, First-Out -> Primeiro a Entrar, Primeiro a Sair
	
Aula 236 - Inserção em uma FILA
	*/
	
typedef struct no{
	int valor;
	struct no *proximo;
}No;

// procedimento de inserção na fila
void inserir_na_fila(No **fila, int num){
	No *aux, *novo = (No *)malloc(sizeof(No));
	
	if(novo){
		// novo recebe o valor, e recebe como ponteiro próximo o NULL
		novo->valor = num;
		novo->proximo = NULL;
		if(*fila == NULL)
			*fila = novo;
		else{
			aux = *fila; // auxiliar para percorrer a fila
			while(aux->proximo) // percorrer a fila enquanto aux->proximo != NULL, pois o aux->proximo sera NULL no último elemento da fila
				aux = aux->proximo;
			
			aux->proximo = novo;
		}
	}
	else
		printf("\nErro ao alocar memória!\n");
}

// função para remoção da fila
No* remover_da_fila(No **fila){
	No *remover = NULL;
	
	if(*fila){
		remover = *fila;
		*fila = remover->proximo;
	}
	else
		printf("\nFila Vazia!\n");
	
	return remover;
}

// imprimir fila
void imprimir_fila(No *fila){
	
	if(fila){
		printf("\n\t------------ FILA ------------\n\t");
		while(fila){
			printf("%d ", fila->valor);
			fila = fila->proximo;
		}
		printf("\n\t------------ FILA ------------\n");
	}
	else
		printf("\nFila Vazia!\n");
}

int main(){
	setlocale(0, "Portuguese");
	No *fila = NULL, *remover;
	int opcao, num;
	
	do{
		printf("\n\t1 - Inserir elemento na fila\n\t2 - Remover elemento da fila\n\t3 - Imprimir fila\n\t0 - Sair\n\n\tInforme: ");
		scanf("%d", &opcao);
		
		switch(opcao){
			case 1:
				printf("\n\tDigite o valor a ser inserido: ");
				scanf("%d", &num);
				inserir_na_fila(&fila, num);
				break;
			case 2:
				remover = remover_da_fila(&fila);
				if(remover){
					printf("\n\tElemento removido: %d", remover->valor);
					free(remover);
				}
				break;
			case 3:
				imprimir_fila(fila);
				break;
			case 0:
				printf("\n\tAté a próxima! :]\n");
				break;
			default:
				printf("Valor inválido!");
		}
	}while(opcao != 0);
	
	return 0;	
}
