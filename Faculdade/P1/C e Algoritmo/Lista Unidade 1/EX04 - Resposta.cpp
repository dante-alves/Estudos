#include <stdio.h>
/*EX04 - Respostas 
Responda qual comando de loop � o mais adequado para cada situa��o
a seguir:
a) Sei exatamente quantas vezes o loop deve rodar;
	Nesse caso, o comando mais adequado � o for.
	
b) N�o sei quantas vezes, mas quero que rode pelo menos uma vez;
	Nesse caso, deve-se usar o do while.
	
c) N�o sei quantas vezes, podendo n�o rodar nenhuma vez.
	Nesse caso, � mais adequado o while.
*/ 

int main() {
	int i;
	for (i = 0; i < 1; i++)
		printf("Hello World!\n");
		
	do {
		printf("Hello World!\n");
	} while (0);
	
	while (0)
		printf("Hello World!");
		
	return 0;
}
