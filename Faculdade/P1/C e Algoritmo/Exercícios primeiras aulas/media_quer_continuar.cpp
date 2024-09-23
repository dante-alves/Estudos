#include <stdio.h>
#include <string.h>

//Calcular a media de um aluno com duas notas e perguntar se quer fazer outra conta.

int main () {
	float n1, n2, m;
	char res[2];
	
	do {
		printf ("Primeira nota: ");
		scanf (" %f", &n1); //Um espacinho antes de cada %f para limpar o buffer
		printf ("Segunda nota: ");
		scanf (" %f", &n2);
		m = (n1 + n2) / 2; //Calculo da media
		
		printf ("Com as notas %.1f e %.1f, o aluno tirou %.1f\n", n1, n2, m);
		printf ("Quer continuar? (s/n) ");
		scanf (" %s", res); //Um espacinho também
	} while (strcmp(res,"s") == 0); //strcmp é usado para comparar string com valores, no caso enquanto res == s for falso (0), ele continua repetindo o código.
	
	return 0;
}
