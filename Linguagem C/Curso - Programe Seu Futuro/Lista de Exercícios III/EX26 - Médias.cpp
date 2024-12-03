#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

//EX26 - M�dias

int main () {
	setlocale(LC_ALL, "Portuguese");
	
	float n1, n2, media;
	int opcao;
	
	while (1) {
		printf ("-------------------\n");
		printf ("C�LCULO DE M�DIAS\n");
		printf ("-------------------\n");
		
		printf ("\nPrimeira Nota: ");
		scanf ("%f", &n1);
		while (n1 < 0 || n1 > 10) {
			printf ("Nota inv�lida, insira uma nota v�lida entre 0 e 10: ");
			scanf ("%f", &n1);
		}
		
		printf ("\nSegunda Nota: ");
		scanf ("%f", &n2);
		while (n2 < 0 || n2 > 10) {
			printf ("Nota inv�lida, insira uma nota v�lida entre 0 e 10: ");
			scanf ("%f", &n2);
		}
		
		media = (n1 + n2) / 2;
	
		printf ("\n-------------------\n"); 	
		printf ("RESULTADO DO ALUNO\n");
		printf ("-------------------\n"); 
		printf ("NOTA 1: %.2f\nNota 2: %.2f\n", n1, n2);
		printf ("M�DIA: %.2f\n", media);
		
		printf ("-------------------\n"); 
		printf ("Novo c�lculo?\n1 - Sim\n2 - N�o\nOp��o: ");
		scanf ("%d", &opcao);
		
		while (opcao != 1 && opcao != 2) {
			printf ("Op��o inv�lida. Insira 1 para Sim e 2 para N�o.\nOp��o: ");
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
