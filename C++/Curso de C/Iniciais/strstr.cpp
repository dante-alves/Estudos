#include <stdio.h>
#include <string.h>

int main () {
	char str1[] = "Ol�, mundo!", str2[] = "mundo!";
	char *teste;
	teste = strstr(str1, str2); 
	printf ("%ld", teste - str1);	
}
