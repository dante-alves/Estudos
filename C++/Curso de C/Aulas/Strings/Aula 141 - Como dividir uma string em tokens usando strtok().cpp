#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Aula 141 - Como dividir uma string em tokens usando strtok()

int main () {
	char palavras[50] = {"Fala!bonecos-e bonecas."}, teste;
	char *token;
	
	token = strtok(palavras,"!- "); //d� pra colocar mais de um delimitador (!- )
	
	while (token) { //SE EU S� DEIXO O (token) ENTRE PARENTESES, � O MESMO QUE COLOCAR (token != NULL)
		printf("%s\n", token);
		token = strtok(NULL, "!- ");
	}

	return 0;
}
