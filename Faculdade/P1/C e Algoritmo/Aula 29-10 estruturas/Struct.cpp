#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct{
	char ferramenta[20];
}Ferramentas;

int main(){
	setlocale(0, "Portuguese");
	
	Ferramentas caixa[5];
	int i;
	
	for(i = 0; i < 5; i++){
		printf("Escolha uma ferramenta: ");
		scanf("%20[^\n]", caixa[i].ferramenta);
		scanf("%c");
	}
	
	printf("Ferramentas Escolhidas: ");
	for(i = 0; i < 5; i++)
		printf("\n%s", caixa[i].ferramenta);
	
	
	return 0;
}
