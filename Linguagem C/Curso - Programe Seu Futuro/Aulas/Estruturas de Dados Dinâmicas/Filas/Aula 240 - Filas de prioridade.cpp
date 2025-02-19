#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
/* 	Aula 240 - Filas de prioridade

	- Existe algum crit�rio de prioridade
	- Dados que apresentam o crit�rio de prioridade, v�o para o in�cio da fila
	
*/

typedef struct no{
	int valor;
	struct no *proximo;
}No;

// procedimento de inser��o na fila
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
			if(num > 59){ // se num bater o crit�rio de maior que 60, vai pra fila de prioridade
			
				if((*fila)->valor <= 59){ // verificar se o primeiro valor da fila � menor ou igual a 59 (n�o tem prioridade)
					// se primeiro da fila n�o tem prioridade, o novo que tem prioridade fica em primeiro
					novo->proximo = *fila;
					*fila = novo;
				}
				else{
					// se o primeiro da fila j� tem prioridade, aux vai percorrer a fila at� chegar no �ltimo que tem prioridade
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
				while(aux->proximo) // percorrer a fila enquanto aux->proximo != NULL, pois o aux->proximo sera NULL no �ltimo elemento da fila
					aux = aux->proximo;
				
				aux->proximo = novo;
				
			}
			
		}
		
	}
	else
		printf("\nErro ao alocar mem�ria!\n");
}

// fun��o para remo��o da fila
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
				printf("\n\tAt� a pr�xima! :]\n");
				break;
			default:
				printf("Valor inv�lido!");
		}
	}while(opcao != 0);
	
	return 0;	
}
