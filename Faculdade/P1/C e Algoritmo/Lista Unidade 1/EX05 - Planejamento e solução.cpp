#include <stdio.h>
#include <locale.h>
/*EX05 Planejamento e solução
Escreva um programa que leia o valor de 4 números inteiros. Em
seguida, deverá ser apresentado o resultado da multiplicação do
primeiro número com o terceiro número lido, e a soma do segundo
número com o quarto número lido. A partir do enunciado, faça o
planejamento conforme praticado em sala de aula.

Posso fazer com 4 variáveis tipo int, ou com um vetor. Optei pelo vetor.
Multiplicação do 1º com o 3º
Soma do 2º com o 4º.
*/

int main() {
	setlocale(0, "Portuguese");
	int v[4], multiplica, soma, i;
	
	//Ler os valores
	for(i = 0; i < 4; i++) {
		printf("Insira um valor: ");
		scanf("%d", &v[i]);
	}
	//Cálculos
	multiplica = v[0] * v[2];
	soma = v[1] + v[3];
	//Resultados
	printf("\n%d x %d é igual a: %d\n", v[0], v[2], multiplica);
	printf("%d + %d é igual a: %d\n", v[1], v[3], soma);
	
	return 0;
}
