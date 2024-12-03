#include <stdio.h>
#include <stdlib.h>

int fatorial(int n){
	if(n == 1){
		return n;
	}
	else{
		return n * fatorial(n - 1);
	}
}

int main(){
	
	int N;
	
	printf("Insira um valor para calcular o fatorial: ");
	scanf("%d", &N);
	
	printf("Resposta: %d", fatorial(N));
	return 0;
}
