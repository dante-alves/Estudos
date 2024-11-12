#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*Crie um programa em C, que contenha uma fun��o recursiva que receba dois
inteiros positivos k e n e calcule k elevado a n. Utilize apenas multiplica��es. 
O programa principal deve solicitar ao usu�rio os valores de k e n e imprimir o 
resultado da chamada da fun��o*/

int potencia(int k, int n){
	if(n == 0)
		return 1;
	else{
		return k * potencia(k, n - 1);
	}
}

int main(){
	int n, k;
	
	printf("Insira os valores de K e N: ");
	scanf("%d%d", &k, &n);
	
	printf("K elevado a N � igual a: %d", potencia(k, n));
	
	return 0;
}
