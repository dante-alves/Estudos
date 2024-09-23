#include <stdio.h>
#include <locale.h>

int main () {
	setlocale(0, "Portuguese");
	int nasc, idade;
	#define ano 2024
	
	printf ("Em que ano o nadador nasceu? ");
	scanf (" %d", &nasc);
	
	while (nasc < 1954 || nasc >= ano) {
		printf ("Ano inválido. Insira outro ano: ");
		scanf (" %d", &nasc);
	}
	
	idade = ano - nasc;
	
	//COMO FAZER UTILIZANDO IF
	
	/*
	if (idade >= 5 && idade <= 7) {
		printf ("Nadador de %d anos eh da categoria Infantil A.", idade);
	} else if (idade <= 10) {
		printf ("Nadador de %d anos eh da categoria Infantil B.", idade);
	} else if (idade <= 13) {
		printf ("Nadador de %d anos eh da categoria Juvenil A.", idade);
	} else if (idade <= 17) {
		printf ("Nadador de %d anos eh da categoria Juvenil B.", idade);
	} else if (idade > 17) {
		printf ("Nadador de %d anos eh da categoria Senior.", idade);
	} */
	
	//COMO FAZER UTILIZANDO SWITCH CASE

	 switch (idade) {
		case 5:
		case 6:
		case 7:
			printf ("Nadador de %d anos eh da categoria Infantil A.", idade);
			break;
		case 8:
		case 9:
		case 10:
			printf ("Nadador de %d anos eh da categoria Infantil B.", idade);
			break;
		case 11:
		case 12:
		case 13:
			printf ("Nadador de %d anos eh da categoria Juvenil A.", idade);
			break;
		case 14:
		case 15:
		case 16:
		case 17:
			printf ("Nadador de %d anos eh da categoria Juvenil B.", idade);
			break;
		default:
			printf ("Nadador de %d anos eh da categoria Senior.", idade);
			break;	
	} 
	
}



