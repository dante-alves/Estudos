#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <unistd.h> // adicionei essa s� para implementar um funcionamento de espera com sleep()

/* ATIVIDADE - Lista Sequencial e Busca Bin�ria

	Desenvolver um programa em C OU Java (n�o usar classes prontas) que apresente um menu com as op��es a seguir, realizadas por um algoritmos de LISTA SEQUENCIAL ORDENADA:
	
	
	
	Criar lista (FEITO)
	Inserir contatos (FEITO)
	Mostrar os contatos (FEITO)
	Buscar e mostra um contato (nas duas formas de busca - sequencial e bin�ria) (FEITO)
	Apagar um contato com dado nome (FEITO)
	Apagar um contato de dada posi��o (FEITO)
	Quantos contatos tenho na minha agenda (FEITO)
	Quantos novos contatos posso inserir na minha agenda (FEITO)
	Sair. (FEITO)
*/
#define MAX 100

// estrutura Contato
typedef struct{
	char nome[50];
	char telefone[15];
}Contato;

// estrutura Lista
typedef struct{
	Contato contatos[MAX]; // vetor com 100 contatos
	int pos; // �ltima posi��o ocupada no vetor
}Lista;

// limpar buffer --> essa fun��o vi em um v�deo que explicava que era melhor evitar o uso de fflush(stdin), ent�o resolvi adicionar ela aqui
void clean(){
	int c; // int c pois getchar() retorna um inteiro
	while((c = getchar()) != '\n' && c != EOF); 
}

// criar a lista
Lista criarLista(){
	Lista lista;
	
	lista.pos = -1;
	
	return lista;
}

// verificar se est� vazia
int isVazia(Lista *lista){
	return (lista->pos == -1);
}

// verificar se est� cheia
int isCheia(Lista *lista){
	return (lista->pos == MAX - 1);
}

// verificar se a posi��o � v�lida

int posValida(Lista *lista, int pos){
	if(pos > lista->pos || pos < 0)
		return 0;
	
	return 1;
}

// verificar se o contato j� existe
int verificarContato(Lista *lista, Contato dado){
	int i;
	
	for(i = 0; i <= lista->pos; i++){
		if(strcmp(lista->contatos[i].nome, dado.nome) == 0 || strcmp(lista->contatos[i].telefone, dado.telefone) == 0) // se a compara��o for zero, significa que os nomes ou telefones batem
			return i;
	}
	
	return -1;
}

// deslocar a posi��o dos contatos na lista para a direita
void deslocarDireita(Lista *lista, int pos){
	int i;
	
	if(!isVazia(lista)){
		for(i = lista->pos + 1; i > pos; i--)
			lista->contatos[i] = lista->contatos[i - 1];	
	}
}

// deslocar a posi��o dos contatos na lista para a esquerda (removendo um contato)
void deslocarEsquerda(Lista *lista, int pos){
	int i;
	
	if(!isVazia(lista)){
		for(i = pos; i < lista->pos; i++)
			lista->contatos[i] = lista->contatos[i + 1];
	}
}



// ler dados de novo contato
Contato ler_contato(){
	Contato novo;
	clean();
	printf("\n\n\tInsira o nome do contato: ");
	scanf("%49[^\n]", novo.nome);
	clean();
	printf("\n\tInsira o telefone do contato: ");
	scanf("%14[^\n]", novo.telefone);
	clean();
	
	return novo;
}

// inserir o novo contato
void inserir(Lista *lista, Contato novo, int pos){
	deslocarDireita(lista, pos);
	lista->contatos[pos] = novo;
	lista->pos++;	
	printf("\n\tContato adicionado com sucesso!\n");
}

// inserir no inicio
void inserir_no_inicio(Lista *lista, Contato novo){
	if(isCheia(lista) || verificarContato(lista, novo) != - 1) // verifica��o
		printf("\tLista cheia ou contato j� existente.\n");
	else{
		inserir(lista, novo, 0);
	}
}

// inserir no meio
void inserir_no_meio(Lista *lista, Contato novo, int pos){
	if(isCheia(lista) || (pos > lista->pos + 1) || (pos < 0)|| verificarContato(lista, novo) != -1) // verifica��o
		printf("\tLista cheia, posi��o inv�lida ou contato j� existente.\n");
	else{
		inserir(lista, novo, pos);
	}
}

// inserir no fim
void inserir_no_fim(Lista *lista, Contato novo){
	if(isCheia(lista) || verificarContato(lista, novo) != - 1) // verifica��o
		printf("\tLista cheia ou contato j� existente.\n");
	else{
		inserir(lista, novo, lista->pos + 1);
	}
}
void trocar(Contato *a, Contato *b){
	Contato aux = *a;
	*a = *b;
	*b = aux;
}
void ordenar_lista(Lista *lista){
	Contato aux;
	int i, troca, tam = lista->pos + 1;
	
	if(tam > 1){ // se tiver mais que um contato, realiza a ordena��o da lista
		do{
			troca = 0;
			for(i = 0; i < tam - 1; i++){
				if(strcmp(lista->contatos[i].nome, lista->contatos[i+1].nome) > 0){
					trocar(&lista->contatos[i], &lista->contatos[i+1]);
					troca = 1;
				}
			}
		}while(troca);	
	} 
}

// imprimir a lista
void imprimir(Lista *lista){
	int i, tam = (lista->pos + 1);
	
	if(isVazia(lista))
		printf("\n\tLista Vazia.\n");
	else{
		printf("\n\tLista De Contatos");
		printf("\n\tTotal de Contatos: %d\n\tQuantos podem ser inseridos: %d\n", tam, MAX - tam);
		printf("\t-----------------------\n");
		for(i = 0; i <= lista->pos; i++){
			printf("\t%d\n\tNome: %s\n\tTelefone: %s\n", i + 1, lista->contatos[i].nome, lista->contatos[i].telefone);
			printf("\t-----------------------\n");
		}
	}
}

// remover contato pelo nome
void remover_nome(Lista *lista, char nome[]){
	Contato removido;
	int pos;
	
	strcpy(removido.nome, nome); // passando o nome para o contato
	
	if(isVazia(lista))
		printf("\n\tLista Vazia.\n");
	else{
		pos = verificarContato(lista, removido);

		if(pos == -1)
			printf("\tContato %s n�o encontrado.\n", nome);
		else{
			deslocarEsquerda(lista, pos);
			printf("\tContato %s removido com sucesso.\n", nome);
			lista->pos--;
		}
	}
}

// remover contato pelo telefone
void remover_telefone(Lista *lista, char telefone[]){
	Contato removido;
	int pos;
	
	strcpy(removido.telefone, telefone); // passando o telefone para o contato
	
	if(isVazia(lista))
		printf("\n\tLista Vazia.\n");
	else{
		pos = verificarContato(lista, removido);

		if(pos == -1)
			printf("\tContato de n�mero %s n�o encontrado.\n", telefone);
		else{
			deslocarEsquerda(lista, pos);
			printf("\tContato de n�mero %s removido com sucesso.\n", telefone);
			lista->pos--;
		}
	}
	
	
}

// remover contato pela posi��o
void remover_posicao(Lista *lista, int pos){
	if(isVazia(lista))
		printf("\n\tLista Vazia.\n");
	else{
		if(pos <= lista->pos && pos >= 0){ // se a posi��o for v�lida
			deslocarEsquerda(lista, pos);
			printf("\tContato na posi��o %d removido com sucesso.\n", pos + 1); // pos + 1 para se adequar ao valor que aparece na interface do usu�rio (come�ando de 1, e n�o 0)
			lista->pos--;
		}
		else
			printf("\tPosi��o inv�lida. Contato n�o existente nessa posi��o.\n");
	}
}

// op��es para inserir novo contato
void menu_inserir(Lista *lista){
	int opc, pos;
	Contato novo;
	
	printf("\n\t1 - Inserir no in�cio\n\t2 - Inserir no meio\n\t3 - Inserir no fim\n\n\tInforme: ");
	scanf("%d", &opc);
	
	novo = ler_contato();
	
	switch(opc){
		case 1:
			inserir_no_inicio(lista, novo);
			break;
		case 2:
			imprimir(lista);
			printf("\n\tInforme a posi��o em que deseja inserir: ");
			scanf("%d", &pos);
			
			inserir_no_meio(lista, novo, pos);
			break;
		case 3:
			inserir_no_fim(lista, novo);
			break;
		default:
			printf("\n\tOp��o inv�lida.\n");
	}
	
}

void menu_remover(Lista *lista){
	int opc, pos;
	char nome[50], telefone[15];
	if(!isVazia(lista)){
		imprimir(lista);
		
		printf("\n\t1 - Remover via Nome\n\t2 - Remover via Telefone\n\t3 - Remover via Posi��o\n\n\tInforme: ");
		scanf("%d", &opc);
		
		switch(opc){
			case 1:
				printf("\n\tInsira o nome do contato que deseja remover: ");
				clean();
				scanf("%49[^\n]", nome);
				clean();
				remover_nome(lista, nome);
				break;
			case 2:
				printf("\n\tInsira o telefone do contato que deseja remover: ");
				clean();
				scanf("%14[^\n]", telefone);
				clean();
				remover_telefone(lista, telefone);
				break;
			case 3:
				printf("\n\tInsira a posi��o do contato que deseja remover: ");
				scanf("%d", &pos);
				clean();
				remover_posicao(lista, pos - 1); // manda pos - 1 porque na impress�o da lista, as posi��es come�am em 1, e n�o em 0
				break;
			default:
				printf("\n\tOp��o inv�lida.\n");
		}
	}
	printf("\n\tLista Vazia.\n");
}

void busca_sequencial(Lista *lista, Contato *buscar){
	int pos;
	
	imprimir(lista);
 	
 	pos = verificarContato(lista, *buscar);
 	
 	if(pos != -1){
 		printf("\n\tContato encontrado com sucesso!\n\n\tDADOS\n\tNome: %s\n\tTelefone: %s\n", 
		 lista->contatos[pos].nome, 
		 lista->contatos[pos].telefone);
	 }
	 else
	 	printf("\n\tContato n�o encontrado.\n");
}

int binaria(Lista *lista, int inicio, int fim, char *nome){
	int meio;
	
	
	while(inicio <= fim){
		if(strcmp(lista->contatos[inicio].nome, nome) == 0) // caso o nome esteja no �ndice in�cio
		return inicio;
	
		if(strcmp(lista->contatos[fim - 1].nome, nome) == 0)// caso esteja no �ndice fim
		return fim - 1;
		
		if(strcmp(lista->contatos[meio].nome, nome) == 0) // caso esteja no �ndice meio
			return meio;
		else if(strcmp(lista->contatos[meio].nome, nome) < 0)
			fim = meio - 1; // se o nome estiver abaixo da metade da lista, o fim vira meio - 1
		else
			inicio = meio + 1;// se o nome estiver acima da metade da lista, o �nicio vira meio + 1
	}
	
	return -1;
}

void busca_binaria(Lista *lista, Contato *buscar){
	int pos;
	
	int inicio = 0;
	
	pos = binaria(lista, inicio, lista->pos + 1, buscar->nome);
	
	if(pos != -1){
		printf("\n\tContato encontrado com sucesso!\n\n\tDADOS\n\tNome: %s\n\tTelefone: %s\n", 
		 lista->contatos[pos].nome, 
		 lista->contatos[pos].telefone);
	 }
	else
		printf("\n\tContato n�o encontrado.\n");
}

void menu_buscar(Lista *lista){
	 int opc, pos;
	 Contato buscar;
	 
	 
	 if(!isVazia(lista)){
	 	printf("\n\t1 - Busca Sequencial\n\t2 - Busca Bin�ria\n\n\tInforme: ");
	 	scanf("%d", &opc);
	 	
	 	ordenar_lista(lista);
		imprimir(lista);
		
	 	printf("\n\tInsira o nome do contato que deseja buscar: ");
	 	clean();
	 	scanf("%49[^\n]", buscar.nome);
	 	clean();
	 	
	 	switch(opc){
	 		case 1: busca_sequencial(lista, &buscar); break;
	 		case 2: busca_binaria(lista, &buscar); break;
	 		default: printf("\n\tOp��o inv�lida.\n"); break;
		 }
		 
		printf("Pressione ENTER para continuar...");
		getchar();
	 }
	 else
	 	printf("\n\tLista Vazia.\n");
}



// main
int main(){
	setlocale(0, "Portuguese");
	// criando a lista
	Lista lista = criarLista();
	int opc;
	char teste[20] = "4925";
	
	
	
	// menu principal
	do{
		system("cls");
		printf("\n%d\n", charValido(teste));
		int tam = lista.pos + 1;
		
		printf("\n\tLISTA DE CONTATOS\n\n");
		printf("\tN�mero de Contatos Atuais: %d\n\tQuantos ainda podem ser adicionados: %d\n", tam, MAX - tam);
		printf("\n\tMENU\n\t1 - Inserir Contato\n\t2 - Mostrar Lista\n\t3 - Buscar Contato\n\t4 - Apagar Contato\n\t0 - Sair\n\n\tInforme: ");
		scanf("%d", &opc);
		
		switch(opc){
			
			case 1:
				menu_inserir(&lista);
				sleep(2);
				break;
			case 2:
				imprimir(&lista);
				printf("\n\tPressione ENTER para continuar...");
				while(getchar() != '\n');
				getchar();
				break;
			case 3:
				menu_buscar(&lista);
				break;
			case 4:
				menu_remover(&lista);
				sleep(2);
				break;
			case 0: printf("\n\n\tAt� a pr�xima! :]\n"); break;
			default: printf("\n\n\tOp��o inv�lida...\n");
		}
	}while(opc != 0);
	
	return 0;
}
