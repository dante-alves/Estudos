#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
/* 	Aula 240 - Filas de prioridade

	- Existe algum critério de prioridade
	- Dados que apresentam o critério de prioridade, vão para o início da fila
	
*/

typedef struct no{
	int valor;
	struct no *proximo;
}No;

// procedimento de inserção na fila
void inserir_na_fila(No **fila, int num){
	No *aux, *novo = (No *)malloc(sizeof(No));
	
	if(novo){
		novo->valor = num;
		novo->proximo = NULL;
		if(*fila == NULL){
			*fila = novo;
		}
		else{
			// fila de prioridade
			if(num > 59){ // se num bater o critério de maior que 60, vai pra fila de prioridade
			
				if((*fila)->valor <= 59){ // verificar se o primeiro valor da fila é menor ou igual a 59 (não tem prioridade)
					// se primeiro da fila não tem prioridade, o novo que tem prioridade fica em primeiro
					novo->proximo = *fila;
					*fila = novo;
				}
				else{
					// se o primeiro da fila já tem prioridade, aux vai percorrer a fila até chegar no último que tem prioridade
					aux = *fila;
					
					while(aux->proximo && aux->proximo->valor > 59)
						aux = aux->proximo;
					// ao chegar no final da fila de prioridade, novo->proximo vai apontar para o mesmo que aux->proximo, e aux->proximo passa a apontar para novo
					novo->proximo = aux->proximo;
					aux->proximo = novo;
				}
			
			} // fila normal
			else{
			
				aux = *fila; // auxiliar para percorrer a fila
				while(aux->proximo) // percorrer a fila enquanto aux->proximo != NULL, pois o aux->proximo sera NULL no último elemento da fila
					aux = aux->proximo;
				
				aux->proximo = novo;
				
			}
			
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
