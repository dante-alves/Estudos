#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/* Aula 223, 224 - Pilhas

223 -> Explica��o de pilhas
224 -> Empilhar elemento com push();
225 -> Desempilhar elemento com pop();


	Pilhas - Inserir ou remover elementos
		- toda opera��o realizada na pilha � feita no topo da pilha.
		
		- PUSH -> Empilhar
			-> *topo == NULL
							dado 3 / ponteiro para dado 2
							dado 2 / ponteiro para dado 1
							dado 1 / ponteiro NULL
						Um vai servindo de ponteiro para o pr�ximo
		
		- POP -> Desempilhar
			-> *topo == ponteiro para dado 2
			-> criar o ponteiro *remover
			-> pegar o endere�o de mem�ria do dado 3 remove = topo
			-> free(remove)
			
			
	
	OBS: estruturas de dados din�micas tem a mem�ria alocada separadamente, e isso � �timo, pois n�o � preciso um espa�o de mem�ria sequencial 
	separado para aqueles dados, como em estruturas de dados est�ticas.
					
Pilhas s�o estruturas do tipo LIFO
Last-in- First-out
-> �ltimo a entrar, primeiro a sair

ESTRUTURA DE UM N� (cada dado da pilha)

typedef struct no{
	int dado;
	struct no *proximo; ----> o ponteiro para o pr�ximo n� da pilha
}t_No;

*/
typedef struct{
	int dia, mes, ano;
}Data;

typedef struct{
	char nome[50];
	Data data;
}Pessoa;

typedef struct no{
	Pessoa p;
	struct no *proximo;	
}No;

//Prot�tipos de fun��o
Pessoa ler_pessoa();
void imprimir_pessoa(Pessoa p);

void readln(char s[], int maxlen); // procedimento para ler strings

No* push(No *topo); // fun��o para adicionar elemento � pilha
No* pop (No **topo); // fun��o para remover elemento da pilha ----> utiliza ponteiro de ponteiro para alterar diretamente o valor de *topo na main

int main(){
	setlocale(0, "Portuguese");
	No *topo = NULL, *remover;
	int opcao;
	
	do{
		printf("\n1 - Empilhar\n2 - Desempilhar\n3 - Imprimir\n0 - Sair");
		scanf("%d", &opcao);
		while(getchar() != '\n');
		
		switch(opcao){
			case 1:
				topo = push(topo);
				break;
			case 2:
				remover = pop(&topo);
				break;
			case 3:
				
				break;
			case 0:
				
				break;
			default:
						
		}
	}
	
	return 0;
}

// fun��o para ler os dados da pessoa
Pessoa ler_pessoa(){
	Pessoa p;
	
	printf("\nDigite o nome da pessoa: ");
	readln(p.nome, 50);
	
	printf("\nDigite a data de nascimento dd/mm/aaaa: ", &p.data.dia, &p.data.mes, &p.data.ano);
	scanf("%d/%d/%d", &p.data.dia, &p.data.mes, &p.data.ano);
	return p;
}

// procedimento para imprimir pessoa
void imprimir_pessoa(Pessoa p){
	printf("\nNome: %s\nData: %2d/%2d/%4d\n", p.nome, p.data.dia, p.data.mes, p.data.ano);
}

// procedimento para ler o input e limpar o  buffer
void readln(char s[], int maxlen){
	char ch;
	int i;
	int chars_remain;
	i = 0;
	chars_remain = 1; // flag para verificar se ainda t�m caracteres a serem lidos
	
	while(chars_remain){ // enquanto tiver caracteres sobrando, realiza o loop
		ch = getchar(); // pega o caracter
		
		if((ch == '\n') || (ch == EOF))
			chars_remain = 0; // se o caracter for \n ou EOF a flag recebe 0, indicando que acabou ----> isso garante que o \n seja removido
		else if(i < maxlen - 1){ // se n�o, se i for menor que o tamanho m�ximo da string - 1, a string recebe o caracter
			s[i] = ch;
			i++;
		}
	}
	s[i] = '\0'; // adiciona manualmente o final da string
}

// fun��o para adicionar elemento � pilha
No* push(No *topo){
	No *novo = (No *)malloc(sizeof(No));
	
	if(novo){
		novo->p = ler_pessoa();
		novo->proximo = topo;
		return novo;
	}
	else{
		printf("\nErro ao empilhar elemento.\n");
		return NULL;
	}
}
// fun��o para remover elemento da pilha ----> utiliza ponteiro de ponteiro para alterar diretamente o valor de *topo na main
No* pop(No **topo){
	if(*topo != NULL){
		No *remover = *topo;
		*topo = remover->proximo; // passar o ponteiro do dado diretamente abaixo ao que foi removido
		return remover;
	}
	else{
		printf("\nPilha Vazia!\n");
		return NULL;
	}
}
