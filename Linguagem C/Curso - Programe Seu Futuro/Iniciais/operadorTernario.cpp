#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
//Uso do operador ternario
int main () {
	
	float nota;
	
	setlocale (LC_ALL, "Portuguese");
	printf ("Qual foi a nota do aluno? ");
	scanf ("%f", &nota);
	nota < 7 ? printf ("Reprovado") : printf ("Aprovado!"); // condi��o ? comando para true : comando para false
	
	// Tern�rio aninhado
	nota < 1 ? printf ("Aluno Reprovado") : nota > 1 && nota < 7 ? printf ("Aluno em Final") : printf ("Aluno Aprovado!");
}
