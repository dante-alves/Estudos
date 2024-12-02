#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

//Projeto - Jogo da Velha

// estrutura do usuário
typedef struct{
	char apelido[30];
	int vitorias;
}t_Usuario;

// variáveis globais
char **jogo;
int l, c, pos = 0;

	// RANK
	char f[] = {"Rank.txt"}; // nome do arquivo onde o rank vai ser salvo
	t_Usuario rankeados[15];  // vetor onde o rank vai ser salvo
	int tamRank = 15, quant; // tamanho do rank e quantidade que tem atualmente no rank

// procedimento para inicializar todas as posições da matriz
void inicializarMatriz() {
	for (l = 0; l < 3; l++) {
		for(c = 0; c < 3; c++) {
			jogo[l][c] = ' ';
		}
	}
}

// procedimento para imprimir posições na tela
void imprimirPosicoes() {
	setlocale(0, "Portuguese");
	int cont = 0;
	printf("POSIÇÕES DE CADA QUADRADO\n");
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

// procedimento para imprimir o jogo em si na tela
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




// função para verificar vitória por linhas --> 1 = ganhou; 0 = não ganhou ainda
int ganhouPorLinhas(char X) {
	int cont = 0;
	for (l = 0; l < 3; l++) {
		if (jogo[l][0] == X && jogo[l][0] == jogo[l][1] && jogo[l][1] == jogo[l][2])
			cont++;
	}
	return cont;
}

// função para verificar vitória por colunas
int ganhouPorColunas(char X) {
	int cont = 0;
	for (c = 0; c < 3; c++) {
		if (jogo[0][c] == X && jogo[0][c] == jogo[1][c] && jogo[1][c] == jogo[2][c])
			cont++;
	}
	return cont;
}

// função para verificar vitória por diagonal principal
int ganhouDiagPrincipal(char X) {
	int cont = 0;
	if (jogo[0][0] == X && jogo[0][0] == jogo[1][1] && jogo[1][1] == jogo[2][2])
		cont++;
	return cont;
}

// função para verificar vitória por diagonal secundária
int ganhouDiagSecund(char X) {
	int cont = 0;
	if (jogo[0][2] == X && jogo[0][2] == jogo[1][1] && jogo[1][1] == jogo[2][0])
		cont++;
	return cont;
}

// função para verificar se a posição escolhida é válida
int posValida() {
	if (pos > 0 && pos < 10 && jogo[(pos - 1)/3][(pos - 1) % 3] == ' ') //(pos - 1)/3 e (pos - 1) % 3 é o cálculo para definir a posição da matriz a partir de um único número
		return 1;
	else
		return 0;
}

// procedimento para ler as coordenadas do jogador
void lerCoordenadas(char X) {
	setlocale(0, "Portuguese");
	printf("\nVez do %s. Digite a posição que quer jogar : ", X == 'X' ? "Jogador 1 (X)" : "Jogador 2 (O)");
	scanf("%d", &pos);
	fflush(stdin);
	while (posValida() != 1) {
		printf("\nPosição inválida ou já preenchida. Escolha outra posição: ");
		scanf("%d", &pos);
		fflush(stdin);
	}
	jogo[(pos - 1)/3][(pos - 1) % 3] = X;
}

// função para retornar se o jogo deu velha ou não
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

// procedimento para salvar o rank
void salvarRank(){
	FILE *file = fopen(f, "w+");
	
	int i;
	
	if(file){
		fprintf(file, "Total de jogadores no rank: %d\n\n", quant);
		for(i = 0; i < quant; i++){
			fprintf(file, "%d - %d %s ------------ %s\n", i+1, rankeados[i].vitorias, rankeados[i].vitorias == 1 ? "Vitória" : "Vitórias", rankeados[i].apelido);
		}
		fclose(file);
	}
	else
		printf("\nErro ao abrir o arquivo! :(\n");
}

// procedimento para ler o arquivo do rank
int lerRank(){
	FILE *file = fopen(f, "r");
	
	t_Usuario *novo = (t_Usuario*)malloc(sizeof(t_Usuario)); // alocando memória dinamicamente
	
	int qtd = 0, i;
	
	if(file){
		fscanf(file, "Total de jogadores no rank: %d\n\n", &qtd); // ler o total de jogadores no rank
		for(i = 0; i < qtd; i++){
			fscanf(file, "%*d - %d %*s ------------ %30[^\n]\n", &novo->vitorias, novo->apelido); // ler os dados do jogador
			rankeados[i] = *novo; // salvar no vetor do rank
			novo = (t_Usuario*)malloc(sizeof(t_Usuario)); // realocando memória
		}
		free(novo);
		
		fclose(file);
	}
	else
		file = fopen(f, "w");
		fclose(file);
		
	return qtd;
}


// procedimento para organizar o rank em ordem decrescente
void ordenarRank(){
	int i, troca;
	t_Usuario aux;
	do{
		troca = 0;
		
		for(i = 0; i < quant - 1; i++){
			if(rankeados[i].vitorias < rankeados[i + 1].vitorias){
				aux = rankeados[i];
				rankeados[i] = rankeados[i + 1];
				rankeados[i + 1] = aux;
				
				troca = 1;
			}
		}
	}while(troca);
}

// procedimento para salvar os dados no vetor do rank
void vetorRank(t_Usuario user[]){
	int i, u;
	
	for(u = 0; u < 2; u++){
		if(user[u].vitorias > 0){
			
			for(i = 0; i < tamRank; i++){
				if(stricmp(rankeados[i].apelido, user[u].apelido) == 0){ // caso o nome do jogador já esteja no rank, ele só atualiza as vitórias
					if(rankeados[i].vitorias < user[u].vitorias)
						rankeados[i].vitorias = user[u].vitorias;
						break; //Parar o loop
				}
				
				
				if(rankeados[i].vitorias == 0){ // preencher posições vazias no rank
					rankeados[i] = user[u];
					quant++;
					break;
				}
				
				else if(quant >= tamRank){ //Se já tiver o máximo de usuários no rank
					ordenarRank(); // organizar o rank
					
					if(rankeados[tamRank - 1].vitorias < user[u].vitorias) // substitui o último do rank pelo novo usuário
						rankeados[tamRank - 1] = user[u];
					
					break;
				}
				
			}
			ordenarRank(); // por fim, reorganiza o rank.
		}
	}
}

// procedimento jogar com o loop principal do jogo
void jogar() {
	setlocale(0, "Portuguese");
	// variáveis
	int i, j, jogador = 1, vitoriaX, vitoriaO;
	int opc;
	
	t_Usuario user[2];
	
	// registrar jogadores
	for(i = 0; i < 2; i++){
		printf("Apelido do jogador %d: ", i+1);
		scanf("%20[^\n]", user[i].apelido);
		while (getchar() != '\n');
		
		user[i].vitorias = 0;
	}
	
	do {
		inicializarMatriz();
		system("cls");
		
		// jogar
		do {
			// variaveis que resetam em todo jogo
			vitoriaX = vitoriaO = 0;
			
			system("cls");
			imprimirPosicoes();
			imprimirJogo();
			
			if (jogador == 1){
				lerCoordenadas('X');
				if(ganhouPorLinhas('X') != 0 || ganhouPorColunas('X') != 0 || ganhouDiagPrincipal('X') != 0 || ganhouDiagSecund('X') != 0)
					vitoriaX = 1;
				jogador = 2;
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
		
		if (vitoriaX == 1){
			printf("\n\nVitória do Jogador 1 (%s), parabéns!\n", user[0].apelido);
			user[0].vitorias++; //Acrescentar vitória para o usuário
			jogador = 1;
		}
		else if (vitoriaO == 1){
			printf("\n\nVitória do Jogador 2 (%s), parabéns!\n", user[1].apelido);
			user[1].vitorias++;
			jogador = 2;
		}
		else
			printf("\n\nO jogo deu velha...\n");
			
		printf("\nDigite 1 para jogar novamente: ");
		scanf("%d", &opc);
		fflush(stdin);
		
	} while(opc == 1);
	
	printf("\n-------------------------------------\n");
	for(i = 0; i < 2; i++)
		printf("\nTotal de vitórias de %s: %d\n", user[i].apelido, user[i].vitorias);
		
	// salvando os dados no vetor do ranking
	vetorRank(user);
	
	// fim
	printf("\nPressione ENTER para continuar...");
	getchar();
	fflush(stdin);
	
}

// função que mostra as formas de ganhar no jogo da velha
int tutorialGanhar() {
	int opcao;
	system("cls");
	
		printf("\n\t[TUTORIAL]\n");
		printf("\nComo ganhar ou empatar? -> Existem 3 formas de ganhar\n");
		printf("[1.] -> Completar a linha com o mesmo caractere.\n[2.] -> Completar a coluna com o mesmo caractere.\n[3.] -> Completar a diagonal com o mesmo caractere.\n[4.] -> Se todas as casas estiverem preenchidas e nenhum dos jogadores tiverem ganhado, é EMPATE.");
		printf("\n--------------------------------------------------------------------------------------------\n");
	
		// exemplos de como ganhar
		printf("[1] -> Completar a linha com o mesmo caractere.\n\n");
		jogo[0][0] = jogo[0][1] = jogo[0][2] = 'X';
		imprimirJogo();
		printf("\nJogador 1 é o vencedor.\n\n");
		inicializarMatriz();
		printf("Pressione ENTER para Continuar...");
		getchar();
		fflush(stdin); // evitar de levar algo para o buffer
	
		printf("\n[2.] -> Completar a coluna com o mesmo caractere.\n\n");
		jogo[0][0] = jogo[1][0] = jogo[2][0] = 'O';
		imprimirJogo();
		printf("\nJogador 2 é o vencedor.\n\n");
		inicializarMatriz();
		printf("Pressione ENTER para Continuar...");
		getchar();
		fflush(stdin); // evitar de levar algo para o buffer
	
		printf("\n[3.] -> Completar a diagonal com o mesmo caractere.\n\n");
		jogo[0][0] = jogo[1][1] = jogo[2][2] = 'X';
		imprimirJogo();
		printf("\nJogador 1 é o vencedor.\n\n");
		inicializarMatriz();
		printf("Pressione ENTER para Continuar...");
		getchar();
		fflush(stdin); // evitar de levar algo para o buffer
		
		printf("\n[4.] -> Se todas as casas estiverem preenchidas e nenhum dos jogadores tiverem ganho, é EMPATE.\n\n");
		jogo[0][0] = jogo[0][1] = jogo[1][1] = jogo[1][2] = jogo[2][0] = 'X';
		jogo[0][2] = jogo[1][0] = jogo[2][1] = jogo[2][2] = 'O';
		imprimirJogo();
		printf("\nQue pena, foi empate.\n\n");
		inicializarMatriz();
		
		// finalizar o tutorial de como ganhar
		printf("\n-------------------------------------------------\n");
		printf("\n\n[1] -> Jogar\n[2] -> Voltar ao Menu\n");
		printf("\nINFORME: ");
		scanf("%d", &opcao);

		fflush(stdin); 
		
		system("cls");
		
		if(opcao == 1)
			return 2; // 2 é o número para jogar
		else
			return 0; // 0 é o número para mostrar as opções do menu
}

// função que mostra o tutorial do jogo da velha
int tutorial() {
	char jogador1 = 'X', jogador2 = 'O';
	int jogador;
	
	for(jogador = 1; jogador <= 2; jogador++) {
		system("cls");
	
		printf("\n\t[TUTORIAL]\n");
		printf("\nREGRAS:\n");
		printf("[1.] -> O Jogador 1 joga com a letra 'X'.\n[2.] -> O Jogador 2 joga com a letra 'O'.\n");
		printf("\n-------------------------------------------------\n");
		
		imprimirPosicoes();	
		imprimirJogo();
		if(jogador == 1) {
			printf("\n\nJogador %d = 'X'.", jogador);
			lerCoordenadas(jogador1);
			printf("\n");
		} 
		else {
			printf("\nJogador %d = 'O'", jogador);
			lerCoordenadas(jogador2);
			printf("\n");
			imprimirJogo();
		}
	}
	
	int opcao;
	printf("\n----------------------------------------------");
	printf("\n\n[1] -> Continuar Tutorial -> (Como ganhar ou empatar?)\n[2] -> Voltar ao Menu\n[3] -> Jogar");
	printf("\nINFORME: ");
	scanf("%d", &opcao);
	fflush(stdin);
	system("cls");
	
	while(opcao != 1 && opcao != 2 && opcao != 3){
		printf("Opção Inválida!\n");
		printf("\n\n[1] -> Continuar Tutorial -> (Como ganhar ou empatar?)\n[2] -> Voltar ao Menu\n[3] -> Jogar");
		printf("\nINFORME: ");
		scanf("%d", &opcao);
		fflush(stdin);
		system("cls");
	}
	
	if (opcao == 1)
		opcao = tutorialGanhar(); // retorna 0 ou 2 (menu ou jogar)
	else if(opcao == 2)
		opcao = 0; // voltar para o menu
	else
		opcao = 2; // jogar
	
	return opcao;
}

// procedimento que mostra o ranking
void ranking(){
	int i;
	ordenarRank();
	
	printf("\n\t------------ [ R A N K I N G ] -----------\n");
	for(i = 0; i < quant; i++)
		printf("\n\t[%d.] -> %d %s ------------ %s", i+1, rankeados[i].vitorias, rankeados[i].vitorias == 1 ? "Vitória" : "Vitórias", rankeados[i].apelido);
		
	
	printf("\nPressione ENTER para continuar...");
	getchar();
	fflush(stdin);
	
}

// procedimento que mostra os créditos do projeto
void creditos() {
	system("cls");
	printf("\n\t ------------[P R O J E T O]--------------\n");
	printf("\t|\t\t\t\t\t  |\n");
	printf("\t|  Desenvolvimento do jogo da velha 3x3   |\n");
	printf("\t| para a cadeira Técnicas e Desenvolvi -  |\n");
	printf("\t| mento de Algoritmo (TDA) da UNIPÊ.\t  |\n");
	printf("\t|\t\t\t\t\t  |\n");
	printf("\t| *Discente:* Walace Sartori Bonfim\t  |\n");
	printf("\t|\t\t\t\t\t  |");
	printf("\n\t -----------------------------------------\n");
	
		
	printf("\n\t -------------[E Q U I P E]---------------\n");
	printf("\t|\t\t\t\t\t  |\n");
	printf("\t| [1.] -> Antonio Felix de Oliveira Neto  |\n\t| [2.] -> Dante Alves e Silva\t\t  |\n\t| [3.] -> Guilherme de Medeiros Serpa\t  |\n\t| [4.] -> Iloir Martins de Souza Neto\t  |\n\t| [5.] -> João Nicéforo Cantalice Neto\t  |\n");
	printf("\t|\t\t\t\t\t  |\n\t -----------------------------------------\n");
	
	
	printf("\n\nPressione ENTER para continuar...");
	getchar();
	fflush(stdin);
}	

// procedimento que mostra o menu do jogo
void menu() {
	
	int opcao = 0, opc;
	/* 
		MENU:
			JOGAR - done
			TUTORIAL - done
			RANKING
			CRÉDITOS - done
			SAIR - done
	*/
	
	do{
		switch(opcao) {
			case 0: // menu
				printf("\n------------ [ M E N U ] -----------\n");
				printf("|\t\t\t\t   |\n");
				printf("|  [1] -> Tutorial\t\t   |\n|  [2] -> Jogar\t\t\t   |\n|  [3] -> Mostrar o ranking\t   |\n|  [4] -> Créditos\t\t   |\n|  [5] -> Sair\t\t\t   |");
				printf("\n|\t\t\t\t   |");
				printf("\n------------------------------------\n");
				printf("\nEscolha: ");
				scanf("%d", &opcao);
				fflush(stdin);
				break;
			case 1 : 
				inicializarMatriz();
				opcao = tutorial();
				break;
			
			case 2 : // jogar
			
				jogar();
				opcao = 0;
				break;
			
			case 3 : // ranking
			// ler o arquivo 
				// e mostrar o rank
				ranking();
				opcao = 0;
				break;
				
			case 4 : // creditos
				creditos();
				opcao = 0;
				break;
				
			default :
				printf("\n\tValor inválido!\n\tPressione ENTER para continuar...");
				getchar();
				fflush(stdin);
				opcao = 0;
		} 
		system("cls");
	} while(opcao != 5); //sair
	
			// salvar os dados e imprimir
		system("cls");
		printf("\n\n\n\n\tAté logo!!");
		printf("\t    *****    \n"); // Cabeça
	    printf("\t\t\t  *       *  \n"); // Testa
	    printf("\t\t\t *  O   O  * \n"); // Olhos
	    printf("\t\t\t*     ^     *\n"); // Nariz
	    printf("\t\t\t*   \\___/   *\n"); // Sorriso
	    printf("\t\t\t *         * \n"); // Queixo
	    printf("\t\t\t  *       *  \n");
	    printf("\t\t\t    *****    \n"); // Base
}

void inicializarRank(){
	int i;
	for (i = 0; i < tamRank; i++)
		rankeados[i].vitorias = 0;
}

// MAIN
int main() {
	
	// definindo o idioma
	setlocale(0, "Portuguese");
	
	int i;
	
	// alocando a memória para o ponteiro (linha)
	jogo = (char**)malloc( 3 * sizeof(char*));
	
	// alocando a memoria para as colunas.
	for ( i = 0 ; i < 3 ; i ++)
		*(jogo + i) = (char*)malloc(3 * sizeof(char));
	
	// inicializar o vetor do rank
	inicializarRank();
	
	// ler o arquivo do rank
	quant = lerRank();
	
	// chamar o menu do jogo
	menu();
	
	// salvar o rank no arquivo
	salvarRank();
	
	// liberando a memória
	for ( i = 0 ; i < 3 ; i ++)
		free(*(jogo + i));
	
	free(jogo);
	
	return 0;
} 
