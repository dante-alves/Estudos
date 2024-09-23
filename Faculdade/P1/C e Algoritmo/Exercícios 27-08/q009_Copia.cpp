#include <stdio.h>
#include <string.h>

//Função para trocar as letras
void codificaZenitPolar (char *texto) {
	for (int i = 0; i < strlen(texto); i++) { //strlen pega o tamanho 
		switch (texto[i]) {
			case 'Z': texto[i] = 'P'; break;
			case 'z': texto[i] = 'p'; break;
			case 'E': texto[i] = 'O'; break;
			case 'e': texto[i] = 'o'; break;
			case 'N': texto[i] = 'L'; break;
			case 'n': texto[i] = 'l'; break;
			case 'I': texto[i] = 'A'; break;
			case 'i': texto[i] = 'a'; break;
			case 'T': texto[i] = 'R'; break;
			case 't': texto[i] = 'r'; break;
			//Contrário
			case 'P': texto[i] = 'Z'; break;
			case 'p': texto[i] = 'z'; break;
			case 'O': texto[i] = 'E'; break;
			case 'o': texto[i] = 'e'; break;
			case 'L': texto[i] = 'N'; break;
			case 'l': texto[i] = 'n'; break;
			case 'A': texto[i] = 'I'; break;
			case 'a': texto[i] = 'i'; break;
			case 'R': texto[i] = 'T'; break;
			case 'r': texto[i] = 't'; break;
			default: break; //Para evitar que pegue qualquer outro caractere
		}
	}
}

//Função main

int main () {
	char texto[100];
	printf ("Digite uma frase: ");
	fgets (texto, sizeof(texto), stdin);
	
	codificaZenitPolar (texto);
	
	printf ("A frase codificada se torna: %s\n ", texto);
}
