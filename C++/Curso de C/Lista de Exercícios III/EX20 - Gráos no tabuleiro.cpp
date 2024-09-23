#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//EX20 - Grãos no tabuleiro


//Poderia usar %llu, ou o %Lf (long double, com 16 bytes)
//Para usar %Lf, é preciso usar __mingw_printf()
int main () {
	setlocale (LC_ALL, "Portuguese");
	
	
	long double soma = 0, graos = 1;
	
	printf ("Grãos por quadro:\n");
	
	for (int i = 1; i <= 64; i++) {
		__mingw_printf ("\n%.0Lf\n", graos);
	
		soma += graos;
		graos *= 2;
	}
	__mingw_printf ("\nNo total, o monge recebeu %.0Lf grãos.", soma);
}
