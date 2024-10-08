#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h> //PRECISA DESSA PARA PASSAR A HORA DO PC

// Aula 103 e 104 - Como gerar números aleatórios para preencher um vetor: funções rand () e srand ()

int main () {
	setlocale(LC_ALL, "Portuguese");
	
	int num2[10], i;
	
	srand(time(NULL)); //coloca o srand() para determinar a seed que o rand() vai iniciar, e time(NULL) para utilizar a hora do computador como parâmetro
	
	for(i = 0; i < 10; i++){
		num2[i] = rand() % 100; // o rand() não é realmente random, mas ele utiliza seeds, por isso, para determinar as seeds (cada valor), utiliza srand().
	}
	for (i = 0; i < 10; i++)
		printf ("\n%d", num2[i]);
	
	return 0;
}

//Para definir um intervalo entre 0 e 99, por exemplo, é possível fazer num2[i] = rand() % 100;
