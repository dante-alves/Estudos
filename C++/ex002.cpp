#include <stdio.h>

int main () {
	int i;
	float r;
	char s;
	
	printf("Digite um valor inteiro:\n");
	scanf("%d", &i);
	getchar();
	printf("Agora, digite um valor real:\n");
	scanf("%f", &r);
	getchar();
	printf("Os numeros escolhidos foram %d e %f\n", i, r);
	getchar();
}
