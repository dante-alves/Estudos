#include <stdio.h>
#include <stdlib.h>

/*
	EX05 - Implemente a função strcpy (char *destino, char *origem) usando ponteiros.
*/

void strcpy(char *destino, char *origem){
	int i = 0;
	
	while(origem[i] != '\0'){
		destino[i] = origem[i];
		i++;
	}
	destino[i] = '\0';
	
	/*OU forma com aritmética de ponteiros
	while(*(origem + i) != '\0'){
		*(destino + i) = *(origem + i);
		i++;
	}
	*(destino + i) = '\0';
	*/
}

int main(){
	char string[20], copia[20];
	
	printf("Digite uma frase: ");
	scanf("%20[^\n]", string);
	
	strcpy(copia, string);
		
	printf("Frase em string: %s\nFrase em copia: %s", string, copia);
	return 0;
}
