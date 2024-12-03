#include <stdio.h>
#include <stdlib.h>

//Aula 190 - Ponteiro para struct

typedef struct{
	int dia, mes, ano;
}Data;

void imprimirData(Data *x){
	printf("%d/0%d/%d\n", x->dia, x->mes, x->ano); //Não usa o ponto para ponteiro, mas sim 0 ->
}

int main(){
	
	Data data;
	Data *p;
	
	p = &data;
		
	printf("Endereco\tdata: %p\tp: %p\n\n", &data, p);
		
	data.dia = 25;
	data.mes = 6;
	data.ano = 2003;
	
	printf("%d/0%d/%d\n", data.dia, data.mes, data.ano);
	
	imprimirData(p);
	
	
	return 0;
}
