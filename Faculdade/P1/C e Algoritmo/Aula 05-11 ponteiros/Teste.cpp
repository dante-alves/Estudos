#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	char nome[] = {"Dante"};
	char *p_nome = nome;
	
	printf("%c", *p_nome);
	printf("%s", p_nome);
	return 0;
}
