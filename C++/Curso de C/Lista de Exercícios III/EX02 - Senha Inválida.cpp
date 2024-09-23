#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//EX02 - Senha Inválida 

int main () {
	setlocale(LC_ALL, "Portuguese");
	int senha;
	
	printf ("Qual é a senha? ");
	scanf ("%d", &senha);
	
	while (senha != 123456) {
		printf ("Senha Inválida.\nInsira a senha correta: ");
		scanf ("%d", &senha);
	}
	printf ("Acesso Permitido.");
}

