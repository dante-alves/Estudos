#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/* Aula 223, 224, 225, 226 - Pilhas

223 -> Explicação de pilhas
224 -> Empilhar elemento com push();
225 -> Desempilhar elemento com pop();
226 -> Imprimir pilha


	Pilhas - Inserir ou remover elementos
		- toda operação realizada na pilha é feita no topo da pilha.
		
		- PUSH -> Empilhar
			-> *topo == NULL
							dado 3 / ponteiro para dado 2
							dado 2 / ponteiro para dado 1
							dado 1 / ponteiro NULL
						Um vai servindo de ponteiro para o próximo
		
		- POP -> Desempilhar
			-> *topo == ponteiro para dado 2
			-> criar o ponteiro *remover
			-> pegar o endereço de memória do dado 3 remove = topo
			-> free(remove)
			
			
	
	OBS: estruturas de dados dinâmicas tem a memória alocada separadamente, e isso é ótimo, pois não é preciso um espaço de memória sequencial 
	separado para aqueles dados, como em estruturas de dados estáticas.
					
Pilhas são estruturas do tipo LIFO
Last-in- First-out
-> Último a entrar, primeiro a sair

ESTRUTURA DE UM NÓ (cada dado da pilha)

typedef struct no{
	int dado;
	struct no *proximo; ----> o ponteiro para o próximo nó da pilha
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

//Protótipos de função
Pessoa ler_pessoa();
void imprimir_pessoa(Pessoa p);

void readln(char s[], int maxlen); // procedimento para ler strings

No* push(No *topo); // função para adicionar elemento à pilha
No* pop (No **topo); // função para remover elemento da pilha ----> utiliza ponteiro de ponteiro para alterar diretamente o valor de *topo na main
void imprimir_pilha(No *topo); // procedimento para imprimir a pilha
//No* popTeste(No **topo, No *alterar);

int main(){
	setlocale(0, "Portuguese");
	No *topo = NULL, *remover;
	int opcao;
	
	do{
		printf("\n1 - Empilhar\n2 - Desempilhar\n3 - Imprimir\n0 - Sair\n\nEscolha uma opção: ");
		scanf("%d", &opcao);
		while(getchar() != '\n');
		
		switch(opcao){
			case 1:
				topo = push(topo);
				break;
			case 2:
				remover = pop(&topo);
				if(remover){
					printf("\nPessoa removida: ");
					imprimir_pessoa(remover->p);
				}
				break;
			case 3:
				imprimir_pilha(topo);
				break;
			case 0:
				printf("\nFinalizando o programa. Até a próxima!\n");
				break;			
		}
	}while(opcao != 0);
	
	return 0;
}

// função para ler os dados da pessoa
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

// função para adicionar elemento à pilha
No* push(No *topo){
	No *novo = (No *)malloc(sizeof(No));
	
	if(novo){
		novo->p = ler_pessoa();
		novo->proximo = topo; // o ponteiro de novo passa a apontar para o que anteriormente estava no topo
		return novo;
	}
	else{
		printf("\nErro ao empilhar elemento.\n");
		return NULL;
	}
}
// função para remover elemento da pilha ----> utiliza ponteiro de ponteiro para alterar diretamente o valor de *topo na main
No* pop(No **topo){
	if(*topo != NULL){
		No *remover = *topo;
		*topo = remover->proximo; // passar o ponteiro do dado diretamente abaixo ao que foi removido ----> poderia ser também o dado de *topo->proximo
		return remover;
	}
	else
		printf("\nPilha Vazia!\n");
		
	return NULL;
	
}

// procedimento para imprimir a pilha
void imprimir_pilha(No *topo){
	int i = 1;
	
	if(topo != NULL){
		printf("\n------------------- P I L H A -------------------");
		while(topo != NULL){ // enquanto o ponteiro não for nulo (indicando o início da pilha), continua imprimindo
			printf("\n%dª Pessoa da Pilha\n", i++);
			imprimir_pessoa(topo->p);
			topo = topo->proximo; //topo recebe o ponteiro do próximo da pilha
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
    
    printf("\nDigite o índice da pessoa que deseja remover: ");
    scanf("%d", &ind);
    
    // Verifica se a pilha não está vazia
    if (*topo != NULL) {
        No *atual = *topo; // Variável para percorrer a pilha
        No *anterior = NULL; // Variável para guardar o nó anterior
        
        // Avança até o índice desejado
        for (i = 1; i < ind && atual != NULL; i++) {
            anterior = atual;
            atual = atual->proximo;
        }

        // Verifica se o índice existe na pilha
        if (atual != NULL) {
            remover = atual;  // O nó a ser removido
            if (anterior != NULL) {
                anterior->proximo = atual->proximo;  // Atualiza o ponteiro do nó anterior ----> anterior->proximo vai receber o ponteiro que atual aponta, pulando assim o atual.
            } else {
                *topo = atual->proximo;  // Se for o primeiro nó, atualiza o topo
            }
            
            return remover;  // Retorna o nó removido
        } else {
            printf("\nÍndice inválido!\n");
        }
    } else {
        printf("\nPilha Vazia!\n");
    }

    return NULL;  // Retorna NULL se não conseguir remover o nó
}*/
