#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//EX06 - Múltiplos de 7

int main () {
	int i;
	
	for (i = 7; i <= 9999; i += 7) {
		printf ("%d\n", i);
	}
}
