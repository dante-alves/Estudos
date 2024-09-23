#include <iostream>
#include <iomanip>
using namespace std;

int main () {
	float n1, n2, n3, mp;
	int p1, p2, p3;
	//Utilizando cout << e cin >>
	cout << "Insira o valor da NOTA 1: ";
	cin >> n1;
	cout << "Insira o PESO da NOTA 1: ";
	cin >> p1;
	cout << "Insira o valor da NOTA 2: ";
	cin >> n2;
	cout << "Insira o PESO da NOTA 2: ";
	cin >> p2;
	cout << "Insira o valor da NOTA 3: ";
	cin >> n3;
	cout << "Insira o PESO da NOTA 3: ";
	cin >> p3;
	mp = (n1*p1 + n2*p2 + n3*p3) / (p1 + p2 + p3);
	cout << "A Media Ponderada do aluno foi de: " << std::fixed << std::setprecision(2) << mp << std::endl;
	//Utilizando printf e scanf
	printf ("Insira o valor da NOTA 1: ");
	scanf ("%f", &n1);
	printf ("Insira o PESO da NOTA 1: ");
	scanf ("%d", &p1);
	printf ("Insira o valor da NOTA 2: ");
	scanf ("%f", &n2);
	printf ("Insira o PESO da NOTA 2: ");
	scanf ("%d", &p2);
	printf ("Insira o valor da NOTA 3: ");
	scanf ("%f", &n3);
	printf ("Insira o PESO da NOTA 3: ");
	scanf ("%d", &p3);
	mp = (n1*p1 + n2*p2 + n3*p3) / (p1 + p2 + p3);
	printf ("A Media Ponderada do aluno foi de: %.2f", mp);
}
