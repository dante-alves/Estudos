#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
	int main () {
	double area, R, D;
	cout << "Qual e o diametro do circulo? ";
	cin >> D;
	R = D/2;
	area = 3.14 * pow(R,2);
	cout << "A area do circulo e igual a: " << std::fixed << std::setprecision(3) << area << std::endl;
	
	printf ("Qual e o diametro do circulo? ");
	scanf ("%lf", &D);
	R = D/2;
	area = 3.14 * pow(R,2);
	printf ("A area do circulo e igual a: %.3lf\n", area);
}

