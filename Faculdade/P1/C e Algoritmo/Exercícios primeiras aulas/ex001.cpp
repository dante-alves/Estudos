#include <stdio.h>

int main () {
	float n1 = 0, n2 = 0, soma = 0;
	printf ("Primeira Nota: ");
	scanf ("%f", &n1);
	printf ("Segunda Nota: ");
	scanf ("%f", &n2);
	soma = n1+n2;
	printf ("Com as notas %.1f e %.1f o aluno teve soma total de: %.1f \nPortanto, ", n1, n2, soma);
	if (soma > 6.0 && soma <= 10.0) 
	{
		printf ("Aluno APROVADO");
	} 
	else if (soma < 6.0 && soma >= 1.0) 
	{
		printf ("Aluno EM FINAL");
	}
	else if (soma < 1.0)
	{
		printf ("Aluno REPROVADO");
	}
	else 
	{
		printf ("Nota INVALIDA");	
	}
}

