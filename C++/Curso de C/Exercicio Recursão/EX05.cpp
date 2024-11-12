#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

/*EX05 - Crie uma fun��o recursiva que receba um n�mero inteiro positivo N e calcule o
somat�rio dos n�meros de 1 a N*/

int somatorioN(int n){
	if(n == 1)
		return 1;
	else
		return n + somatorioN(n - 1);
}

void sequencia(int n){
	if(n == 1)
		printf("%d ", n);
	else{
		sequencia(n - 1);
		printf("%d ", n);
	}
}
int main(){
	int n;
	
	printf("Digite um n�mero: ");
	scanf("%d", &n);
	
	printf("Sequencia: ");
	sequencia(n); 
	
	printf("\nA soma de todos os valores entre 1 e %d � igual a: %d", n, somatorioN(n));
	
	return 0;
}
