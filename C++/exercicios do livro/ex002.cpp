#include <iostream>
#include <iomanip>
using namespace std;

int main (){
	float n1, n2, n3, m;
	//UTILIZANDO PRINTF E SCANF
	printf ("Insira as notas do aluno\n");
	printf ("--------------------------\n");
	printf ("Nota 1: ");
	scanf ("%f", &n1);
	printf ("Nota 2: ");
	scanf ("%f", &n2);
	printf ("Nota 3: ");
	scanf ("%f", &n3);
	m = (n1 + n2 + n3)/3;
	printf ("--------------------------\n");
	printf ("A media do aluno foi: %.2f\n", m); 
	
	// UTILIZANDO COUT E CIN
	cout << "Insira as notas do aluno" << std::endl;
	cout << "--------------------------" << std:: endl;
	cout << "Nota 1: ";
	cin >> n1;
	cout << "Nota 2: ";
	cin >> n2;
	cout << "Nota 3: ";
	cin >> n3;
	m = (n1 + n2 + n3)/3;
	cout << "--------------------------" << std::endl;
	cout << "A media do aluno foi: "<< std::fixed << std::setprecision(2) << m; 
}
