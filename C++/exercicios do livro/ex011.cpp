#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int main () {
	unsigned int n1;
	cout << "Escolha um numero maior que zero: ";
	cin >> n1;
	cout << "O numero " << n1 << " ao quadrado e igual a: " << pow (n1,2) << ", ao cubo, e " << pow (n1,3) << "." << std::endl;
	cout << "Alem disso, a raiz quadrada de " << n1 << " e igual a " << sqrt (n1) << ", e a raiz cubica e " << cbrt (n1) << std::endl;
	
	printf ("Escolha um numero maior que zero: ");
	scanf ("%u", &n1);
	printf ("O numero %u ao quadrado e igual a %.0f, ao cubo e %.0f. \n", n1, pow (n1,2), pow (n1,3));
	printf ("Alem disso, a raiz quadrada de %u e igual a %lf, e a raiz cubica e igual a %lf.", n1, sqrt(n1), cbrt(n1));
}
