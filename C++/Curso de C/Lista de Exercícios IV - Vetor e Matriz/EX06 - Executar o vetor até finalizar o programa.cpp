#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//EX06 - Executar o vetor at� finalizar o programa

int main () {
	setlocale(0, "Portuguese");
	
	float reais[10]; 
	int opcao, i;
	
	for (i = 0; i < 10; i++) {
		printf("Valor %d: ", i);
		scanf("%f", &reais[i]);
	}
	
	while (1) {
		printf("\nEscolha uma das a��es abaixo: ");
		printf("\n1 - Imprimir o vetor do in�cio ao fim");
		printf("\n2 - Imprimir o vetor do fim ao in�cio");
		printf("\n3 - Modificar os valores do vetor");
		printf("\n0 - Finalizar o programa\n\n");
		
		scanf("%d", &opcao);
		
		while (opcao != 0 && opcao != 1 && opcao != 2 && opcao != 3) {
			printf("Op��o inv�lida. Insira outro valor: ");
			scanf ("%d", &opcao);
		}
	
		switch (opcao) {
			case 1:
				printf("\nVetor do in�cio ao fim: ");
				for (i = 0; i <9; i++) {
					printf("[%1.f], ", reais[i]);
				}
				printf("[%1.f].\n", reais[i]);
			break;
			
			case 2:
				printf("\nVetor do fim ao in�cio: ");
				for (i = 9; i > 0; i--) {
					printf("[%1.f], ", reais[i]);
				}
				printf("[%1.f].\n", reais[i]);
			break;
			
			case 3:
				printf("\nModificar valores do vetor\n");
				for (i = 0; i < 10; i++) {
					printf("Valor %d: ", i);
					scanf("%f", &reais[i]);
				}
			break;
			case 0:
				printf("At� a pr�xima! :)");
				return 0;
		}

	}
	
	return 0;
}
