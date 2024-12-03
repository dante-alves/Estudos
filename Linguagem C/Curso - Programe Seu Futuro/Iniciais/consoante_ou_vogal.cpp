#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>

//Ler um caractere e dizer se é consoante ou vogal.

int main () {
	char letra, generaliza;
	setlocale(LC_ALL, "Portuguese");
	
	printf ("Insira uma letra: ");
	scanf (" %c", &letra);
	
	/*if (letra == 'a' || letra == 'A' || letra == 'e' || letra == 'E' || letra == 'i' || letra == 'I' || letra == 'o' || letra == 'O' || letra == 'u' || letra == 'U') {
		printf ("A letra é uma vogal.");
	} else {
		printf ("A letra é consoante.");
	}*/
	
	// ou 
	
	generaliza = toupper(letra);
	
	if (generaliza == 'A' || generaliza == 'E' || generaliza == 'I' || generaliza == 'O' || generaliza == 'U') {
		printf ("A letra %c é uma vogal", generaliza);
	} else {
		printf ("A letra %c é uma consoante", generaliza);
	}
	
}
