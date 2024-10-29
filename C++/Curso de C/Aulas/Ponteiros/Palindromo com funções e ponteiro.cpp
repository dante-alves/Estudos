#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Verificar Palíndromo com funções e ponteiro

//Procedimento para ler a palavra
void lerPalavra(char palavra[]){
	printf("Digite uma palavra para verificar se eh palindromo: ");
	scanf("%20[^\n]", palavra);
}

//Função para verificar se é palíndromo
int verificaPalindromo(char palavra[]){
	int i = 0, tam, palindromo = 1;
	
	tam = strlen(palavra);
	
	while(tam >= i){
		if(palavra[i++] != palavra[--tam])
			palindromo = 0;
	}
	
	return palindromo;
}

//Procedimento para dar o resultado
void resultado(char palavra[]){
	if(verificaPalindromo(palavra) == 1)
		printf("\nA palavra %s eh palindromo.", palavra);
	else
		printf("\nA palavra %s nao eh palindromo.", palavra); 
	
}

int main(){
	char palavra[20];
	
	lerPalavra(palavra);
	resultado(palavra);
	
	return 0;
}
