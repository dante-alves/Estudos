#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

union documento{
	char cpf[11];
	char cnpj[14];
};

int main(){
	setlocale(0, "Portuguese");
	
	union documento doc;
	
	printf("Informe um CPF com 11 dígitos: ");
	scanf("%s", &doc.cpf);
	
	printf("CPF: %s\n", doc.cpf);
	
	printf("Informe um CNPJ com 14 dígitos: ");
	scanf("%s", &doc.cnpj);
	
	printf("CNPJ: %s", doc.cnpj);

	return 0;
}
