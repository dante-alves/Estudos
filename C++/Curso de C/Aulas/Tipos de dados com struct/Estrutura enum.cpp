#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

enum estado_civil{
	casada = 1,
	solteira = 2
};

int main(){
	setlocale(0, "Portuguese");
	
	enum estado_civil e_civil;
	
	printf("Digite 1 para casada e 2 para solteira: ");
	scanf("%d", &e_civil);
	
	switch(e_civil){
		case casada:
			printf("Olá casada...");
		break;
		case solteira:
			printf("Olá solteira...");
	}
	
	return 0;
}
