#include <stdio.h>
int main () {
	char nome[20] = "Dante";
	printf("%s\n", nome);
	// Uma letra por linha
	printf("%c \n%c \n%c \n%c \n%c\n", nome[0], nome[1], nome[2], nome[3], nome[4]);
	// Na diagonal
	printf("%c \n\t%c \n\t\t%c \n\t\t\t%c \n\t\t\t\t%c", nome[0], nome[1], nome[2], nome[3], nome[4]);
	//MELHORAR O CÓDIGO DEPOIS
}
