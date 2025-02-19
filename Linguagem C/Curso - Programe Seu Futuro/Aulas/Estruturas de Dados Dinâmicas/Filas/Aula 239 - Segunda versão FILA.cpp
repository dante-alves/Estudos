#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Aula 239 - Segunda versão FILA

typedef struct no{
	int valor;
	struct no *proximo;
}No;

typedef struct{
	No* primeiro;
	No* ultimo;
	int tam;	
}Fila;

// proced. para inicializar a fila
void criar_fila(Fila *fila){
	fila->primeiro = NULL;
	fila->ultimo = NULL;
	fila->tam = 0;
}

// procedimento de inserção na fila
void inserir_na_fila(Fila *fila, int num){
	No *aux, *novo = (No *)malloc(sizeof(No));
	
	if(novo){
		// novo recebe o valor, e recebe como ponteiro próximo o NULL
		novo->valor = num;
		novo->proximo = NULL;
		if(fila->primeiro == NULL){
			fila->primeiro = novo;
			fila->ultimo = novo;
		}
		else{
			fila->ultimo->proximo = novo; // linkando o fim com o novo nó
			fila->ultimo = novo; // transformando o fim no novo nó
		}
		fila->tam++;
	}
	else
		printf("\nErro ao alocar memória!\n");
}

// função para remoção da fila
No* remover_da_fila(Fila *fila){
	No *remover = NULL;
	
	if(fila->primeiro){
		remover = fila->primeiro;
		fila->primeiro = fila->primeiro->proximo;
		fila->tam--;
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
	
	Fila fila;
	No *remover;
	int opcao, num;
	
	criar_fila(&fila);

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
				imprimir_fila(fila.primeiro); // mandando o ponteiro do primeiro da fila 
				break;
			case 0:
				printf("\n\tAté a próxima! :]\n");
				break;
			default:
				printf("Opção inválida!");
		}
	}while(opcao != 0);
	
	
	return 0;
}
