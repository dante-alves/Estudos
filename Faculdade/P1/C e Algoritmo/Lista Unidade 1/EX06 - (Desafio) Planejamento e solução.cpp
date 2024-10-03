#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
/*EX06 - Planejamento e solução
(Desafio) Em uma eleição existem três candidatos A, B, D. Escreva um
programa em C que efetue a apuração dos votos e informe a
quantidade de votos por candidatos, a quantidade de eleitores, a
quantidade de votos nulos e a quantidade de votos em branco. A partir
do enunciado, faça o planejamento conforme praticado em sala de
aula.

Armazenar os candidatos em um vetor;
Armazenar a quantidade de votos no candidato em outro vetor;
Armazenar a quantidade de votos em branco;
Armazenar a quantidade de votos nulos;
Calcular o total de eleitores somando tudo.
*/

int main() {
	setlocale(0, "Portuguese");
	char continuar = 'S';
	int votosA, votosB, votosD, brancos, nulos, eleitores, opcao;
	
	//Inicializar as variáveis
	votosA = votosB = votosD = brancos= nulos = eleitores = 0;
	
	//Receber os votos
	do {
		printf("\n-------------------\nURNA ELEITORAL\n-------------------\n");
		printf("[1]Para votar no candidato A\n");
		printf("[2]Para votar no candidato B\n");
		printf("[3]Para votar no candidato D\n");
		printf("[4]Para votar em branco\n");
		printf("[5]Para votar em nulo\n");
		printf("[0]Para Finalizar a Votação\n");
		printf("\nOpção escolhida: ");
		scanf("%d", &opcao);
		
		//Contornar o erro
		while (opcao < 0 || opcao > 5) {
			printf("\nOpção inválida. Insira outra opção: ");
			scanf("%d", &opcao);
		}
		switch (opcao) {
			case 1:
				votosA++;
				printf("\nVotou no Candidato A.\n");
			break;
			case 2:
				votosB++;
				printf("\nVotou no Candidato B.\n");
			break;
			case 3:
				votosD++;
				printf("\nVotou no Candidato D.\n");
			break;
			case 4: 
				brancos++;
				printf("\nVotou em Branco.\n");
			break;
			case 5:
				nulos++;
				printf("\nVotou Nulo.\n");
			break;
			case 0:
				continuar = 'N';	
		}
		
		//Somar o voto do eleitor ao total de eleitores
		if (opcao != 0)
			eleitores++;
		
	} while (continuar == 'S');
	
	//Resultado
	printf("\nAPURAÇÃO DOS VOTOS");
	printf("\n---------------------\n");
	printf("Candidato A: %d\nCandidato B: %d\nCandidato D: %d", votosA, votosB, votosD);
	printf("\nVotos em branco: %d\n", brancos);
	printf("Votos nulos: %d\n", nulos);
	printf("Total de eleitores: %d", eleitores);
	
	return 0;
}
