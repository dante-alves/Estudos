#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//EX04 - Invertendo letras 2 a 2 no nome completo.

int main () {
	char nome1[256], nome2[256], nome3[256], nome4[256], nomeCompleto[256] = {""}, aux, nomeModificado[256];

	printf("Qual seu nome completo? ");
	

	scanf("%s %s %s %s", nome1, nome2, nome3, nome4); 
	
	//Concatenando o nome de jeito podre
	strcat(nomeCompleto, nome1);
	strcat(nomeCompleto, " ");
	strcat(nomeCompleto, nome2);
	strcat(nomeCompleto, " ");
	strcat(nomeCompleto, nome3); 
	strcat(nomeCompleto, " ");
	strcat(nomeCompleto, nome4); 
	
	
	//Printar o nome com as letras trocadas de 2 em 2
	for (int i = 0; i < strlen(nomeCompleto); i += 2)
		printf("%c%c", nomeCompleto[i+1], nomeCompleto[i]);
		
		
	//Passar o nome original para modificar em outra variável
	strcpy(nomeModificado, nomeCompleto);
		
	//Modificando o nome
	for (int i = 0; i < strlen(nomeModificado) - 1; i += 2) {
		aux = nomeModificado[i];
		nomeModificado[i] = nomeModificado[i + 1];
		nomeModificado[i + 1] = aux;
	}
	
	//Printando o resultado
	printf("\nNome original: %s\n", nomeCompleto);
	printf("Nome modificado: %s", nomeModificado);
}
