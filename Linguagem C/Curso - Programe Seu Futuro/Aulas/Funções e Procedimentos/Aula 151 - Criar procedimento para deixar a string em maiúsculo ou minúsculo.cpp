#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h> //Funções toupper e tolower

char frase[50];

//Aula 151 - Criar procedimento para deixar a string em maiúsculo ou minúsculo
//DEIXAR MAIÚSCULO
void strMaiusc(int tam) {
	int i;
	
	for (i = 0; i < tam; i++){
		frase[i] = toupper(frase[i]);
	}
	
	//Também poderia utilizar um while(frase[i] != '\0')
}

//DEIXAR MINÚSCULO
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
	
	printf("Deseja deixar em maiúsculo ou minúsculo?\n\n[1]Maiúsculo\n[2]Minúsculo\nSua escolha: ");
	scanf("%d", &escolha);
	
	switch(escolha) {
		case 1:
			strMaiusc(tam);
			printf("Frase em maiúsculo: %s", frase);
		break;
		case 2:
			strMinusc(tam);
			printf("Frase em minúsculo: %s", frase);
		break;
		default:
			printf("Valor inválido.");
	}
	return 0;
}
