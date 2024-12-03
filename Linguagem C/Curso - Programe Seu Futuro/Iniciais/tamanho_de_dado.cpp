#include <stdio.h>
#include <stdlib.h>

int main () {
	short int y = 32767; //short diminui o consumo de memória da variável para 2 bytes = 16 bits = 111111111111111
	float x = 1.0;
	char c[2] = "C";
	long long int w = 2147812423;
	long double v = 3.35432234623462346;
	
	printf ("Tamanho de short int y: %d\n", y); //Esse dá 32767 positivo, pois tem 15 bits
	y++;
	printf ("Tamanho de short int y: %d\n", y); //Esse dá 32768 negativo, pois tem 16 bits, e o bit mais a esquerda de um número é usado para definir se é positivo ou negativo
												//(1 é negativo, 0 é positivo)
	
	printf ("Tamanho em memoria de int: %d bytes\n", sizeof(int));
	
	printf ("Tamanho em memoria de char: %d bytes\n", sizeof(c));
	
	printf ("Tamanho de um float na memoria: %d bytes\n", sizeof x);
	
	printf ("Tamanho de um long long int: %d bytes\n", sizeof w);
	printf ("Valor do long long int: %lld\n", w);
	
	printf ("Tamanho de um long double: %d bytes\n", sizeof v); //long double tem 16 bytes
	__mingw_printf("Valor de v: %Lf\n", v);
	//sizeof não é uma função, é um operador!
	
	//o long, diferente do short, não aumenta a ocupação de memória, continuam sendo 4 bytes
	//Mas se usar long long int, ele ocupará 8 bytes
	
	//Para printar um número long double no windows, é preciso usar a função __mingw_printf("Valor de v: %Lf", v);
}
