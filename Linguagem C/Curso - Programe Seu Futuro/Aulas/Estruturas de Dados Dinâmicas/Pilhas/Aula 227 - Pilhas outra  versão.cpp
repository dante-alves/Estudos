#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/* Aula 227 - Pilhas segunda vers�o

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

typedef struct{
	No *topo;
	int tam;
}Pilha;

//Prot�tipos de fun��o
Pessoa ler_pessoa();
void imprimir_pessoa(Pessoa p);

void readln(char s[], int maxlen); // procedimento para ler strings

void push(Pilha *p); // fun��o para adicionar elemento � pilha
No* pop(Pilha *p); // fun��o para remover elemento da pilha ----> utiliza ponteiro de ponteiro para alterar diretamente o valor de *topo na main
void imprimir_pilha(Pilha *p); // procedimento para imprimir a pilha
//No* popTeste(No **topo, No *alterar);

// segunda vers�o
void criar_pilha(Pilha *p);

int main(){
	setlocale(0, "Portuguese");
	Pilha p;
	No *remover;
	int opcao;
	
	criar_pilha(&p);
	
	do{
		printf("\n1 - Empilhar\n2 - Desempilhar\n3 - Imprimir\n0 - Sair\n\nEscolha uma op��o: ");
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
				printf("\nFinalizando o programa. At� a pr�xima!\n");
				break;			
		}
	}while(opcao != 0);
	
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
void push(Pilha *p){
	No *novo = (No *)malloc(sizeof(No));
	
	if(novo){
		novo->p = ler_pessoa();
		novo->proximo = p->topo; // o ponteiro de novo passa a apontar para o que anteriormente estava no topo
		p->topo = novo;
		p->tam++;
	}
	else{
		printf("\nErro ao empilhar elemento.\n");
	}
}
// fun��o para remover elemento da pilha ----> utiliza ponteiro de ponteiro para alterar diretamente o valor de *topo na main
No* pop(Pilha *p){
	if(p->topo){
		No *remover = p->topo;
		p->topo = remover->proximo; // passar o ponteiro do dado diretamente abaixo ao que foi removido ----> poderia ser tamb�m o dado de *topo->proximo
		p->tam--;
		return remover;
	}
	else
		printf("\nPilha Vazia!\n");
		
	return NULL;
	
}

// procedimento para imprimir a pilha
void imprimir_pilha(Pilha *p){
	int i = 1;
	
	if(p->topo){
		No *aux = p->topo;
		printf("\n------------------- P I L H A  tam: %d -------------------", p->tam);
		while(aux){ // enquanto o ponteiro n�o for nulo (indicando o in�cio da pilha), continua imprimindo
			printf("\n%d� Pessoa da Pilha\n", i++);
			imprimir_pessoa(aux->p);
			aux = aux->proximo; //topo recebe o ponteiro do pr�ximo da pilha
		}
		printf("\n------------------- F I M  D A  P I L H A -------------------\n");
	}
	else
		printf("\nPilha vazia!\n");
}

/* remover um do meio ---> teste
No* popTeste(No **topo, No *alterar) {
    int ind, i;
    No *remover;
    
    printf("\nDigite o �ndice da pessoa que deseja remover: ");
    scanf("%d", &ind);
    
    // Verifica se a pilha n�o est� vazia
    if (*topo != NULL) {
        No *atual = *topo; // Vari�vel para percorrer a pilha
        No *anterior = NULL; // Vari�vel para guardar o n� anterior
        
        // Avan�a at� o �ndice desejado
        for (i = 1; i < ind && atual != NULL; i++) {
            anterior = atual;
            atual = atual->proximo;
        }

        // Verifica se o �ndice existe na pilha
        if (atual != NULL) {
            remover = atual;  // O n� a ser removido
            if (anterior != NULL) {
                anterior->proximo = atual->proximo;  // Atualiza o ponteiro do n� anterior ----> anterior->proximo vai receber o ponteiro que atual aponta, pulando assim o atual.
            } else {
                *topo = atual->proximo;  // Se for o primeiro n�, atualiza o topo
            }
            
            return remover;  // Retorna o n� removido
        } else {
            printf("\n�ndice inv�lido!\n");
        }
    } else {
        printf("\nPilha Vazia!\n");
    }

    return NULL;  // Retorna NULL se n�o conseguir remover o n�
}*/

void criar_pilha(Pilha *p){
	p->topo = NULL;
	p->tam = 0;
}
