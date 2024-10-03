#include <stdio.h>
#include <locale.h>
/*EX05 Planejamento e solu��o
Escreva um programa que leia o valor de 4 n�meros inteiros. Em
seguida, dever� ser apresentado o resultado da multiplica��o do
primeiro n�mero com o terceiro n�mero lido, e a soma do segundo
n�mero com o quarto n�mero lido. A partir do enunciado, fa�a o
planejamento conforme praticado em sala de aula.

Posso fazer com 4 vari�veis tipo int, ou com um vetor. Optei pelo vetor.
Multiplica��o do 1� com o 3�
Soma do 2� com o 4�.
*/

int main() {
	setlocale(0, "Portuguese");
	int v[4], multiplica, soma, i;
	
	//Ler os valores
	for(i = 0; i < 4; i++) {
		printf("Insira um valor: ");
		scanf("%d", &v[i]);
	}
	//C�lculos
	multiplica = v[0] * v[2];
	soma = v[1] + v[3];
	//Resultados
	printf("\n%d x %d � igual a: %d\n", v[0], v[2], multiplica);
	printf("%d + %d � igual a: %d\n", v[1], v[3], soma);
	
	return 0;
}
