#include <stdio.h>
#include <stdlib.h>

//Aula 145, 146 e 147 - Funções e Procedimentos

//Função para somar
int soma(int x, int y) {
	return x + y;
}

//Função para calcular o tamanho de uma string
int tamanhoString(char str[]) {
	int cont = 0;
	
	while (str[cont] != '\0')
		cont++;
	
	return cont;
}

//Procedimento para imprimir uma string caracter por caracter
void printString(char str[], int len) {
	int i;
	for (i = 0; i < len; i++)
		printf("%c", str[i]);
	printf("\n");
	
	/* OU
	i = 0;
	while (str[i] != '\0')
		printf("%c", str[i++]);
	printf("\n");
	*/
}
int main() {
	//Função para somar
	int resultado, num1 = 5, num2 = 8;
	
	resultado = soma(num1,num2);
	
	printf("A soma eh %d\n", resultado);
	
	//Função para calcular o tamanho de uma string
	char str[20];
	int tam;
	
	printf("Digite uma frase: ");
	scanf("%20[^\n]", str);
	scanf("%c");
	
	tam = tamanhoString(str);
	printf("\nTamanho da string: %d\n\n", tam);
	
	//Procedimento para imprimir uma string caracter por caracter
	
	printString(str, tam);
	
	return 0;
}

