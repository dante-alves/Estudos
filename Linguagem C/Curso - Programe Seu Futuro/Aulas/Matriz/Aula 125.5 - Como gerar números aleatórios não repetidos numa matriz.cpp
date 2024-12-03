#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Como gerar números aleatórios não repetidos numa matriz

void bubbleSort(int m[5][3], int tamL, int tamC){
	int i, troca, aux;
	int total = tamL * tamC;//A forma mais fácil, é transformar a matriz numa sequência linear de números, e não dividida em linhas e colunas, por isso calcula o total de valores
	
	do{
		troca = 0;
		
		for(i = 0; i < total - 1; i++){
			
			//Definir as posições de cada valor na matriz --> Cada valor de linha e coluna vai ser baseado em i, que começa em 0 e vai até o último valor da matriz
			int l1 = i / tamC;
			int c1 = i % tamC;
			int l2 = (i + 1) / tamC;
			int c2 = (i + 1) % tamC;
			
			if(m[l1][c1] > m[l2][c2]){
				aux = m[l1][c1];
				m[l1][c1] = m[l2][c2];
				m[l2][c2] = aux;
				
				troca = 1;
			}
		}
	}while(troca);
}

int main(){
	int m[5][3];
	int i, j, atribui, l, c, aux;
	
	srand(time(NULL));
	
	i = j = 0;
	
	do{
		atribui = 1;
		
		aux = rand() % 100;
		
		for(l = 0; l < 5; l++){
			for(c = 0; c < 3; c++){
				if(m[l][c] == aux){
					atribui = 0;
				}
			}
		}
	
		if(atribui == 1){
			m[i][j] = aux; 
			
			j++;
			
			if(j == 3){
				i++;
				j = 0;
			}
		}
	}while(i < 5);
	
	bubbleSort(m, 5, 3);
	
	for(l = 0; l < 5; l++){
			for(c = 0; c < 3; c++){
				printf("%d ", m[l][c]);
			}
		}
}
