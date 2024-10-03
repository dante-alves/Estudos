#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

//EX16 - Jogo da Velha 
/*|X|
-------
  |X|
-------
  |X|O

*/

int main () {
	setlocale(0, "Portuguese");
	int tam = 3;
	char m[tam][tam], bola = 'O', xis = 'X', vencedor;
	int l, c, cont = 0, pos, vez = 1, velha = 0, opcao;
	
	for (l = 0; l < tam; l++) {
		for (c = 0; c < tam; c++) {
			m[l][c] = ' ';
		}
	}
	while (1) {
		vencedor = ' ';
		velha = 0;
		cont = 0;
		printf("POSIÇÕES DE CADA QUADRADO\n");
		printf("--------------------------\n\n");
		for (l = 0; l < tam; l++) {
			for (c = 0; c < tam - 1; c++) {
				if (c == 0)
					printf("   ");
				printf("%d|", ++cont);
				
			}
			printf("%d\n", ++cont);
			
			if (l < tam - 1)
				printf("  -------\n");
		}
		printf("\n--------------------------\n\n");
		
		//Estrutura do jogo da velha
		for (l = 0; l < tam; l++) {
			for (c = 0; c < tam - 1; c++) {
				if (c == 0)
					printf("   ");
				printf("%c|", m[l][c]);
				
			}
			printf("%c\n", m[l][c]);
			
			if (l < tam - 1)
				printf("  -------\n");
		}
		
		//Verificar se alguém venceu
		//Por linha
		for (c = 0; c < tam; c++) {
			if (m[0][c] == xis && m[0][c] == m[1][c] && m[1][c] == m[2][c]) {
				vencedor = xis;
			} else if (m[0][c] == bola && m[0][c] == m[1][c] && m[1][c] == m[2][c]) {
				vencedor = bola;
			}
		} 
		
		//Por coluna
		for (l = 0; l < tam; l++) {
			if (m[l][0] == xis && m[l][0] == m[l][1] && m[l][1] == m[l][2]) {
				vencedor = xis;
			} else if (m[l][0] == bola && m[l][0] == m[l][1] && m[l][1] == m[l][2]) {
				vencedor = bola;
			}
		} 
		
		//Por diagonal principal
		l = 0;
		if (m[l][l] == xis && m[l][l] == m[l+1][l+1] && m[l][l] == m[l+2][l+2]) {
			vencedor = xis;
		} else if (m[l][l] == bola && m[l][l] == m[l+1][l+1] && m[l][l] == m[l+2][l+2]) {
			vencedor = bola;
		}
		
		//Por diagonal secundária
		l = 0;
		if (m[l][tam-1-l] == xis && m[l][tam-1-l] == m[l+1][tam-2-l] && m[l][tam-1-l] == m[l+2][tam-3-l]) {
			vencedor = xis;
		} else if (m[l][tam-1-l] == bola && m[l][tam-1-l] == m[l+1][tam-2-l] && m[l][tam-1-l] == m[l+2][tam-3-l]) {
			vencedor = bola;
		}
		
		//Verificar se deu velha
		for (l = 0; l < tam; l++) {
			for (c = 0; c < tam; c++) {
				if (m[l][c] != ' ')
					velha++;
			}
		}
		
		if (velha == 9) {
			vencedor = 'v';
		}
		
		//Finalizar o jogo e perguntar se quer jogar novamente
		if (vencedor == xis) {
			printf("\nJogador X venceu!\n");
			printf("Quer jogar novamente? [1]SIM [2]NÃO\n");
			scanf("%d", &opcao);
			
			switch (opcao) {
				case 1: 
					for (l = 0; l < tam; l++) {
						for (c = 0; c < tam; c++) {
							m[l][c] = ' ';
						}
					}
				system("cls");
				break;
				case 2: 
					return 0;
		}
		} else if (vencedor == bola) {
			printf("\nJogador O venceu!\n");
			printf("Quer jogar novamente? [1]SIM [2]NÃO\n");
			scanf("%d", &opcao);
			
			switch (opcao) {
				case 1: 
					for (l = 0; l < tam; l++) {
						for (c = 0; c < tam; c++) {
							m[l][c] = ' ';
						}
					}
				system("cls");
				break;
				case 2: 
					return 0;
		}
		} else if ( vencedor == 'v') {
			printf ("\nO jogo deu VELHA.\n");
			printf("Quer jogar novamente? [1]SIM [2]NÃO\n");
			scanf("%d", &opcao);
			
			switch (opcao) {
				case 1: 
					for (l = 0; l < tam; l++) {
						for (c = 0; c < tam; c++) {
							m[l][c] = ' ';
						}
					}
				system("cls");
				break;
				case 2: 
					return 0;
		}
		
		//Perguntar qual vai ser a próxima jogada
		} else {

			if (vez == 1) {
				
				//VEZ DE X
				
				printf("\n(Jogador X)Em qual posição quer jogar? ");
				scanf("%d", &pos);
				
				while (m[(pos - 1) / tam][(pos - 1) % tam] != ' ') {
					printf("Posição já preenchida. insira outra posição: ");
					scanf("%d", &pos);
				}
				
				m[(pos - 1) / tam][(pos - 1) % tam] = xis;
				
				vez = 2;
			} else if (vez == 2) {
				
				//VEZ DE BOLINHA
				
				printf("\n(Jogador O)Em qual posição quer jogar? ");
				scanf("%d", &pos);
				
				while (m[(pos - 1) / tam][(pos - 1) % tam] != ' ') {
					printf("Posição já preenchida. insira outra posição: ");
					scanf("%d", &pos);
				}
				
				m[(pos - 1) / tam][(pos - 1) % tam] = bola;
				
				vez = 1;
			}
			system("cls");
		}
	}
	
	return 0;
}
