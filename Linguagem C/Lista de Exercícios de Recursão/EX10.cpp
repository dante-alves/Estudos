#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*EX10 - Escreva uma fun��o recursiva que determine quantas vezes um d�gito K ocorre
em um n�mero natural N. Por exemplo, o d�gito 2 ocorre 3 vezes em 762021192*/

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
	printf("Insira um n�mero inteiro e um d�gito a ser identificado dentro desse n�mero: ");
	scanf("%d %d", &n, &k);
	
	printf("Quantas vezes %d aparece em %d: %d", k, n, digito_no_numero(k, n, 0));
	
	return 0;
}
