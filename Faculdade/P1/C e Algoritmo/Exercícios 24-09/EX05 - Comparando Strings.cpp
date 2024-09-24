#include <stdio.h>
#include <string.h>
#include <locale.h>

//EX05 Comparando strings

int main () {
	setlocale(LC_ALL, "Portuguese");
	char p1[256], p2[256];
	
	printf("Insira a primeira palavra: ");
	scanf("%s", p1);

	printf("Insira a segunda palavra: ");
	scanf("%s", p2);
	
	if (strcmp(p1, p2) == 0) 
		printf("As palavras são iguais.");
	else if (strcmp(p1, p2) < 0)
		printf("%s é menor do que %s", p1, p2);
	else 
		printf("%s é maior do que %s", p1, p2);
}
