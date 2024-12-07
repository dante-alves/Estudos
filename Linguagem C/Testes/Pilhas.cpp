#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Pilhas

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

typedef struct{
	No *topo;
	int tam;
}Pilha;

// protótipos de função
void readln(char s[], int maxlen);

void imprimir_pessoa(Pessoa p);
Pessoa ler_pessoa();

void criar_pilha(Pilha *p);

void push(Pilha *p);

No* pop(Pilha *p);

void imprimir_pilha(Pilha *p);

int main(){
	setlocale(0, "Portuguese");
	Pilha p;
	No *remover;
	int opcao;
	
	criar_pilha(&p);
	
	do{
		printf("\n1 - Empilhar\n2 - Desempilhar\n3 - Imprimir\n0 - Sair\n\nEscolha uma opção: ");
		scanf("%d", &opcao);
		while(getchar() != '\n');
		
		switch(opcao){
			case 1:
				push(&p);
				break;
			case 2:
				remover = pop(&p);
				if(remover){
					printf("\nPessoa removida: ");
					imprimir_pessoa(remover->p);
					
					free(remover);
				}
				break;
			case 3:
				imprimir_pilha(&p);
				break;
			case 0:
				printf("\nFinalizando o programa. Até a próxima!\n");
				break;			
		}
	}while(opcao != 0);
	
	return 0;
}

// procedimento para ler o input e limpar o  buffer
void readln(char s[], int maxlen){
	char ch;
	int i;
	int chars_remain;
	
	i = 0;
	chars_remain = 1; // flag para verificar se ainda têm caracteres a serem lidos
	
	while(chars_remain){ // enquanto tiver caracteres sobrando, realiza o loop
		ch = getchar(); // pega o caracter
		
		if((ch == '\n') || (ch == EOF))
			chars_remain = 0; // se o caracter for \n ou EOF a flag recebe 0, indicando que acabou ----> isso garante que o \n seja removido
		else if(i < maxlen - 1){ // se não, se i for menor que o tamanho máximo da string - 1, a string recebe o caracter
			s[i] = ch;
			i++;
		}
	}
	s[i] = '\0'; // adiciona manualmente o final da string
}
void imprimir_pessoa(Pessoa p){
		printf("\nNome: %s\n", p.nome);
		printf("Data de nascimento: %2d/%2d/%4d\n", p.data.dia, p.data.mes, p.data.ano);
}

Pessoa ler_pessoa(){
	Pessoa p;
	
	printf("\nDigite o nome da pessoa: ");
	readln(p.nome, 50);
	printf("\nDigite a data de nascimento dd/mm/aaaa: ");
	scanf("%d/%d/%d", &p.data.dia, &p.data.mes, &p.data.ano);
	
	return p;
}

void criar_pilha(Pilha *p){
	p->topo = NULL;
	p->tam = 0;
}

void push(Pilha *p){
	No *novo = (No *)malloc(sizeof(No));
	
	if(novo){
		novo->p = ler_pessoa();
		novo->proximo = p->topo;
		p->topo = novo;
		p->tam++;
	}
	else
		printf("\nErro ao alocar memória!\n");
}

No* pop(Pilha *p){
	No *remover;
	
	if(p->topo){
		remover = p->topo;
		p->topo = remover->proximo;
		p->tam--;
		
		return remover;
	}
	else
		printf("\nPilha vazia!\n");
	return NULL;
}

void imprimir_pilha(Pilha *p){
	No *aux;
	
	if(p->topo){
		aux = p->topo;
		printf("\n------------------- P I L H A  tam: %d -------------------", p->tam);
		while(aux){
			imprimir_pessoa(aux->p);
			aux = aux->proximo;
		}
		printf("\n------------------- F I M  D A  P I L H A -------------------");
	}
	else
		printf("\nPilha vazia!\n");
}
