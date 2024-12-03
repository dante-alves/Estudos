#include <stdio.h>
#include <stdlib.h>

//Aula 153: Fun��es e Procedimentos Recursivos -> Fun��o ou procedimento recursivo � aquele que chama a si mesmo na execu��o.
//Exemplo: imprimir todos os n�meros de n at� 0
	
//Procedimento para imprimir os n�meros 
void imprimir(int n) {
	
	//Recurs�o EM ORDEM DECRESCENTE
	if(n == 0)	//Qual � o ponto de parada?
		printf("%d ", n); 
	else{		//N�o � o ponto de parada, ent�o resolve uma pequena parte do problema, e chama o procedimento novamente
		printf("%d ", n);
		imprimir(n - 1);
	}
	
	//Recurs�o EM ORDEM CRESCENTE
	if(n == 0)	//Qual � o ponto de parada?
		printf("%d ", n); 
	else{		//N�o � o ponto de parada, ent�o resolve uma pequena parte do problema, e chama o procedimento novamente
		imprimir(n - 1); //S� precisa inverter isso para ficar em ordem crescente. Isso funciona pois todos os n�meros v�o ser empilhados antes de printar um por um em seu procedimento
		printf("%d ", n);
	}
}

int main() {
	int n, i;
	
	printf("Digite um valor maior do que 0: ");
	scanf("%d", &n);
	
	while (n <= 0) {
		printf("Valor inv�lido. Insira um valor MAIOR do que 0: ");
		scanf("%d", &n);
	}
	
	//Procedimento para imprimir os n�meros
	imprimir(n);
	
	return 0;
}
