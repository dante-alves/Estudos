#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*EX08 - O máximo divisor comum dos inteiros x e y é o maior inteiro que é divisível por x e
y. Escreva uma função recursiva mdc em C, que retorna o máximo divisor comum de x
e y. O mdc de x e y é definido como segue: se y é igual a 0, então mdc(x,y) é x; caso
contrário, mdc(x,y) é mdc (y, x%y), onde % é o operador resto.*/

//Função que retorna o máximo divisor comum entre dois inteiros 
int mdc(int n1, int n2){
	//Se o resto da divisão do maior valor pelo menor for 0, então o menor valor é o máximo divisor comum. Se não, tem que dividir o menor valor pelo resto da divisão até chegar ao resto 0. 
	if(n2 == 0)
		return n1;
	else 
		return mdc(n2, n1 % n2);
}

int main(){
	int x, y;
	
	printf("Digite o valor de x e y: ");
	scanf("%d%d", &x, &y);
	
	printf("O máximo divisor comum de %d e %d é: %d", x, y, mdc(x, y));
	
	return 0;
}
