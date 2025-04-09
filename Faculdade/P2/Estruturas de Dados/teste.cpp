#include    <stdio.h>
#include    <stdlib.h>
#include    <locale.h>
#include 	<time.h>
#include	<string.h>
/*
    Desenvolver um programa em C OU Java (não usar classes prontas) que apresente um menu com as opções a seguir, 
    realizadas por um algoritmos de LISTA SEQUENCIAL ORDENADA:

        1. Criar lista (V)
        2. Inserir contatos (V)
        3. Mostrar os contatos (V)
        4. Buscar e mostra um contato (nas duas formas de busca - sequencial e binária)
        5. Apagar um contato com dado nome (V)
        6. Apagar um contato de dada posição (V)
        7. Quantos contatos tenho na minha agenda (v)
        8. Quantos novos contatos posso inserir na minha agenda (v)
        9. Sair. (V)
	
	
	Por enquanto, só fiz a busca de forma binária
		Ps: Voltar aqui e fazer as outras funções de forma binária (quando melhorar em lógica).
		
		Pelo que mini estudei
			iterativa -> melhor para arrays ordenados (Utilizarei essa)
			
			recursiva -> arvore binária.
*/

// definir o tamanho maximo da lista sequencial ordenada

#define MAX 50


/*
    estrutura para pegar os dados 
        -> t_Contato
            -> nome
            -> telefone.
*/ 

typedef struct {
    char nome[50];
    char telefone[20];
} t_Contato;

/*
    Estrtura para lista
        -> t_Lista
            -> contatos[tamanho]
            -> indice
*/

typedef struct {
    t_Contato contatos[50];
    int indice;
} t_Lista;

// Ponto 1. da atividade
// funcao para criar a lista 
t_Lista criarLista() {

    t_Lista lista;
    lista.indice = -1; // indice -1. Lista está vazia.
    return lista;
}

void trocar(t_Contato *primeiroContato, t_Contato *segundoContato) {
	t_Contato *aux = primeiroContato;
	primeiroContato = segundoContato;
	segundoContato = primeiroContato;
}

int ordenarLista(t_Lista *lista) {
	t_Contato aux;
	
	for(int i = 0; i < lista->indice; i++) {
		if(strcmp(lista->contatos[i].nome, lista->contatos[i + 1].nome) > 0) {
			trocar(&lista->contatos[i], &lista->contatos[i + 1]);
		}
	}
	
	/*
		1 INDICE JOSE -> 2 ANTONIO
		JOSE > ANTONIO
		
		ANTONIO > A
	*/
	return 1;
}

// ponto 3. da atividade
// procedimento para imprimir lista.
void imprimirLista(t_Lista *lista) {

    printf("\n---- L I S T A [tamanho Máximo = 50]------------\n");
    for(int i = 0; i < lista->indice + 1; i++) 
        printf("\t[%d.] -- %s -- %s\n", 
                                i + 1, 
                                lista->contatos[i].nome, 
                                lista->contatos[i].telefone
        );
    printf("--------------------------------------------\n");
    
}

// função para pegar os dados do usuario.
t_Lista *pegarUserDados (t_Lista *lista, int pos) {
	printf("\n-------- PEGAR DADOS --------- \n");
    printf("\nDigite o seu nome: ");
    scanf("%49[^\n]", lista->contatos[pos].nome);
	fflush(stdin);
	
    printf("Digite o seu Numero: ");
    scanf("%19[^\n]", lista->contatos[pos].telefone);
	fflush(stdin);
	
	lista->indice++; // acrescetando o tamanho da lista.
    return lista;
}

// funcao para verificar se é vazia.
int isVazia(t_Lista *lista) {
    return (lista->indice == -1);
}

int isCheia(t_Lista *lista) {
	return (lista->indice == MAX - 1);
}

// funcao para pedir a posição ao usuario
int pedirPosicao(t_Lista *lista) {
	int pos;
	imprimirLista(lista);
	printf("\nDigite a posição: ");
	scanf("%d", &pos);
	fflush(stdin);
	/*
		 pq coloquei lista->indice + 2? Pq, como o usuário ainda não digitou a pos
		 ,consequetemente ele não digitou os dados do contato, e não acrescentou +1 dado.
		 
		 Ex:
		 	ImprimirLista
		 		[1.] - Antonio - xxx
		 		[2.] - Jose - yyy
		 	
		 	Qual posição quer colocar. Se eu eu utilizar lista->indice + 1 dará erro, caso eu digite pos 3.
		 	
	*/
	
	
	// caso digite um valor inválido.
	while(pos < 1 || pos > lista->indice + 2) {
		printf("\nValor Invalido!\nInforme corretamente: ");
		printf("\nDigite a posição: ");
		scanf("%d", &pos);
		fflush(stdin);	
	}
	
	
	return pos - 1; // retornando decrementado
}

/*
	if(isVazia(lista)) está vazia? 
		Ent, n possui nenhum dado na lista, logo colocará na pos 0 do vetor.
		Nao está vazia, ent pede a posição ao usuário mostrando as posições
*/
int pegarPosicao(t_Lista *lista) {
	return isVazia(lista) ? 0 : pedirPosicao(lista);
}

// funcao para deslocar o vetor para a direita ao ser inserido um dado.
int deslocaDireita(t_Lista *lista, int pos) {
	
	for(int i = lista->indice + 1; i > pos; i--)
		lista->contatos[i] = lista->contatos[i - 1];
	
	return 1;
}

// testando
int inserirContato2(t_Lista *lista, int pos, t_Contato contato) {
	
	deslocaDireita(lista, pos);
	
	lista->contatos[pos] = contato;
	lista->indice++;
	ordenarLista(lista); // ta errado ainda
	return 1;
}

// ponto 2. para a atividade
// função para inserirContato.
int inserirContato(t_Lista *lista) {
	
	if(isCheia(lista)) {
		printf("\nA lista está cheia...\n");
		return 0;
	}
		
    int pos; // variavel para pegar a posicao onde o usu quer digitar.
    
    pos = pegarPosicao(lista);
    
    deslocaDireita(lista, pos);
    
    lista = pegarUserDados(lista, pos); // chamando função para pegar os dados dele.

	// lista vazia, ent n precisa desloca para a direta.
	if(isVazia(lista))
		return 1;
	
    return 1;
}

// função para deslocar a esquerda
int deslocaEsquerda(int pos, t_Lista *lista) {
	printf("\nUsuário: %s removido com sucesso\n", lista->contatos[pos].nome);
	for(int i = pos; i < lista->indice; i++)
		lista->contatos[i] = lista->contatos[i + 1];
		
	return 1;
}

// função para achar o indice do nome.
findIndiceUser(char *nomeInLista, char *nomeFindUser) {
	return strcmp(nomeInLista, nomeFindUser);
}

// ponto 5
// função para apagar o contato por nome.

int removerContato_porNome(t_Lista *lista) {
	
	if(isVazia(lista)) {
		printf("\nLista está vaziaa...");
		return 0;
	}
		
	
	char nome[50];
	printf("\nDigite o nome do usuário o qual quer remover: ");
	scanf("%49[^\n]", nome);
	
	for(int i = 0; i < lista->indice + 1; i++) {
		if(findIndiceUser(lista->contatos[i].nome, nome) == 0) 
			return deslocaEsquerda(i, lista); // apagando usuário...
	}
	
	printf("\nUsuário não existe...\n");
	return -1;
}


// ponto 6
// funcao para apagar o contato por posicao

int removerContato_porPosicao(t_Lista *lista) {
	if(isVazia(lista)) {
		printf("\nLista está vaziaa...");
		return 0;
	}
	
	int pos;
	
	imprimirLista(lista);	
	printf("\nDigite a posição o qual quer remover: ");
	scanf("%d", &pos);
	fflush(stdin);
	if(pos < 1 || pos > lista->indice + 2) {
		printf("\nValor inválido!\tSaindo...");
		return 0;
	}
	
	deslocaEsquerda(pos - 1, lista);
	lista->indice--;
	return 1;
}

// ponto 4 da atividade 
// Buscar e mostra um contato (nas duas formas de busca - sequencial e binária)

// busca sequencial. 
/*
	O que pensei, foi. Buscar um nome e mostrar todos?
		Filtro = Antonio
			[1.] -> Antonio Felix (mostra)
			[2.] -> Antonio Olviveira (mostra)
			[3.] -> Antonioo
	
	-> Pensar dps como fazer.
*/
// por id.
int buscaUsuario_Sequencial(t_Lista *lista) {
	int pos = pegarPosicao(lista);
	
	if(isVazia(lista)) {
		printf("\nA Lista está vazia...");
		return 0;
	}


	if(pos == lista->indice + 1) {
		printf("\nUsuário não encotrado");
		return 0;
	}
	
	printf("Usuário encontrado:\n");
	printf("[%d.]---Nome: %s\tTelefone: %s", 
										pos + 1, 
										lista->contatos[pos].nome, 
										lista->contatos[pos].telefone
	);

	return 1;
}

/*
	 busca binária iterativa.
	 -> Irei fazer pelo nome
	 Loop que divide no meio a array
*/

int findUser_Binario(t_Lista  *lista, int inicio, int fim, char *nome) {
	
	int meio;
	
	if(findIndiceUser(lista->contatos[inicio].nome, nome) == 0)
		return inicio;
	
	if(findIndiceUser(lista->contatos[fim - 1].nome, nome) == 0)
		return fim - 1;
		
	while(inicio <= fim) 
	{
		meio = (inicio + fim)/2;
		
		if(findIndiceUser(lista->contatos[meio].nome, nome) == 0)
			return meio;
		else if(findIndiceUser(lista->contatos[meio].nome, nome) < 0)
			fim = meio - 1;
		else
			inicio = meio + 1;
		
	}
	
	return -1; // nao achou
}

int buscaUsuario_Binario(t_Lista *lista) {
	ordenarLista(lista);
	imprimirLista(lista);
	char nome[50];
	printf("\nDigite o nome o qual quer buscar: ");
	scanf("%49[^\n]", nome);
	
	// ordenarLista(lista);
	
	int inicio = 0;
	int pos = findUser_Binario(lista, inicio, lista->indice + 1, nome) ; // lista->indice + 1 == fim.
	
	if(pos == -1) {
		printf("\nUsuário não encotrado\n");
		return -1;
	}
		
	printf("Usuário encontrado:\n");
	printf("[%d.]---Nome: %s\tTelefone: %s", 
										pos + 1, 
										lista->contatos[pos].nome, 
										lista->contatos[pos].telefone
	);
	return 1;
}

// ponto 7
// função para verificar quantos contantos tenho na minha agenda
int tamanhoLista(t_Lista *lista) {
    return lista->indice + 1;
}

// ponto 8
// funçãso para verificar o tamanho restante da lista
int tamanhoRestanteLista(t_Lista *lista) {
    return MAX - (lista->indice + 1);
}

void menu(t_Lista * lista) {
	
	int opcao;
	do {
		printf("\n --------------------M-E-N-U--------------------\n|\t\t\t\t\t\t|\n");
		printf(
		"|\t[1.] - Inserir Contato\t\t\t|\n|\t[2.] - Remover Contato [Por Nome]\t|\n|\t[3.] - Remover Contato [Por Posição]\t|\n|\t[4.] - Buscar Contato (Sequencial)\t|\n|\t[5.] - Buscar Contato (Binário)\t\t|\n|\t[6.] - Imprimir Lista\t\t\t|\n|\t[7.] - Tamanho da Lista (MAX e Resto)\t|\n|\t[8.] - Sair\t\t\t\t|\n|\t\t\t\t\t\t|"
		);
		printf("\n -----------------------------------------------\n");
		printf("\nInforme: ");
		scanf("%d", &opcao);
		fflush(stdin);
		
		switch(opcao) {
			
			case 1 : 
				printf("\nPs: Você pode inserir 1 posição à frente do que existe: Ex: Só tem um usuário [1.]\nVoce pode inserir na posição do usuário existen ou 1 posição a frente dele (2).\n");
				inserirContato(lista); 
				break;
			
			case 2 : removerContato_porNome(lista); break;
			
			case 3 : removerContato_porPosicao(lista); break;
			
			case 4 : buscaUsuario_Sequencial(lista); break;
			
			case 5 : buscaUsuario_Binario(lista); break;
			
			case 6 : imprimirLista(lista); break;
			
			case 7 :
				printf("\nTamanho da Lista: %d", tamanhoLista(lista));
    			printf("\nContatos Restantes para inserir: %d\n", tamanhoRestanteLista(lista));
    			break;
				
			default : printf("\nSaindo..."); break;
		}
	} while(opcao && opcao != 8);
}

int main() {
	setlocale(0,"Portuguese");
	t_Lista lista;
	t_Contato aux1 = {"Antonio", "111111"};
	t_Contato aux2 = {"Beatriz", "222222"};
	t_Contato aux3 = {"Carlos", "333333"};
	t_Contato aux4 = {"Daniela", "444444"};
	t_Contato aux5 = {"Eduardo", "555555"};
	t_Contato aux6 = {"Fernanda", "666666"};
	t_Contato aux7 = {"Gabriel", "777777"};
	t_Contato aux8 = {"Helena", "888888"};
	t_Contato aux9 = {"Igor", "999999"};
	t_Contato aux10 = {"Juliana", "101010"};
	t_Contato aux11 = {"Kleber", "111000"};
	t_Contato aux12 = {"Larissa", "121212"};
	t_Contato aux13 = {"Marcos", "131313"};
	t_Contato aux14 = {"Natália", "141414"};
	t_Contato aux15 = {"Otávio", "151515"};
	t_Contato aux16 = {"Patrícia", "161616"};
	t_Contato aux17 = {"Quirino", "171717"};
	t_Contato aux18 = {"Renata", "181818"};
	t_Contato aux19 = {"Samuel", "191919"};
	t_Contato aux20 = {"Tatiane", "202020"};
	t_Contato aux21 = {"Ulisses", "212121"};
	t_Contato aux22 = {"Vanessa", "222222"};
	t_Contato aux23 = {"William", "232323"};
	t_Contato aux24 = {"Xavier", "242424"};
	t_Contato aux25 = {"Yasmin", "252525"};
	t_Contato aux26 = {"Zé", "262626"};
	t_Contato aux27 = {"Adriana", "272727"};
	t_Contato aux28 = {"Bruno", "282828"};
	t_Contato aux29 = {"Camila", "292929"};
	t_Contato aux30 = {"Diego", "303030"};
	t_Contato aux31 = {"Elisa", "313131"};
	t_Contato aux32 = {"Fabiano", "323232"};
	t_Contato aux33 = {"Giovana", "333333"};
	t_Contato aux34 = {"Henrique", "343434"};
	t_Contato aux35 = {"Isabela", "353535"};
	t_Contato aux36 = {"João", "363636"};
	t_Contato aux37 = {"Karina", "373737"};
	t_Contato aux38 = {"Leandro", "383838"};
	t_Contato aux39 = {"Mônica", "393939"};
	t_Contato aux40 = {"Nelson", "404040"};
	
    // chamando para criar lista.
    lista = criarLista();
    
    inserirContato2(&lista, 0, aux1);
    inserirContato2(&lista, 1, aux2);
	inserirContato2(&lista, 2, aux3);
	inserirContato2(&lista, 3, aux4);
	inserirContato2(&lista, 4, aux5);
	inserirContato2(&lista, 5, aux6);
	inserirContato2(&lista, 6, aux7);
	inserirContato2(&lista, 7, aux8);
	inserirContato2(&lista, 8, aux9);
	inserirContato2(&lista, 9, aux10);
	inserirContato2(&lista, 10, aux11);
	inserirContato2(&lista, 11, aux12);
	inserirContato2(&lista, 12, aux13);
	inserirContato2(&lista, 13, aux14);
	inserirContato2(&lista, 14, aux15);
	inserirContato2(&lista, 15, aux16);
	inserirContato2(&lista, 16, aux17);
	inserirContato2(&lista, 17, aux18);
	inserirContato2(&lista, 18, aux19);
	inserirContato2(&lista, 19, aux20);
	inserirContato2(&lista, 20, aux21);
	inserirContato2(&lista, 21, aux22);
	inserirContato2(&lista, 22, aux23);
	inserirContato2(&lista, 23, aux24);
	inserirContato2(&lista, 24, aux25);
	inserirContato2(&lista, 25, aux26);
	inserirContato2(&lista, 26, aux27);
	inserirContato2(&lista, 27, aux28);
	inserirContato2(&lista, 28, aux29);
	inserirContato2(&lista, 29, aux30);
	inserirContato2(&lista, 30, aux31);
	inserirContato2(&lista, 31, aux32);
	inserirContato2(&lista, 32, aux33);
	inserirContato2(&lista, 33, aux34);
	inserirContato2(&lista, 34, aux35);
	inserirContato2(&lista, 35, aux36);
	inserirContato2(&lista, 36, aux37);
	inserirContato2(&lista, 37, aux38);
	inserirContato2(&lista, 38, aux39);
	inserirContato2(&lista, 39, aux40);
    menu(&lista);
    return 0;
}

