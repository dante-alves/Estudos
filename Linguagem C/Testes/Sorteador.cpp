#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int main () {
	setlocale(0, "Portuguese");
	int intervalo, qtd, i, opcao;
	
	srand(time(NULL));
	
	while (1) {
		//Coletar o intervalo dos números e quantos serão coletados
		printf("O sorteio será feito no intervalo de 0 a ? ");
		scanf("%d", &intervalo);
		printf("\nQuantos valores a serem sorteados? ");
		scanf("%d", &qtd);
		
		//Declarar o vetor no tamanho definido
		int vet[qtd];
		
		//Sortear os números e printar
		printf("\n\nValores sorteados: ");
		for (i = 0; i < qtd; i++){
			vet[i] = rand() % intervalo;
			printf("%d ", vet[i]);
		}
		
		printf("\nSortear novamente? [1]SIM / [2]NÃO\n");
		scanf("%d", &opcao);
		
		switch (opcao) {
			case 1:
				system("cls");
			break;
			case 2:
				return 0;
		}
	}
	
	return 0;
}
