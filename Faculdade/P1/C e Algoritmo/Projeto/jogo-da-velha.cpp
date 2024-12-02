#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// estrutura usuario.
typedef struct {
	char nome[21]; 
	int vitoria, empate, derrota, pontos; 
} t_Usuario;

// variaveis globais
char **jogo; // matriz[3][3]

int i, j; 

// arquivo do ranking
#define fileRanking "ranking.txt" 

/* Prototipo das fun��es e procedimentos */

void menu(); // Menu principal.
void selecionarOpcaoMenu(); // Selecionar a opcao que o usu�rio digitou no menu

void tutorial(); // tutorial.

void inicializarJogo(); // Inicializar o jogo com ' '
void imprimirPosicoes(); // Imprimir as posi��es do quadrado.
void imprimir(); // Imprimir o jogo na tela.

void lerCoord(char j); // ler a posi��o que o usu digitou
int validarCoord(int pos); // validar a posi��o

void tutorialGanhar(); // tutorial de como ganhar ou empate

void jogar(); // gameplay oficial.
int jogarNovamente(char *usuario1, char *usuario2); // verificar se os jogadores querem jogar de novo
int quantVazias(); // fun��o para verificar a quantidade de casas vazias.

void tempoDeJogo(time_t end, time_t start); // procedimento para calcular e mostrar o tempo de jogo
// /*
// fun��es para verificar se o usu ganhou
int verificarVitoria(char jogador); // verificar se o usuario ganhou

int ganhouPorLinhas(char c); // verificar se o usu ganhou por linha
int ganhouPorLinha(int l, char c); // verificar se o mesmo caractere est� em cada linha

int ganhouPorColunas(char c); // verificar se o usu ganhou por coluna
int ganhouPorColuna(int j, char c); // verificar se o mesmo caractere est� em cada coluna

int ganhouPorDiagPrinc(char c); // verificar se o usu ganhou por diagonalPrincipal
int ganhouPorDiagSecun(char c); // verificar se o usu ganho upor diagonal Secundaria
// */

// /* 
// parte do arquivo
void lerRanking(t_Usuario *user, int *qtdJogadores); // ler o ranking
void pedirDados(char *usuario1, char *usuario2); // pedir os dados do usuario.

void ordernarRanking(t_Usuario *userRanking, int qtdJogadores); // ordernar o ranking.

void atualizarJogador(t_Usuario *user, int *qtdJogadores, char *nome, int resultado); // atualizar os dados do jogador de acordo com o resultado.

int encontrarJogador(t_Usuario *user, int qtdJogadores, char *nome); // fun��o para encontrar jogador

void salvarRanking(t_Usuario *user, int qtdJogadores); // salvar o ranking.
// */

void imprimirRanking(int *indexStart, int *tamRank); // imprimir o Ranking 

// Caso usu queira aumentar o intervalo de impressao do ranking
void aumentarRank(int *index, int *quantidade, int *qtdJogadores); 

void imprimirCreditos(); // imprimir os cr�ditos

void sair(); // exit.
 
int main() {
		
	// Definindo a lingua
	setlocale(0, "Portuguese");
	
	// alocando a mem�ria para o ponteiro (linha)
	jogo = (char**)malloc( 3 * sizeof(char*));
	
	// alocando a memoria para as colunas.
	for ( i = 0 ; i < 3 ; i ++)
		*(jogo + i) = (char*)malloc(3 * sizeof(char));
			
	// chamando o menu para o jogador definir o seu caminho.
	menu();
		
	
	// Liberando a mem�ria
	for ( i = 0 ; i < 3 ; i ++) {
		free(*(jogo + i));
		*(jogo + i) = NULL;
	}
		
	free(jogo);
	jogo = NULL;
	return 0;
} 

// procedimento para mostrar o menu e fazer com que o usu�rio escolha

/* 
		MENU:
			TUTORIAL
			JOGAR
			RANKING
			CR�DITOS
			SAIR
*/

// Menu principal.
void menu() {

	printf("\n ----------- [ M E N U ] ----------\n");
	printf("|\t\t\t\t   |\n");
	printf("|  [1] -> Tutorial\t\t   |\n|  [2] -> Jogar\t\t\t   |\n|  [3] -> Mostrar o ranking\t   |\n|  [4] -> Cr�ditos\t\t   |\n|  [5] -> Sair\t\t\t   |");
	printf("\n|\t\t\t\t   |");
	printf("\n ----------------------------------\n");
	selecionarOpcaoMenu();
}

void selecionarOpcaoMenu() {
	int opcao;
	char arquivo[] = {"ranking/ranking.txt"};
	
	printf("\nEscolha: ");
	scanf("%d", &opcao);
	
	// Valida��o da resposta do usu�rio
	fflush(stdin); 
	while(opcao < 1 || opcao > 5) {
		system("cls");
		printf("\n\t[ERROR] -> Valor inv�lido!\n");
		printf("\n------------ [ M E N U ] -----------\n");
		printf("|\t\t\t\t   |\n");
		printf("|  [1] -> Tutorial\t\t   |\n|  [2] -> Jogar\t\t\t   |\n|  [3] -> Mostrar o ranking\t   |\n|  [4] -> Cr�ditos\t\t   |\n|  [5] -> Sair\t\t\t   |");
		printf("\n|\t\t\t\t   |");
		printf("\n------------------------------------\n");
		printf("\nEscolha: ");
		scanf("%d", &opcao);
		fflush(stdin);
	}
	
	// tamanho de usuarios que ser� impresso no ranking inicial 10. e o index = 0;
	int tamRank = 10;
	int indexStart = 0;
	switch(opcao) {
		
		case 1 : // chamar o tutorial
			tutorial(); 
			break;
		
		case 2 : // come�ar o jogo.
			jogar();
			break;
		
		case 3 : 
			imprimirRanking(&indexStart, &tamRank); // passando o endere�o de mem�ria, visto que vou alterar o resultado.
			// e mostrar o rank
			menu();
			break;
			
		case 4 : // Chamar os cr�ditos
			imprimirCreditos(); 
			break;
			
		case 5 : 
			sair(); // chamar a saida
			break;
			
		default : // Isso aqui pode ser tirado, visto que possue a valida��o.
			system("cls");
			printf("\n\t[ERROR] -> Valor inv�lido!");
			break;
	}
}

// opcao 1 -> Tutorial

// procedimento para chamar o tutorial
void tutorial() {
	// definir as letras do jogador.
	char jogador1 = 'X', jogador2 = 'O';
	int jogador = 1, cont;
	
	inicializarJogo();	
	
	
	// fazer um loop para imprimir 2 vezes, mostrando como se digita a coordenada e como sair� na tela.
	for(cont = 0; cont < 2; cont ++) {
		
		system("cls");
		// menu do tutorial
		printf("\n\t[TUTORIAL]\n");
		printf("\nREGRAS:\n");
		printf("[1.] -> O primeiro jogador come�a com a letra 'X'.\n[2.] -> O segundo jogador joga com a letra 'O'.\n[3.] -> Caso coloque um quadrado que j� est� preenchida, ir� dar [ERRO]. ");
		printf("\n-------------------------------------------------\n");
		imprimirPosicoes();
		
		imprimir();
		if(jogador == 1) {
			printf("\n\nJogador 1 = 'X'.");
			lerCoord(jogador1);
			jogador++;
		} 
		else {
			printf("\nJogador 2 = 'O'");
			lerCoord(jogador2);
			jogador = 1;
			imprimir();
		}
		
	}
	
	// perguntar caso o usuario queria continuar o tutorial ou come�ar a jogar.
	int opcao;
	printf("\n----------------------------------------------");
	printf("\n\n[1] -> Continuar Tutorial -> (Como ganhar ou empatar?).\n[2] -> Come�ar a jogar.\n[3] -> Voltar ao menu.");
	printf("\n\nINFORME: ");
	scanf("%d", &opcao);
	
	// valida��o da resposta.
	fflush(stdin);
	while(opcao < 1 || opcao > 3) {
		system("cls");
		printf("\n[ERROR] -> Valor inv�lido!\n");
		printf("\n----------------------------------------------");
		printf("\n\n[1] -> Continuar Tutorial -> (Como ganhar ou empatar?).\n[2] -> Come�ar a jogar.\n[3] -> Voltar ao menu.");
		printf("\n\nINFORME: ");
		scanf("%d", &opcao);
		fflush(stdin);
	}
	system("cls");
	
	// definir a continua��o do usu�rio de acordo com a sua resposta.
	
	switch(opcao) {
		
		case 1:	tutorialGanhar(); break;
		
		case 2: jogar(); break;
		
		case 3: menu(); break;
		
		default: 
			printf("\n\t[ERROR] -> Valor inv�lido!\n");
			printf("\n----------------------------------------------");
			break;		
	}	
}

// Procedimento para inicializar o jogo com caracteres vazios.
void inicializarJogo() {
	
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++)
			*(*(jogo + i) + j) = ' ';
	}	
}

// procedimento para imprimir posi��es na tela
// INTERFACE DOS QUADRADOS
void imprimirPosicoes() {
	setlocale(0, "Portuguese");
	int cont = 0;
	printf("\n  POSI��ES DE CADA QUADRADO\n");
	printf("------------------------------------\n\n");
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 2; j++) {
			if (j == 0)
				printf("\t");
			printf(" %d ||", ++cont);
			
		}
		printf(" %d\n", ++cont);
		
		if (i < 2)
		printf("\t=============\n");
	}
	printf("\n------------------------------------\n\n");
}

// procedimento para imprimir o jogo na tela
// INTERFACE PRINCIPAL
void imprimir() {
	printf("\n\tJOGO DA VELHA\n\n\n");
	for(i = 0; i < 3; i++){
		for(j = 0; j < 2; j++) {
			if(j == 0) {
				printf("        ");
			}
			printf(" %c ||",jogo[i][j]);
		}
		printf(" %c\n",jogo[i][j]);
		if(i < 2)
			printf("\t=============\n");
	}
}

// procedimento para ler a posicao que o usuario digitou 
void lerCoord(char j) {
	int posicao;
	
	printf("\nDigite a posi��o que quer jogar: ");
	scanf("%d", &posicao);
	
	// validar a posi��o que o usuario digitou.
	fflush(stdin);
	while(!validarCoord(posicao)) {
		printf("Coordenadas invalidas! Digite a posi��o que quer jogar: ");
		scanf("%d", &posicao);
		fflush(stdin);
	}

	/* 
		Calcular a posi��o da matriz de acordo com o numero digitado pelo usuario;
		
		Ex: Usuario digitou [2]:
		jogo[0][1] = [2]
		
		jogo[(posicao - 1)/3][(posicao - 1) % 3]
		
		jogo[(2 - 1)/3[(2 - 1) % 3] = j (X ou O).
		jogo[1/3][1 % 3] = j (X ou O)
			
		/ -> retorna o quociente.
		% -> retorna o resto.
		1 colchete -> 1/3 = 0;
		2 colchete -> Resto = Dividendo - (Quociente x Divisor) -> R = 1 - (0 x 3) -> R = 1
		jogo[0][1] -> linha 0, coluna 1.
	*/
	jogo[(posicao - 1)/3][(posicao - 1) % 3] = j;
}

/*
	Funcao para validar a posicao digitada
	1 - � valida
	0 - n�o � valida
*/

int validarCoord(int pos) {
	// est� de acordo com a posi��o dos quadrados 1 a 9 && o quadradao est� vazio ' '? S -> retorna 1(V), N -> retorna 0(F).
	if(pos > 0 && pos < 10 && jogo[(pos - 1)/3][(pos - 1) % 3] == ' ')
		return 1;
	else
		return 0;
}

// procedimento que mostra como ganhar em cada situa��o ou empate.
void tutorialGanhar() {
	int opcao, resp;
	
	system("cls");
	
	// menu para o usuario escolher
	printf("\n\t[TUTORIAL]\n");
	printf("\nComo ganhar ou empatar? -> Existem 3 formas de ganhar uma partida:\n");
	printf("[1.] -> Completar a linha com o mesmo caractere.\n[2.] -> Completar a coluna com o mesmo caractere.\n[3.] -> Completar a diagonal com o mesmo caractere.\n[4.] -> Se todas as casas estiverem preenchidas e nenhum dos jogadores ganharem � *empate*.");
	printf("\n--------------------------------------------------------------------------------------------\n");
	printf("\n\nVeja na pr�tica:\nDigite um n�mero [1, 2, 3, 4]: ");
	scanf("%d", &opcao);
	
	fflush(stdin); // evitar caractere na resposta 
	inicializarJogo(); // inicializar jogo, para resetar os valores
	switch(opcao) {
	
	case 1 : // vitoria por linha.
		*(*(jogo + 0) + 0) = *(*(jogo + 1) + 0) = *(*(jogo + 2) + 0) = 'X';
		imprimir();
		printf("\nJogador 1 (*X*) � o vencedor.\n\n");
		break;
	
	case 2 : // vitoria por coluna
		*(*(jogo + 0) + 0) = *(*(jogo + 0) + 1) = *(*(jogo + 0) + 2) = 'O';
		imprimir();
		printf("\nJogador 2 (*O*) � o vencedor.\n\n");
		break;
	
	case 3 :  // vitoria por diagonal
		*(*(jogo + 0) + 0) = *(*(jogo + 1) + 1) = *(*(jogo + 2) + 2) = 'X';
		imprimir();
		printf("\nJogador 1 (*X*) � o vencedor.\n\n");
		break;
		
	case 4 : // empate
		*(*(jogo + 0) + 0) = *(*(jogo + 0) + 1) = *(*(jogo + 1) + 1) = *(*(jogo + 1) + 2) = *(*(jogo + 2) + 0) = 'X';
		*(*(jogo + 0) + 2) = *(*(jogo + 1) + 0) = *(*(jogo + 2) + 1) = *(*(jogo + 2) + 2) = 'O';
		imprimir();
		printf("\nQue pena foi empate.\n\n");
		break;
		
	default : // caso o usu�rio digite um valor inv�lido
		printf("\n\t[ERROR] -> Valor inv�lido!\n");
		break;
	}
	
	// chamar um menu para verificar se o usu�rio quer ver as outras op��es ou jogar.
	printf("\n-------------------------------------------------\n");
	printf("\n[1] -> Jogar.\n[2] -> Para ver na pr�tica as outras op��es.");
	printf("\n\nINFORME: ");
	scanf("%d", &resp);
	
	// valida��o da resposta.
	fflush(stdin);
	while(resp < 1 || resp > 2) {
		system("cls");
		printf("\n\t[ERROR] -> Valor Inv�lido!\n");
		printf("\n-------------------------------------------------\n");
		printf("\n[1] -> Jogar.\n[2] -> Para ver na pr�tica as outras op��es.");
		printf("\n\nINFORME: ");
		scanf("%d", &resp);
		fflush(stdin);
	}
	
	system("cls");
	// definir o caminho do usu�rio, caso 2 -> chamar esse procedimento novamente, caso 1 -> jogar.
	resp == 2 ? tutorialGanhar() : jogar();	
}

// procedimento jogar com o loop principal do jogo
void jogar() {
	system("cls");
		
	int jogador = 1, vitoriaX, vitoriaO;
	int qtdJogadores  = 0;
	char jogador1 = 'X', jogador2 = 'O'; 
	char nomeUser1[20], nomeUser2[20];
	
	time_t inicio, fim; //vari�veis do tipo time_t para calcular o tempo de jogo
	
	// criando jogador
	t_Usuario  *user;
	
	//	printf("TAMANHO: %d", sizeof(user)); 36 bytes.	
	
	// alocando dinamicamente. // 50 * 36 bytes = 1800 bytes.
	user = (t_Usuario*)malloc(50 * sizeof(t_Usuario)); 
	
	
	// ler o Ranking do arquivo.	
	lerRanking(user, &qtdJogadores);
		
	// pedir os dados dos 2 usuarios.
	pedirDados(nomeUser1, nomeUser2);
	
	do{ // loop principal do jogo
		vitoriaX = vitoriaO = 0; // iniciar as flags de vit�ria para X e para O com 0 toda vez no in�cio do loop
		int opcao;
		inicializarJogo(); // procedimento para atribuir os valores vazios para a matriz.
		system("cls");
		// loop at� alguem ganhar ou empatar.
		/*
			jogador1 = 'X' ; jogador2 = 'O'.
			imprimir() -> Procedimento para imprimir o jogo.
			verificarVitoria(tem como parametro a letra de acordo com o jogador) -> fun��o para verificar se alguem ganhou
		*/
		inicio = time(NULL); // recebendo hora inicial do jogo
		do {
			imprimirPosicoes();
			imprimir();
			if(jogador == 1){ 
				printf("\nJogador %s = (*%c*)", nomeUser1, jogador1);
				lerCoord(jogador1); 
				jogador = 2; // acresentar para o proximo jogador seja o 2
				vitoriaX += verificarVitoria(jogador1);
			}
			else {
				printf("\nJogador %s = (*%c*)", nomeUser2, jogador2);
				lerCoord(jogador2);
				jogador = 1; // retornar o valor para que o proximo jogador seja o 1
				vitoriaO += verificarVitoria(jogador2);
			}
			system("cls");
		} while(vitoriaX == 0 && vitoriaO == 0 && quantVazias() > 0);
		imprimir();
		
		// Imprimir de acordo com o resultado.
		if(vitoriaX == 1) {
			printf("\n\nParab�ns Jogador (*%s*). Voc� ganhou!!!\n", nomeUser1);
			atualizarJogador(user, &qtdJogadores, nomeUser1, 1);
			atualizarJogador(user, &qtdJogadores, nomeUser2, -1);
			jogador = 1; // se o jogador 1 ganha, ele come�a dnv na pr�xima partida
		}
		else if(vitoriaO == 1) {
			printf("\n\nParab�ns Jogador (*%s*). Voc� ganhou!!!\n", nomeUser2);
			atualizarJogador(user, &qtdJogadores, nomeUser2, 1);
			atualizarJogador(user, &qtdJogadores, nomeUser1, -1);
			jogador = 2; // se o jogador 2 ganha, ele come�a dnv na pr�xima partida
		} 
		else {
			printf("\nQue pena! Foi empate.!!!\n");
			atualizarJogador(user, &qtdJogadores, nomeUser2, 0);
			atualizarJogador(user, &qtdJogadores, nomeUser1, 0);
		}
		fim = time(NULL); // recebendo hora final do jogo
		tempoDeJogo(fim, inicio); // chamando procedimento de calcular o tempo de jogo
		salvarRanking(user, qtdJogadores);	// salvar os dados.
	}while(jogarNovamente(nomeUser1, nomeUser2)); // verificar se os jogadores querem jogar novamente
	
	// liberando mem�ria	
	free(user);
	user = NULL;
	system("cls");
	menu(); // chamar o menu, novamente.
	
}

// fun��o que pergunta se os jogadores querem jogar novamente ---> Retorna 1 para sim e 0 para n�o
int jogarNovamente(char *usuario1, char *usuario2){
	
	int opc;
	printf("\nEscolha novamente.\n\n[1.] -> Jogar Novamente\n[2.] -> Jogar com usu�rios diferentes\n[3.] -> Voltar ao Menu\n\nINFORME: ");
	scanf("%d", &opc);
	
	// validar a resposta.
	fflush(stdin);
	while(opc < 1 || opc > 3){
		system("cls");
		printf("\n\n[ERROR] -> Valor inv�lido!\n"); 
		printf("\n-------------------------------------------------\n");
		printf("\nEscolha novamente.\n\n[1.] -> Jogar Novamente\n[2.] -> Jogar com usu�rios diferentes\n[3.] -> Voltar ao Menu\n\nINFORME: ");
		scanf("%d", &opc);
		fflush(stdin);
	}
	
	switch(opc){
		case 1:
			return 1; // s� retornar
			break;
			
		case 2 : 
		// caso ele queira jogadores diferentes, s� alterar o nome.
		// quando ele for jogar com nomes diferentes 
		// pedir para alterar os dados. e retornar
			pedirDados(usuario1, usuario2); 
			return 1;
			break;
		case 3: // caso queira acessar o menu.
			return 0;
			break;
	}
}

// procedimento para calcular e mostrar o tempo de jogo
void tempoDeJogo(time_t end, time_t start){
	double tempoTotal = difftime(end, start);
	int minutos, segundos;
	
	// poderia colocar de hora, mas bem improv�vel que o usu vAI JOGAR 1 HORA DE JOGO DA VELHA EM UMA PARTIDA.
	minutos = (int)tempoTotal / 60;
	segundos = (int)tempoTotal % 60;
	
	printf("\nTempo de jogo: %d minutos e %d segundos\n", minutos, segundos);
}

// fun��o que retorna a quantidade de posi��es vazias
// visto que, caso n�o tenha mais posi��es vazias, e ninguem ganhou -> ser� empate.

int quantVazias() {
	
	int quantidade = 0;
	
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++) {
			if(*(*(jogo + i) + j) == ' ')
				quantidade++;
		}
	}
	
	return quantidade;
}

/*
	funcao que verifica quem ganhou, seja linha, seja coluna, seja diagonal
		0 -> N�o ganhou
		1 -> Ganhou
*/


int verificarVitoria(char jogador) {
	return ganhouPorLinhas(jogador) || ganhouPorColunas(jogador) || 
           ganhouPorDiagPrinc(jogador) || ganhouPorDiagSecun(jogador);
}

/*
	Funcao para retornar a variavel ganhou e fazer a soma no loop do jogar()
		1 - ganhou
		0 - nao ganhou ainda
*/

int ganhouPorLinhas(char c) {
	
	int ganhou = 0;
	// loop para verificar se cada posi��o da linha est� preenchida com o mesmo caractere.
	for(i = 0; i < 3; i++){
		ganhou += ganhouPorLinha(i, c);
	}
	
	return ganhou;
		
}

/*
	Funcao para verificar vit�ria por linha
		1 - ganhou
		0 - nao ganhou ainda
*/

int ganhouPorLinha(int l, char c) {
	if(jogo[l][0] == c && jogo[l][1] == c && jogo[l][2] == c)
		return 1;
	else
		return 0;
}


/*
	Mesma situa��o da fun��o ganhouPorLinhas
	1 - ganhou
	0 - nao ganhou ainda
*/

int ganhouPorColunas(char c) {
	
	int ganhou = 0;
	for(j = 0; j < 3; j++){
		ganhou += ganhouPorColuna(j, c);
	}
	
	return ganhou;
		
}
/*
	Funcao para verificar vit�ria por coluna
		1 - ganhou
		0 - nao ganhou ainda
*/

int ganhouPorColuna(int j, char c) {
	if(jogo[0][j] == c && jogo[1][j] == c && jogo[2][j] == c)
		return 1;
	else
		return 0;
}

/*
	Funcao para verificar vit�ria por Diagonal principal
		1 - ganhou
		0 - nao ganhou ainda
*/

int ganhouPorDiagPrinc(char c) {
	if(jogo[0][0] == c && jogo[1][1] == c && jogo[2][2] == c)
		return 1;
	else
		return 0;
}

/*
	Funcao para verificar vit�ria por Diangonal secundaria
		1 - ganhou
		0 - nao ganhou ainda
*/

int ganhouPorDiagSecun(char c) {
	if(jogo[0][2] == c && jogo[1][1] == c && jogo[2][0] == c)
		return 1;
	else
		return 0;
		
}

// procedimento para ler o Ranking.
void lerRanking(t_Usuario *user, int *qtdJogadores) {
	
	// vai abrir o arquivo e ler -> r -> Leitura.
	FILE *arquivo = fopen(fileRanking, "r");
	
	// caso n�o exista o arquivo, obviamente qtdJogadores � 0 e vai retornar..
	if(!arquivo) {
		*qtdJogadores = 0;
		return;
	}
	
	*qtdJogadores = 0;
	
	/* 
		printf("%d", fscanf(arquivo, "%s %d %d %d %d" , 
				user[*qtdJogadores].nome, 1
				&user[*qtdJogadores].vitoria, 2
				&user[*qtdJogadores].empate, 3
				&user[*qtdJogadores].derrota, 4 
				&user[*qtdJogadores].pontos) 5
				
				EOF -> End Of File (Final do Arquivo) -> -1.
	
		// colocando em um loop 
			-> caso exista esses dados -> retornar� a quantidade de informa��es lidas, no caso 5
			-> caso n�o exista retornar� -1 (EOF) -> End Of File.
	*/
		
	// escanear as variaveis do struct t_Usuario, e fazer a contagem de quantos jogadores tem.
	while(fscanf(arquivo, "%20[^*]* %d %d %d %d\n" , 
				user[*qtdJogadores].nome,
				&user[*qtdJogadores].vitoria,
				&user[*qtdJogadores].empate,
				&user[*qtdJogadores].derrota,
				&user[*qtdJogadores].pontos) != EOF) 
					(*qtdJogadores)++;		
			
	
	// procedimento para organizar o ranking dos jogadores.			
	ordernarRanking(user, *qtdJogadores);	
	
	// fechar o arquivo para evitar que corrompa.
	fclose(arquivo);
}

// Procedimento para pedir os dados do usuario.
void pedirDados(char *usuario1, char *usuario2) {
	
	
	printf("Apelido do jogador 1 (limite de 20 caracteres): ");
	scanf("%20[^\n]", usuario1); 
	while(getchar() != '\n'); // Evitar que caso o usuario digite +de 20 caracteres passe para usu2.
	int tamUser1 = strlen(usuario1);
	
	if(tamUser1 > 20)
		usuario1[21] = '\0';
	
	printf("Apelido do jogador 2 (limite de 20 caracteres): ");
	scanf("%20[^\n]", usuario2);
	while(getchar() != '\n'); // Evitar que caso o usuario digite +de 20 evite um erro.
	int tamUser2 = strlen(usuario2);
	
	if(tamUser2 > 20)
		usuario2[21] = '\0';
	
	
}

// procedimento para organizar o ranking dos jogadores.
void ordernarRanking(t_Usuario *userRanking, int qtdJogadores) {
	int troca;
	
	// estrutura aux para fazer a troca.
	t_Usuario aux;
		
	do {
		troca = 0;
		
		// loop para fazer a troca de posi��es
		for(i = 0; i < qtdJogadores - 1; i++) { 
			// Trocar posi��o de acordo com a pontua��o
			
			// se a pontua��o do elemento na posi��o [0] for maior que a pontua��o do elemento na posi��o 0 + 1 -> faz a troca.
			if(userRanking[i].pontos < userRanking[i + 1].pontos) {
				aux = userRanking[i];
				userRanking[i] = userRanking[i + 1];
				userRanking[i + 1] = aux;
				
				troca = 1;
			}
			// Caso a pontua��o esteja igual
			// Crit�rio de desempate � o n�mero de Derrotas.
			if(userRanking[i].pontos == userRanking[i + 1].pontos) { 
				if(userRanking[i].derrota > userRanking[i + 1].derrota) {
					aux = userRanking[i];
					userRanking[i] = userRanking[i + 1];
					userRanking[i + 1] = aux;
				
					troca = 1;
				}
			}
		}
		// caso haja a troca, troca ser� = 1.	
	} while (troca); 
	
}

// procedimento para autalizar as pontua��es, vitorias, derrotas e empates.
void atualizarJogador(t_Usuario *user, int *qtdJogadores, char *nome, int resultado) {
	
	// atribuir uma variavel o valor do return, caso tenha o usuario.
	int indice = encontrarJogador(user, *qtdJogadores, nome);
	
	// -1 -> N�o existe.
	if(indice == -1) {
		// fazer a copia para a estrutura de dados.
		// strcpy(1 parametro: onde quer salvar, 2 parametro: referencia).
		strcpy(user[*qtdJogadores].nome, nome);
		
		// obviamente, se n�o existe, n tem ponto, vitoria, etc.
		user[*qtdJogadores].vitoria = user[*qtdJogadores].empate = 0;
		user[*qtdJogadores].derrota  = user[*qtdJogadores].pontos= 0;
		
		// 1. pega o valor que o ponteiro aponta -> *qtdJogadores
		// dps acrescenta +1 para o pr�ximo n�mero
		indice = (*qtdJogadores)++; // acrescenta +1 jogador na estrutura. 
	}
	
	/*
		De acordo com o resultado  -1 derrota, 1 vitoria, 0 empate 
		acrescenta +1 em V,E,D
		
		E caso o usu ganhe +2 pontos
		Caso seja empate +1 pontos para cada usu.
	*/	
	int pontoVitoria = 2, pontoEmpate = 1;
	
	switch(resultado) {
		
		case -1 :
			user[indice].derrota++;
			break;
		
		case 0 :
			user[indice].empate++;
			user[indice].pontos += pontoEmpate;
			break;
		
		case 1 :
			user[indice].vitoria++;
			user[indice].pontos += pontoVitoria; 
			break;	
	}
	
}

// funcao para encontrar a posi��o do jogador.
int encontrarJogador(t_Usuario *user, int qtdJogadores, char *nome) {	
	for(i = 0; i < qtdJogadores; i++) {
		if(stricmp(user[i].nome, nome) == 0) 
			return i; 
	}
	
	return -1;
}

void salvarRanking(t_Usuario *user, int qtdJogadores) {
	FILE *file = fopen(fileRanking, "w");
		
	if(file) { 
		for(i = 0; i < qtdJogadores; i++) {
			fprintf(file, "%s* %d %d %d %d\n", 
						user[i].nome,
						user[i].vitoria,
						user[i].empate,
						user[i].derrota,
						user[i].pontos
			);
		}
		
		fclose(file);
	}	
	else {
		printf("\n\t[ERROR] -> Erro ao salvar o arquivo!\n");
		return;
	}
	
}

void imprimirRanking(int *pIndexStart, int *pTamRank) {
	
	system("cls");
	t_Usuario *ranking;
	int qtdJogadores = 0;
	
	ranking = (t_Usuario*)malloc(50 * sizeof(t_Usuario));
	
	lerRanking(ranking, &qtdJogadores);
	
	if(qtdJogadores == 0) {
		printf("\nOps... :(\nNo momento n�o h� ningu�m no ranking:\n");
		return menu();
	}	
	
	printf("\n\n ------------[R A N K I N G]------------------------\n");
	printf("|\t\t\t\t\t\t   |\n");
	for(i = *pIndexStart; i < *pTamRank; i++) {
		printf("| [%2d.] -> %-20s %2dV %2dE %2dD %3dPts |\n", // - dps do % indica que ser� alinhado � esquerda.
						i + 1,
						ranking[i].nome,
						ranking[i].vitoria,
						ranking[i].empate,
						ranking[i].derrota,
						ranking[i].pontos
		);
		
		// se i == qtdJogadores Limite, vai quebrar o loop para n imprimir rankings vazios.
		if(i == qtdJogadores - 1) break;
	}
	printf("|\t\t\t\t\t\t   |\n");
	printf(" ---------------------------------------------------\n");
	 
	// verificar oq o usu quer fazer.
	int opcao;
		
		if(qtdJogadores > 10) {
			printf("\n[1.] -> Voltar ao menu\n[2.] -> Ver outras posi��es do ranking.\n");
			printf("INFORME: ");
			scanf("%d", &opcao);
			
			// validar a resposta.
			fflush(stdin);
			while(opcao < 1 || opcao > 2) {
				system("cls");
				imprimirRanking(pIndexStart, pTamRank);
				printf("\n\n\t[ERROR] -> Valor Inv�lido!\n");
				printf("------------------------------------------\n");
				printf("\n[1.] -> Voltar ao menu.\n[2.] -> Ver outras posi��es do ranking.\n");
				printf("INFORME: ");
				scanf("%d", &opcao);
				fflush(stdin);
			}
		
		
		// se ele escolher opcao 2 -> deseja aumentar o rank
		if(opcao == 2) {
			// passar os ponteiros para alterar os resultados e a quantidade de jogadores.
			aumentarRank(pIndexStart, pTamRank, &qtdJogadores); 
			
			// imprimir com os resultados que o usu escolheu.
			imprimirRanking(pIndexStart, pTamRank);
		} 
		else
			system("cls");
	}
	else{
		printf("Pressione ENTER para voltar ao menu...");
		while(getchar() != '\n');		
	}
	
	system("cls");
	
	free(ranking);
	ranking = NULL;
}

// procedimento para definir o intervalo da impressao ranking
void aumentarRank(int *index, int *quantidade, int *qtdJogadores) {
	int opcao;
	
	/* 
		qtdJogadores � menor ou igual que 20 ? 
		Se sim, imprimir apenas duas op��es, visto que n faz sentido imprimir 
		o rank intervalo do rank 21 -30.
		
		Se nao, imprimir o menu normal.
	*/
	*qtdJogadores <= 20 
		? printf("\n[1.] -> Ver o ranking do 0 - 10\n[2.] -> Ver o ranking do 11 - 20\n")
		: printf("\n[1.] -> Ver o ranking do 0 - 10\n[2.] -> Ver o ranking do 11 - 20\n[3.] -> Ver o ranking do 21 - 30\n");
	printf("SELECIONE: ");
	scanf("%d", &opcao);
	
	// validar a repsosta.
	fflush(stdin);
	while(opcao < 1 || opcao > 3) {
		system("cls");
		imprimirRanking(index, quantidade);
		printf("\n\n\t[ERROR] -> Valor inv�lido! ");
		printf("------------------------------------------\n");
		*qtdJogadores <= 20 
			? printf("\n[1.] -> Ver o ranking do 0 - 10\n[2.] -> Ver o ranking do 11 - 20\n")
			: printf("\n[1.] -> Ver o ranking do 0 - 10\n[2.] -> Ver o ranking do 11 - 20\n[3.] -> Ver o ranking do 21 - 30\n");
		printf("SELECIONE: ");
		scanf("%d", &opcao);
		fflush(stdin);
	}
	
	// de acordo com a opcao do usu definir o resultado.
	switch(opcao) {
		
		// como ele quer ver o de 0 - 10
		// Atribuir indice 0 e quantidade 10.
		// Precisa atribuir para resetar.
		case 1 : 
			*index = 0;
			*quantidade = 10; 
			break;
		
		// Autalizar o indice(10) e a quantidade(20) para o loop
		case 2 : 
			*index = 10;
			*quantidade = 20; 
			break;
		
		// Autalizar o indice(20) e a quantidade(30) para o loop
		case 3 : 
			*index = 20;
			*quantidade = 30; 
			break;
		
		default: 
			system("cls");
			printf("\n\n\t[ERROR] -> Valor Inv�lido!");
			break;
	}

}

// procedimento para imprimir os cr�dtios
/*
	 PROJETO -> Oq Desenvolvemos, professor;
	 EQUIPE -> Desenvolvedores
	 Refer�ncia -> Arquivos/Estudos/Videos que pesquisamos
*/
void imprimirCreditos() {
	system("cls");
	printf("\n\t ------------[P R O J E T O]--------------\n");
	printf("\t|\t\t\t\t\t  |\n");
	printf("\t|  Desenvolvimento do jogo da velha 3x3   |\n");
	printf("\t| para a cadeira T�cnicas e Desenvolvi -  |\n");
	printf("\t| mento de Algoritmo (TDA) da UNIP�.\t  |\n");
	printf("\t|\t\t\t\t\t  |\n");
	printf("\t| *Discente:* Walace Sartori Bonfim\t  |\n");
	printf("\t|\t\t\t\t\t  |");
	printf("\n\t -----------------------------------------\n");
	
		
	printf("\n\t -------------[E Q U I P E]---------------\n");
	printf("\t|\t\t\t\t\t  |\n");
	printf("\t| [1.] -> Antonio Felix de Oliveira Neto  |\n\t| [2.] -> Dante Alves e Silva\t\t  |\n\t| [3.] -> Guilherme de Medeiros Serpa\t  |\n\t| [4.] -> Iloir Martins de Souza Neto\t  |\n\t| [5.] -> Jo�o Nic�foro Cantalice Neto\t  |\n");
	printf("\t|\t\t\t\t\t  |\n\t -----------------------------------------\n");
	
	printf("\n\t --------[R E F E R � N C I A S]----------\n");
	printf("\t|\t\t\t\t\t  |\n");
	printf("\t| [1.] Canal: *Progame seu Futuro*\t  |\n\t| [2.] Slides da *cadeira TDA*\t\t  |\n");
	printf("\t|\t\t\t\t\t  |");
	printf("\n\t -----------------------------------------\n");
	
	printf("Pressione ENTER para voltar ao menu...");
	while(getchar() != '\n');
	system("cls");
	menu();
	
}

// procedimento caso o usu�rio escolha sair.
void sair() {
		
	system("cls");
	printf("\n\n\n\n\tAt� logo!!");
	printf("\t    *****    \n"); 
	printf("\t\t\t  *       *  \n"); 
	printf("\t\t\t *  O   O  * \n"); 
	printf("\t\t\t*     ^     *\n"); 
	printf("\t\t\t*   \\___/   *\n"); 
	printf("\t\t\t *         * \n"); 
	printf("\t\t\t  *       *  \n");
	printf("\t\t\t    *****    \n"); 
}
