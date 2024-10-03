#include <stdio.h>
/*EX04 - Respostas 
Responda qual comando de loop é o mais adequado para cada situação
a seguir:
a) Sei exatamente quantas vezes o loop deve rodar;
	Nesse caso, o comando mais adequado é o for.
	
b) Não sei quantas vezes, mas quero que rode pelo menos uma vez;
	Nesse caso, deve-se usar o do while.
	
c) Não sei quantas vezes, podendo não rodar nenhuma vez.
	Nesse caso, é mais adequado o while.
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
