#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*EX03 - Faça uma função recursiva que permita inverter um número inteiro N. Ex: 123 - 321*/

int inverter(int n, int invertido){
        /*invertido começa com 0, e é multiplicado por 10 e somado ao resto da divisão de n dividido por 10. Isso se repete até que a divisão de n por 10 seja igual a 0*/

	if(n == 0)
		return invertido;
	else{
		invertido = invertido * 10 + n % 10;
		
		return inverter(n / 10, invertido);
	}
}

int main(){
	setlocale(0, "Portuguese");
	
	int n;
	
	printf("Digite um número: ");
	scanf("%d", &n);
	
	n = inverter(n, 0);
	
	printf("\n%d", n);
	
	return 0;
}
