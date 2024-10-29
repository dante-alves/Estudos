#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

// Campo minado do curso

typedef struct {
	int ehBomba;
	int vizinhos;
	int estaAberta;
}Celula;

// variáveis globais
Celula jogo[10][10];
int l, c, tam = 10;

// procedimento para inicializar a matriz
void inicializarJogo(){
	for(l = 0; l < tam; l++){
		for(c = 0; c < tam; c++){
			jogo[l][c].ehBomba = 0;
			jogo[l][c].estaAberta = 0;
			jogo[l][c].vizinhos = 0;
		}
	}
}

// procedimento para sortear n bombas
void sortearBombas(int n){
	int i;
	srand(time(NULL));
	for(i = 1; i <= n; i++){
		l = rand() % 10;
		c = rand() % 10;
		if(jogo[l][c].ehBomba == 0) // verificar se a posição selecionada já não é bomba
			jogo[l][c].ehBomba = 1;
		else
			i--;
	}
}

// Função para verificar se um par de coordenadas é válido ou não
// 1 - é válido ------ 2 - não é válido
int coordenadaValida(int l, int c){
	if(l >= 0 && l < tam && c >= 0 && c < tam)
		return 1;
	else
		return 0;
}


// Função que retorna a quantidade de bombas ao redor de l c // n = quantidade de bombas
int quantBombasVizinhas(int l, int c){
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
	
	if(coordenadaValida(l - 1, c - 1) && jogo[l-1][c-1].ehBomba)
		quantidade++;
	if(coordenadaValida(l - 1, c) && jogo[l-1][c].ehBomba)
		quantidade++;
	if(coordenadaValida(l - 1, c + 1) && jogo[l-1][c+1].ehBomba)
		quantidade++;
	if(coordenadaValida(l, c - 1) && jogo[l][c-1].ehBomba)
		quantidade++;
	if(coordenadaValida(l, c + 1) && jogo[l][c+1].ehBomba)
		quantidade++;
	if(coordenadaValida(l + 1, c - 1) && jogo[l+1][c-1].ehBomba)
		quantidade++;
	if(coordenadaValida(l + 1, c) && jogo[l+1][c].ehBomba)
		quantidade++;
	if(coordenadaValida(l + 1, c + 1) && jogo[l+1][c+1].ehBomba)
		quantidade++;
		
	return quantidade;
}


// Procedimento para contar as bombas vizinhas
void contarBombas(){
	for(l = 0; l < tam; l++){
		for(c = 0; c < tam; c++){
			jogo[l][c].vizinhos = quantBombasVizinhas(l, c);
		}
	}	
}

// Procedimento para imprimir o jogo
void imprimir(){
	
	printf("\n\n\t  ");
	for(l = 0; l < tam; l++)
		printf("   %d", l); // indices das colunas
	printf("\n\t   -----------------------------------------\n");
	for(l = 0; l < tam; l++){
		printf("\t%d  |", l); // indices das linhas
		for(c = 0; c < tam; c++){
			if(jogo[l][c].estaAberta){
				if(jogo[l][c].ehBomba)
					printf(" * ");
				else
					printf(" %d ", jogo[l][c].vizinhos);
			}
			else
				printf("   ");
			printf("|");
		}
		printf("\n\t   -----------------------------------------\n");
	}
}

// Procedimento para abrir a coordenada digitada pelo usuário
void abrirCelula(int l, int c){
	int i, j;
	
	if(coordenadaValida(l, c) == 1 && jogo[l][c].estaAberta == 0){
		jogo[l][c].estaAberta = 1;
		
		if(jogo[l][c].vizinhos == 0){
			for(i = l - 1; i <= l + 1; i++){
				for(j = c - 1; j <= c + 1; j++)
					abrirCelula(i, j);
			}
		}
	}
}

/*
	Função para verificar vitória
	n - não ganhou ainda
	0 - ganhou
*/
int ganhou(){
	int qtd = 0;
	
	for(l = 0; l < tam; l++){
		for(c = 0; c < tam; c++){
			if(jogo[l][c].estaAberta == 0 && jogo[l][c].ehBomba == 0)
				qtd++;
		}
	}
	return qtd;
}


// Procedimento jogar que faz a leitura das coordenadas
void jogar(){
	int linha, coluna;
	
	do{
		printf("\n\t\t\tCAMPO MINADO\n");
		imprimir();
		do{
			printf("\nDigite as coordenadas de linha e coluna: ");
			scanf("%d%d", &linha, &coluna);
			
			if(coordenadaValida(linha, coluna) == 0 || jogo[linha][coluna].estaAberta == 1)
				printf("\nCoordenada invalida ou ja aberta!");
		} while(coordenadaValida(linha, coluna) == 0 || jogo[linha][coluna].estaAberta == 1); //Repete enquanto a coordenada não for válida e a célula já estiver aberta
		
		abrirCelula(linha, coluna);
		system("cls");
	} while(ganhou() != 0 && jogo[linha][coluna].ehBomba == 0);
	
	printf("\n\t\t\tCAMPO MINADO\n");
	imprimir();
	if(jogo[linha][coluna].ehBomba == 1)
		printf("\n\tQue pena! Voce perdeu!\n");
	else
		printf("\n\tParabens! Voce ganhou!!!\n");
}

int main(){
	int opcao;
	
	do{
		system("cls");
		inicializarJogo();
		sortearBombas(15); // Sortear 15 bombas
		contarBombas();
		
		jogar();
		
		printf("\nDigite 1 para jogar novamente: ");
		scanf("%d", &opcao);
	}while(opcao == 1);
	return 0;
}
