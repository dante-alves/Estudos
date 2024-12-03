#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
	char string1[50] = {"Oi "}, string2[50] = {"Bom dia"}, string3[] = {"dia"};
	
	//Concatenar strcat()
	strcat(string1, string2);
	
	printf("%s", string1);
	
	//Comparar strcmp()
	printf("\n\nResultado: %d\n", strcmp(string1,string2));
	/*
	A fun��o strcmp pode retornar 3 poss�veis valores inteiros:
	0 = se a duas strings s�o iguais;
	-1 = se a primeira string ocorre primeiro que a segunda (alfabeticamente);
	1 = se a segunda string ocorre primeiro que a primeira(alfabeticamente).
	*/
	
	//Copiar strcpy()
	strcpy(string2, string1);
	
	printf("\nString1: %s\nString2: %s", string1, string2);
	printf("\n\nResultado: %d", strcmp(string1,string2)); //Vai retornar 0 agora pois tornaram-se iguais
	
	//AMBAS AS STRINGS VIRARAM "Oi Bom dia"
	
	//Procurando caracter 
	//strchr() ---> Retorna a primeira ocorr�ncia do caracter na string
	//strrchr() ---> Retorna a �ltima ocorr�ncia do caracter na string
	
	char *letra; //Vai armazenar um ponteiro para um caracter
	
	letra = strchr(string1, 'O');
	printf("\n\n%c\n", *letra);
	printf("%c\n", *(letra + 1)); // *(letra + 1) indica o endere�o seguinte ap�s o ponteiro 'O', que no caso � o 'i'
	printf("%c\n", *(letra + 3));
	
	//Como encontrar uma substring dentro de uma string com a fun��o strstr()
	//string1 == Oi Bom dia
	//string3 == dia
	//OBS: Se n�o tiver a substring procurada na string, a fun��o vai retornar o valor NULL
	letra = strstr(string1, string3);
	printf("\n%c", *letra);
	printf("\n%s", letra);
	
	
	//Colocar para mai�sculo ou min�sculo com strupr() e strlwr;
	
	strupr(string2);
	printf("\n\nEm maiusculo: %s", string2);
	strlwr(string2);
	printf("\n\nEm minusculo: %s", string2);
	return 0;
}
