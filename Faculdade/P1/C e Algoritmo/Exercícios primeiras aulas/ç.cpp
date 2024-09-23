#include <stdio.h>


// Ler o numero e verificar se ele é [PAR] ou [IMPAR]

int main () {
	// Variaveis
	int n;
	
 	printf("\nDigite um numero inteiro: ");
 	scanf("%d", &n);
 	
 	if (n % 2 == 0)
	 {
	 	printf("\nO numero lido foi: %d\n Ele e [PAR]", n);
	 } else 
	 {
	 	printf ("\nO numero lido foi: %d\n Ele e [IMPAR]", n);
	 }
	return 0;
} 
