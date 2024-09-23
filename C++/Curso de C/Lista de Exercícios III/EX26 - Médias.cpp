#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

//EX26 - Médias

int main () {
	setlocale(LC_ALL, "Portuguese");
	
	float n1, n2, media;
	int opcao;
	
	while (1) {
		printf ("-------------------\n");
		printf ("CÁLCULO DE MÉDIAS\n");
		printf ("-------------------\n");
		
		printf ("\nPrimeira Nota: ");
		scanf ("%f", &n1);
		while (n1 < 0 || n1 > 10) {
			printf ("Nota inválida, insira uma nota válida entre 0 e 10: ");
			scanf ("%f", &n1);
		}
		
		printf ("\nSegunda Nota: ");
		scanf ("%f", &n2);
		while (n2 < 0 || n2 > 10) {
			printf ("Nota inválida, insira uma nota válida entre 0 e 10: ");
			scanf ("%f", &n2);
		}
		
		media = (n1 + n2) / 2;
	
		printf ("\n-------------------\n"); 	
		printf ("RESULTADO DO ALUNO\n");
		printf ("-------------------\n"); 
		printf ("NOTA 1: %.2f\nNota 2: %.2f\n", n1, n2);
		printf ("MÉDIA: %.2f\n", media);
		
		printf ("-------------------\n"); 
		printf ("Novo cálculo?\n1 - Sim\n2 - Não\nOpção: ");
		scanf ("%d", &opcao);
		
		while (opcao != 1 && opcao != 2) {
			printf ("Opção inválida. Insira 1 para Sim e 2 para Não.\nOpção: ");
			scanf ("%d", &opcao);
		}
		
		switch (opcao) {
			case 1: 
				system("cls");
			break;
			case 2:
				return 0;
		}
	}
}
