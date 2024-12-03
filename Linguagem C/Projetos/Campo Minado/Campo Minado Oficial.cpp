#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

// Definindo o tipo Blocos
typedef struct{
	int mina;
	int selecionado;
	int vizinhos;
}Blocos;

// Variáveis Globais
Blocos bloco[10][10];
int l, c, tam = 6;

// Procedimento para inicializar a matriz
void iniciarMatriz(){
	for(l = 0; l < tam; l++){
		for(c = 0; c < tam; c++){
			bloco[l][c].mina = 0;
			bloco[l][c].selecionado = 0;
			bloco[l][c].vizinhos = 0;
		}
	}
}

// Procedimento para sortear as minas em blocos aleatórios
void sortearMinas(int n){
	int i = 0;
	srand(time(NULL));
	
	while(i < n){
		l = rand() % 8;
		c = rand() % 8;
		if(bloco[l][c].mina == 0){
			bloco[l][c].mina = 1;
			i++;
		}
	}
}

// Função para verificar se uma coordenada é válida
int coordenadaValida(int l, int c){
	if(l >= 0 && l < tam && c >= 0 && c < tam)
		return 1;
	else
		return 0;
}

// Função para verificar quantas minas tem ao redor de um bloco
int qtdMinas(int linha, int coluna){
	/*
		Posições vizinhas possíveis
		l - 1 e c - 1
		l - 1 e c
		l - 1 e c + 1
		--------------
		l e c - 1
		l e c + 1
		--------------
		l + 1 e c - 1
		l + 1 e c
		l + 1 e c + 1	
	*/
	int quantidade = 0;
	
	if(coordenadaValida(l - 1, c - 1) && bloco[l-1][c-1].mina)
		quantidade++;
	if(coordenadaValida(l - 1, c) && bloco[l-1][c].mina)
		quantidade++;
	if(coordenadaValida(l - 1, c + 1) && bloco[l-1][c+1].mina)
		quantidade++;
	if(coordenadaValida(l, c - 1) && bloco[l][c-1].mina)
		quantidade++;
	if(coordenadaValida(l, c + 1) && bloco[l][c+1].mina)
		quantidade++;
	if(coordenadaValida(l + 1, c - 1) && bloco[l+1][c-1].mina)
		quantidade++;
	if(coordenadaValida(l + 1, c) && bloco[l+1][c].mina)
		quantidade++;
	if(coordenadaValida(l + 1, c + 1) && bloco[l+1][c+1].mina)
		quantidade++;
		
	return quantidade;
}

// Procedimento para indicar quantas minas tem ao redor de todos os blocos
void contarMinas(){
	for(l = 0; l < tam; l++){
		for(c = 0; c < tam; c++){
			bloco[l][c].vizinhos = qtdMinas(l, c);
		}
	}
}

// Procedimento para imprimir as linhas dependendendo do tamanho do tabuleiro do jogo
void linha(){
	if(tam == 10)
		printf("\n\t\t    ----------------------------------------\n");
	if(tam == 8)
		printf("\n\t\t    --------------------------------\n");
	if(tam == 6)
		printf("\n\t\t    ------------------------\n");
	
}

// Procedimento para imprimir o jogo
void imprimir(){
	printf("\n\t\t\t     CAMPO MINADO\n\n\t\t   ");
	for(l = 0; l < tam; l++) 
		printf("  %d ", l); //indices das colunas
	linha();
	for(l = 0; l < tam; l++){
		printf("\t\t%d  |", l); //indices das linhas
		for(c = 0; c < tam; c++){
			if(bloco[l][c].selecionado == 0)
				printf("   ");
			else{
				if(bloco[l][c].mina)
					printf(" * ");
				else
					printf(" %d ", bloco[l][c].vizinhos);
			}
			printf("|");
		}
	linha();
	}
}

// Procedimento para abrir um bloco selecionado
void abrirBloco(int l, int c){
	int i, j;
	
	if(coordenadaValida(l, c) == 1 && bloco[l][c].selecionado == 0){
		bloco[l][c].selecionado = 1;
	
		if(bloco[l][c].vizinhos == 0){
			for(i = l - 1; i <= l + 1; i++){
				for(j = c - 1; j <= c + 1; j++) 
						abrirBloco(i, j);
			}
		}
	}
}

// Função que retorna se ganhou ou não (se retornar 0, é porque ganhou, se retornar mais, é pq ainda faltam blocos a serem abertos.
int ganhou(){
	int qtd = 0;
	
	for(l = 0; l < tam; l++){
		for(c = 0; c < tam; c++){
			if(bloco[l][c].selecionado == 0 && bloco[l][c].mina == 0)
				qtd++;
		}
	}
	
	return qtd;
}

<<<<<<< Updated upstream
// Procedimento para calcular o tempo de jogo
=======
// procedimento para calcular e mostrar o tempo de jogo
>>>>>>> Stashed changes
void tempoDeJogo(time_t end, time_t start){
	double tempoTotal = difftime(end, start);
	int minutos, segundos;
	
	minutos = (int)tempoTotal / 60;
	segundos = (int)tempoTotal % 60;
	
	printf("\n\t\tTempo de jogo: %d minutos e %d segundos\n", minutos, segundos);
}

// Procedimento principal para jogar o jogo
void jogar(){
	int linha, coluna;
	
	time_t inicio, fim;
	
	inicio = time(NULL);
	do {
		imprimir();
		do{
			printf("\t\tInsira uma coordenada para jogar: ");
			
			scanf("%d%d", &linha, &coluna);
			fflush(stdin);
			
			if(coordenadaValida(linha, coluna) == 0 || bloco[linha][coluna].selecionado == 1)
				printf("\t\tCoordenada invalida ou ja selecionada!\n");	
		} while(coordenadaValida(linha, coluna) == 0 || bloco[linha][coluna].selecionado == 1);
		
		abrirBloco(linha, coluna);
		system("cls");
	} while(ganhou() != 0 && bloco[linha][coluna].mina == 0);
	fim = time(NULL);
	
	imprimir();
	
	if(ganhou() == 0)
		printf("\n\t\tParabens! Voce ganhou!!!\n");
	else
		printf("\n\t\tQue pena... Voce perdeu!\n");
	
	tempoDeJogo(fim, inicio);
}

void tamanhoJogo(){
	int escolha;
	
	printf("Tamanho do Campo Minado:\n(1)Grande\n(2)Medio\n(3)Pequeno\n");
	scanf("%d", &escolha);
	fflush(stdin);
	
	while(escolha != 1 && escolha != 2 && escolha != 3){
		system("cls");
		printf("Opcao invalida! Escolha novamente.\n");
		printf("Tamanho do Campo Minado:\n(1)Grande\n(2)Medio\n(3)Pequeno\n");
		scanf("%d", &escolha);
		fflush(stdin);
	}
	
	if(escolha == 1)
		tam = 10;
	else if(escolha == 2)
		tam = 8;
	else
		tam = 6;
	
}

int main(){
	int opcao;
	
	do{
		system("cls");
		tamanhoJogo();
		system("cls");
		
		iniciarMatriz();
		sortearMinas(tam + 2);
		contarMinas();
		
		jogar();
		
		printf("\t\tDigite 1 para jogar novamente: ");
		scanf("%d", &opcao);
		fflush(stdin);
	}while (opcao == 1);
	
	return 0;
}
