#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*EX10 - Escreva uma função recursiva que determine quantas vezes um dígito K ocorre
em um número natural N. Por exemplo, o dígito 2 ocorre 3 vezes em 762021192*/

int digito_no_numero(int k, int n, int qtd){
	if(n == 0){
		if(k == 0)
			return qtd + 1;
		else
			return qtd;
	}
	else{
		if(k == n % 10)
			return digito_no_numero(k, n / 10, qtd + 1);
		else
			return digito_no_numero(k, n / 10, qtd);
	}
}
int main(){
	int k, n;
	printf("Insira um número inteiro e um dígito a ser identificado dentro desse número: ");
	scanf("%d %d", &n, &k);
	
	printf("Quantas vezes %d aparece em %d: %d", k, n, digito_no_numero(k, n, 0));
	
	return 0;
}
