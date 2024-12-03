#include <stdio.h>
#include <string.h>

//Tentando fazer o ZENIT-POLAR

int main () {
	char texto[100];
	printf ("Escreva um texto: ");
	fgets (texto, sizeof(texto), stdin);
	
	for (int i = 0; i < strlen(texto); i++) {
		switch (texto[i]) {
		case 'Z': texto[i] = 'P'; break;
		case 'z': texto[i] = 'p'; break;
		case 'E': texto [i] = 'O'; break;
		case 'e'
		case 'N'
		case 'n'
		case 'I'
		case 'i'
		case 'T'
		case 't'
		default: break;
		}
	}
	
	printf ("reescrito ficou: %s", texto);
}

case
case
case
case
case
case
case
case
case
case
'P'
'p'
'O'
'o'
'L'
'l'
'A'
'a'
'R'
'r'
'Z'
'z'
'E'
'e'
'N'
'n'
'I'
'i'
'T'
't'
