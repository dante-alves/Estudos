#include <stdio.h>
#include <string.h>

int main () {
	int c = 0;
	char frase[100] = "Eu nao vou mais jogar avioezinhos de papel na sala de aula.\n";
	
	//Utilizando FOR 
	for (c = 0; c < 500; c++)
	{
		printf ("%s", frase);
	}
	
	/*Utilizando WHILE
	while (c < 500) 
	{
		printf ("%s", frase);
		c++;
	}*/
	
	/*Utilizando DO WHILE
	do 
	{
		printf ("%s", frase);
		c++;
	} while (c < 500); */
}
