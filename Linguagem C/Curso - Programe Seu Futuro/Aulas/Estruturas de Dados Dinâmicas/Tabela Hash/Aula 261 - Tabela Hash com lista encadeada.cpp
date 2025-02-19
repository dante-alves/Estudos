#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Aula 261 - Tabela Hash com lista encadeada

/*				
	- CONCEITOS ESSENCIAIS
		- Tamanho
		- Função de Espalhamento 
			- função que gera um código a ser utilizado como índice de acesso na tabela
		- Colisões
			- ocorre uma colisão quando a função de espalhamento gera o mesmo código para chaves diferentes
		- Fator de Carga
			- Quantidade de elementos dividido pelo tamanho da tabela
	*/

#define M 19

typedef struct no{
	int chave;
	struct no *proximo;
}No;

typedef struct{
	No *inicio;
	int tam;
}Lista;

void inicializarLista(Lista *l){
	l->inicio = NULL;
	l->tam = 0;
}

void inserir_na_lista(Lista *l, int valor){
	No *novo = (No *)malloc(sizeof(No));
	
	if(novo){
		novo->chave = valor;
		novo->proximo = l->inicio;
		l->inicio = novo; // atualizando o início da lista
		l->tam++;
	}
	else
		printf("\n\tErro ao alocar memória!");
}

int buscar_na_lista(Lista *l, int valor){
	No *aux = l->inicio;
	
	while(aux && aux->chave != valor)
		aux = aux->proximo;
	
	if(aux != NULL)
		return aux->chave;
	
	return 0;		
}

void imprimir_lista(Lista *l){
	No *aux = l->inicio;
	printf(" Tamanho da lista: %d: ", l->tam);
	while(aux){
		printf("%d ", aux->chave);
		aux = aux->proximo;
	}
}
int funcao_hash(int chave){
	return chave % M;
}

void inserir(Lista t[], int chave){
	int id = funcao_hash(chave);
	inserir_na_lista(&t[id], chave); // vai 
}

void coletar_chaves(Lista t[]){
	int i;
	int chave;
	
	printf("\n\tInsira a chave a ser armazenada no vetor: ");
	scanf("%d", &chave);
	inserir(t, chave);
}

void imprimir_tabela(Lista t[]){
	int i;
	
	for(i = 0; i < M; i++){
		printf("\n\tÍndice: %d =", i);
		imprimir_lista(&t[i]);
	}
	
}
	
void iniciar_vet(Lista t[]){
	int i;
	
	for(i = 0; i < M; i++)
		inicializarLista(&t[i]);
}

int buscar(Lista t[], int num){
	int id = funcao_hash(num);
	
	return buscar_na_lista(&t[id], num);
}
int main(){
	setlocale(0, "Portuguese");
	/*Fazer uma tabela hash para armazenar 10 elementos
	10 * 2 = 20 -> 19 é o número primo mais próximo
	
	10/19 = 0,52 -> Fator de carga
	
	O vetor precisa ter tamanho 19
	*/
	int tam = 10;
	
	//o M seria o 19, no caso de tam ser 10 -> coloquei M como uma constante
	
	int buscando, opc, num;
	Lista v[M];
	
	iniciar_vet(v);
	
	do{
		printf("\n\n\tTABELA HASH\n");
		printf("\n\t1 - Inserir\n\t2 - Imprimir\n\t3 - Buscar\n\t0 - Sair\n\n\tInforme: ");
		scanf("%d", &opc);
		
		switch(opc){
			case 1: coletar_chaves(v);
			break;
			case 2: imprimir_tabela(v);
			break;
			case 3: 
				printf("\n\tQual elemento deseja buscar? ");
				scanf("%d", &num);
				
				buscando = buscar(v, num);
				if(buscando != 0)
					printf("\n\tO elemento %d foi encontrado.", buscando);
				else
					printf("\n\tElemento %d não encontrado.", num);
			break;
			case 0:
				printf("\n\tAté a próxima! :]");
			break;
			default:
				printf("\n\tValor inválido!");
		}
	}while(opc != 0);
	
	return 0;
}
