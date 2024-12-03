#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Aula 166 - Jogo da Velha

//Vari�veis Globais
char jogo[3][3];
int l, c, pos = 0;

//procedimento para inicializar todas as posi��es da matriz
void inicializarMatriz() {
	for (l = 0; l < 3; l++) {
		for(c = 0; c < 3; c++) {
			jogo[l][c] = ' ';
		}
	}
}

//procedimento para imprimir posi��es na tela
void imprimirPosicoes() {
	setlocale(0, "Portuguese");
	int cont = 0;
	printf("POSI��ES DE CADA QUADRADO\n");
	printf("--------------------------\n\n");
	for (l = 0; l < 3; l++) {
		for (c = 0; c < 2; c++) {
			if (c == 0)
				printf("   ");
			printf("%d|", ++cont);
			
		}
		printf("%d\n", ++cont);
		
		if (l < 2)
			printf("  -------\n");
	}
	printf("\n--------------------------\n\n");
}

//procedimento para imprimir o jogo em si na tela
void imprimirJogo() {
	for (l = 0; l < 3; l++) {
			for (c = 0; c < 2; c++) {
				if (c == 0)
					printf("   ");
				printf("%c|", jogo[l][c]);
				
			}
			printf("%c\n", jogo[l][c]);
			
			if (l < 2)
				printf("  -------\n");
		}
}


//fun��o para verificar vit�ria por linhas --> 1 = ganhou; 0 = n�o ganhou ainda
int ganhouPorLinhas(char X) {
	int cont = 0;
	for (l = 0; l < 3; l++) {
		if (jogo[l][0] == X && jogo[l][0] == jogo[l][1] && jogo[l][1] == jogo[l][2])
			cont++;
	}
	return cont;
}

//fun��o para verificar vit�ria por colunas
int ganhouPorColunas(char X) {
	int cont = 0;
	for (c = 0; c < 3; c++) {
		if (jogo[0][c] == X && jogo[0][c] == jogo[1][c] && jogo[1][c] == jogo[2][c])
			cont++;
	}
	return cont;
}

//fun��o para verificar vit�ria por diagonal principal
int ganhouDiagPrincipal(char X) {
	int cont = 0;
	if (jogo[0][0] == X && jogo[0][0] == jogo[1][1] && jogo[1][1] == jogo[2][2])
		cont++;
	return cont;
}

//fun��o para verificar vit�ria por diagonal secund�ria
int ganhouDiagSecund(char X) {
	int cont = 0;
	if (jogo[0][2] == X && jogo[0][2] == jogo[1][1] && jogo[1][1] == jogo[2][0])
		cont++;
	return cont;
}

//fun��o para verificar se a posi��o escolhida � v�lida
int posValida() {
	if (pos > 0 && pos < 10 && jogo[(pos - 1)/3][(pos - 1) % 3] == ' ') //(pos - 1)/3 e (pos - 1) % 3 � o c�lculo para definir a posi��o da matriz a partir de um �nico n�mero
		return 1;
	else
		return 0;
}

//procedimento para ler as coordenadas do jogador
void lerCoordenadas(char X) {
	setlocale(0, "Portuguese");
	printf("\nDigite a posi��o que quer jogar: ");
	scanf("%d", &pos);
	fflush(stdin);
	while (posValida() != 1) {
		printf("\nPosi��o inv�lida ou j� preenchida. Escolha outra posi��o: ");
		scanf("%d", &pos);
		fflush(stdin);
	}
	jogo[(pos - 1)/3][(pos - 1) % 3] = X;
}

//fun��o para retornar se o jogo deu velha ou n�o
int quantVazias() {
	int quantidade = 0;
	
	for (l = 0; l < 3; l++) {
		for(c = 0; c < 3; c++) {
			if (jogo[l][c] == ' '){
				quantidade++;
			}
		}
	}
	return quantidade;
}

//procedimento jogar com o loop principal do jogo
void jogar() {
	setlocale(0, "Portuguese");
	int jogador = 1, vitoriaX = 0, vitoriaO = 0;
	
	do {
		system("cls");
		imprimirPosicoes();
		imprimirJogo();
		
		if (jogador == 1){
			lerCoordenadas('X');
			if(ganhouPorLinhas('X') != 0 || ganhouPorColunas('X') != 0 || ganhouDiagPrincipal('X') != 0 || ganhouDiagSecund('X') != 0)
				vitoriaX = 1;
			jogador = 0;
		}
		else{
			lerCoordenadas('O');
			
			if(ganhouPorLinhas('O') != 0 || ganhouPorColunas('O') != 0 || ganhouDiagPrincipal('O') != 0 || ganhouDiagSecund('O') != 0)
				vitoriaO = 1;
				
			jogador = 1;
		}
	} while (vitoriaX == 0 && vitoriaO == 0 && quantVazias() > 0);
		
	system("cls");
	imprimirPosicoes();
	imprimirJogo();
	
	if (vitoriaX == 1)
		printf("\n\nVit�ria do jogador de X, parab�ns!\n");
	else if (vitoriaO == 1)
		printf("\n\nVit�ria do jogador de O, parab�ns!\n");
	else
		printf("\n\nO jogo deu velha...\n");
}

int main(){
	setlocale(0, "Portuguese");
	
	int opcao;
	
	do {
		inicializarMatriz();
	
		jogar();
		
		printf("\n\nDigite 1 para jogar novamente, 0 para finalizar o jogo: ");
		scanf("%d", &opcao);
	} while (opcao == 1);
	
	return 0;
}
