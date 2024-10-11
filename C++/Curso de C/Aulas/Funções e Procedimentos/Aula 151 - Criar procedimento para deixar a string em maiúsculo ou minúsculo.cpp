#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h> //Fun��es toupper e tolower

char frase[50];

//Aula 151 - Criar procedimento para deixar a string em mai�sculo ou min�sculo
//DEIXAR MAI�SCULO
void strMaiusc(int tam) {
	int i;
	
	for (i = 0; i < tam; i++){
		frase[i] = toupper(frase[i]);
	}
	
	//Tamb�m poderia utilizar um while(frase[i] != '\0')
}

//DEIXAR MIN�SCULO
void strMinusc(int tam) {
	int i;
	
	for (i = 0; i < tam; i++){
		frase[i] = tolower(frase[i]);
	}
}

int main() {
	setlocale(0, "Portuguese");
	int escolha, tam;
	
	printf("Digite uma frase: ");
	scanf("%50[^\n]", frase);
	
	tam = strlen(frase);
	
	printf("Deseja deixar em mai�sculo ou min�sculo?\n\n[1]Mai�sculo\n[2]Min�sculo\nSua escolha: ");
	scanf("%d", &escolha);
	
	switch(escolha) {
		case 1:
			strMaiusc(tam);
			printf("Frase em mai�sculo: %s", frase);
		break;
		case 2:
			strMinusc(tam);
			printf("Frase em min�sculo: %s", frase);
		break;
		default:
			printf("Valor inv�lido.");
	}
	return 0;
}
