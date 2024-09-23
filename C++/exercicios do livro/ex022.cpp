#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main () {
	float sal, kw_val, kw_quant, pag, desc;
	
	//Configurar todas as variaveis para terem duas casas decimais de uma vez
	std::cout << std::fixed << std::setprecision(2);
	
	cout << "Qual eh o valor do salario minimo atualmente? R$ ";
	cin >> sal;
	cout << "E quantos quilowatts foram consumidos? ";
	cin >> kw_quant;
	kw_val = sal/5;
	pag = kw_val * kw_quant;
	desc = pag * 0.85;
	cout << "O valor, em reais, de 1 quilowatt, eh de R$ " << kw_val << ", o valor a ser pago pela residencia eh de R$ " << pag << " e com desconto de 15% eh igual a R$ " << desc;
}
