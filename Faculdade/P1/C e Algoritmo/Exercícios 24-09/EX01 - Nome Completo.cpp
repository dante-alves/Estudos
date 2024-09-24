#include <stdio.h>
#include<stdlib.h>
#include<locale.h>
#include <string.h>

//EX01 - Nome Completo

int main () {
	char nome1[256], nome2[256], nome3[256];
	char nomeTeste[256];

	printf("\nQual seu nome completo? ");
	//Pra ler a string completa, lendo os espa�os
	fgets(nomeTeste, sizeof nomeTeste,stdin);
	
	printf("%s", nomeTeste);
	
	//Pra verificar onde tem o caractere da string 2 ("\n") na string 1 (nomeTeste) e substitu�-lo por fim da string '\0'.  
	nomeTeste[strcspn(nomeTeste, "\n")] = '\0'; // A fun��o strcspn() localiza a primeira ocorr�ncia de um caractere em string1 que pertence ao conjunto de caracteres especificado por string2. Os caracteres nulos n�o s�o considerados na procura.
	
	/*OU
	
	printf("Qual seu nome completo? ");
	scanf("%s %s %s", nome1, nome2, nome3);
	printf("\n%s %s %s", nome1, nome2, nome3);*/

	return 0;
}
