#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//EX02 - Senha Inv�lida 

int main () {
	setlocale(LC_ALL, "Portuguese");
	int senha;
	
	printf ("Qual � a senha? ");
	scanf ("%d", &senha);
	
	while (senha != 123456) {
		printf ("Senha Inv�lida.\nInsira a senha correta: ");
		scanf ("%d", &senha);
	}
	printf ("Acesso Permitido.");
}

