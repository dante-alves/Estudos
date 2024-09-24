#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

//EX06 - Zenit Polar

//Função para codificar

char* codificaZenit(char *texto) {
	for (int i = 0; i < strlen(texto); i++) {
		switch (texto[i]) {
			case 'Z': texto[i] = 'P';
			break;
			case 'E': texto[i] = 'O';
			break;
			case 'N': texto[i] = 'L';
			break;
			case 'I': texto[i] = 'A';
			break;
			case 'T': texto[i] = 'R';
			break;
			case 'P': texto[i] = 'Z';
			break;
			case 'O': texto[i] = 'E';
			break;
			case 'L': texto[i] = 'N';
			break;
			case 'A': texto[i] = 'I';
			break;
			case 'R': texto[i] = 'T';
			break;
			case 'z': texto[i] = 'p';
			break;
			case 'e': texto[i] = 'o';
			break;
			case 'n': texto[i] = 'l';
			break;
			case 'i': texto[i] = 'a';
			break;
			case 't': texto[i] = 'r';
			break;
			case 'p': texto[i] = 'z';
			break;
			case 'o': texto[i] = 'e';
			break;
			case 'l': texto[i] = 'n';
			break;
			case 'a': texto[i] = 'i';
			break;
			case 'r': texto[i] = 't';
		}
	}
	return ("%s", texto);
}


int main () {
	char texto[256];
	
	printf("Digite um texto: ");
	fgets(texto,sizeof texto, stdin);

	printf("%s", codificaZenit(texto));
	
return 0;
}
