#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
//Projeto Xadrez

/*
	- Tutorial 
		- Regras do jogo
		- Movimento das peças
	
	- Tabuleiro
					[NEGRAS]
					
		---------------------------------
	8	| r | h | b | q | k | b | h | r |
		---------------------------------
	7	| p | p | p | p | p | p | p | p |
		---------------------------------
	6	|   |   |   |   |   |   |   |   |
		---------------------------------
	5	|   |   |   |   |   |   |   |   |
		---------------------------------
	4	|   |   |   |   |   |   |   |   |
		---------------------------------
	3	|   |   |   |   |   |   |   |   |
		---------------------------------
	2	| P | P | P | P | P | P | P | P |
		---------------------------------
	1	| R | H | B | Q | K | B | H | R |
		---------------------------------
		  a   b   c   d   e   f   g   h
		  
					[BRANCAS]
					
		P - Pawn | Peão
		R - Rook | Torre
		H - Horse | Cavalo
		B - Bishop | Bispo
		Q - Queen | Rainha
		K - King | Rei

*/

// variáveis globais
char jogo[8][8];
int l, c;


// procedimento para inicializar a matriz
void inicializarMatriz(){
	
	for(l = 0; l < 8; l++){
		for(c = 0; c < 8; c++){
			jogo[l][c] = ' ';
		}
	}
	
	//Torres
	jogo[0][0] = jogo[0][7] = 'r';
	jogo[7][0] = jogo [7][7] = 'R';
	//Cavalos
	jogo[0][1] = jogo[0][6] = 'h';
	jogo[7][1] = jogo[7][6] = 'H';
	//Bispos
	jogo[0][2] = jogo[0][5] = 'b';
	jogo[7][2] = jogo[7][5] = 'B';
	//Rainhas
	jogo[0][3] = 'q';
	jogo[7][3] = 'Q';
	//Reis
	jogo[0][4] = 'k';
	jogo[7][4] = 'K';
	
	//Peões
	l = 1;
	for(c = 0; c < 8; c++)
		jogo[l][c] = 'p';
		
	l = 6;
	for(c = 0; c < 8; c++)
		jogo[l][c] = 'P';
	
}

// procedimento para imprimir o jogo
void imprimir(){

	printf("\t\t\t[NEGRAS]\n\n");
	printf("\t  ---------------------------------\n");
	for(l = 0; l < 8; l++){
		printf("\t%d |", 8 - l); //Mostrar a coordenada
		for(c = 0; c < 8; c++){
			printf(" %c |", jogo[l][c]);
		}
	printf("\n\t  ---------------------------------\n");
	}
	printf("\t    a   b   c   d   e   f   g   h\n\n");
	printf("\t\t\t[BRANCAS]\n\n");
}

// função que retorna se a coordenada é válida --> Retorna 1 se for válida
int coordenadaValida(){
	if(l >= 0 && c >= 0 && l < 8 && c < 8)
		return 1;
	else
		return 0; 
}

void transformarCoordenada(char coluna, int linha){

	l = 8 - linha;
	
	switch(coluna){
		case 'a':
			c = 0;
			break;
		case 'b':
			c = 1;
			break;
		case 'c':
			c = 2;
			break;
		case 'd':
			c = 3;
			break;
		case 'e':
			c = 4;
			break;
		case 'f':
			c = 5;
			break;
		case 'g':
			c = 6;
			break;
		case 'h':
			c = 7;
		
	}
}

void lerCoordenada(){
	char coluna;
	int linha;
	
	printf("Digite a coordenada que quer jogar: ");
	scanf("%c%d", &coluna, &linha);
	
	transformarCoordenada(coluna, linha);
	
	while(!coordenadaValida()){
		printf("Coordenada invalida! Digite outra coordenada: ");
		scanf("%c%d", &coluna, &linha);
		transformarCoordenada(coluna, linha);
	}
	
	printf("\n%d %d", l, c);
}

int main(){
	
	inicializarMatriz();
	
	imprimir();
	
	lerCoordenada();
	
	
	return 0;
}
