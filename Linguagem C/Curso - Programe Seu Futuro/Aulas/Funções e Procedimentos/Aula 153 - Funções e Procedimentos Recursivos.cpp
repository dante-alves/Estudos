#include <stdio.h>
#include <stdlib.h>

//Aula 153: Funções e Procedimentos Recursivos -> Função ou procedimento recursivo é aquele que chama a si mesmo na execução.
//Exemplo: imprimir todos os números de n até 0
	
//Procedimento para imprimir os números 
void imprimir(int n) {
	
	//Recursão EM ORDEM DECRESCENTE
	if(n == 0)	//Qual é o ponto de parada?
		printf("%d ", n); 
	else{		//Não é o ponto de parada, então resolve uma pequena parte do problema, e chama o procedimento novamente
		printf("%d ", n);
		imprimir(n - 1);
	}
	
	//Recursão EM ORDEM CRESCENTE
	if(n == 0)	//Qual é o ponto de parada?
		printf("%d ", n); 
	else{		//Não é o ponto de parada, então resolve uma pequena parte do problema, e chama o procedimento novamente
		imprimir(n - 1); //Só precisa inverter isso para ficar em ordem crescente. Isso funciona pois todos os números vão ser empilhados antes de printar um por um em seu procedimento
		printf("%d ", n);
	}
}

int main() {
	int n, i;
	
	printf("Digite um valor maior do que 0: ");
	scanf("%d", &n);
	
	while (n <= 0) {
		printf("Valor inválido. Insira um valor MAIOR do que 0: ");
		scanf("%d", &n);
	}
	
	//Procedimento para imprimir os números
	imprimir(n);
	
	return 0;
}
