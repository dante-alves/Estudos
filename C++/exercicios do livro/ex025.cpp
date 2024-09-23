#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main () {
	float custo, convite, qtd_conv;
	
	cout << "Qual foi o custo do espetaculo? R$ ";
	cin >> custo;
	cout << "E qual o preco do convite deste espetaculo? R$ ";
	cin >> convite;
	qtd_conv = ceil ((custo/convite));
	cout << "No minimo, precisam ser vendidos " << qtd_conv << " convites para alcancar o custo do espetaculo.";
}
