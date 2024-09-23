#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <string.h>
int main () {
	setlocale(LC_ALL, "Portuguese");
	char nome[15], res[2], maiusculo[2];

	
	/*do {
		printf ("Qual o nome do aluno? ");
		fgets (nome, sizeof(nome), stdin);
		
		nome[strcspn(nome, "\n")] = '\0';
		
		printf ("O nome é %s\n", nome);
		printf ("Quer continuar? S/N  ");
		fgets (res, sizeof(res), stdin);
		
		res[strcspn(res, "\n")] = '\0';
		
		maiusculo[0] = toupper(res[0]);
		maiusculo[1] = '\0';
		getchar();
	} while (strcmp(maiusculo, "N") == 1); */
	
		do {
		printf ("Qual o nome do aluno? ");
		scanf (" %s", nome);

		printf ("O nome é %s\n", nome);
		printf ("Quer continuar? S/N  ");
		scanf (" %s", res);
		
		maiusculo[0] = toupper(res[0]);
		maiusculo[1] = '\0';

	} while (strcmp(maiusculo, "S") == 0);
}
