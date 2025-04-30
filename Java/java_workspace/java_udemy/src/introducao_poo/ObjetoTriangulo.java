package introducao_poo;

import java.util.Locale;
import java.util.Scanner;

public class ObjetoTriangulo {

	public static void main(String[] args) {
		
		// a instanciação de objetos faz a alocação dinâmica de memória -> espaço de memória chamado heap
		Triangle x = new Triangle();
		Triangle y = new Triangle();
		// as variáveis x e y estão apontando para o endereço de memória que vai apontar para um objeto Triangle 
		
		
		Locale.setDefault(Locale.US);
		Scanner scan = new Scanner(System.in);
		
		
		System.out.print("Insira as medidas do triângulo X: ");
		x.a = scan.nextDouble();
		x.b = scan.nextDouble();
		x.c = scan.nextDouble();
		
		double areaX = x.area();
		
		
		System.out.print("Insira as medidas do triângulo Y: ");
		y.a = scan.nextDouble();
		y.b = scan.nextDouble();
		y.c = scan.nextDouble();
		
		double areaY = y.area();
		
		
		System.out.printf("Área do triângulo X: %.2f\n", areaX);
		System.out.printf("Área do triângulo Y: %.2f\n", areaY);
		
		if (areaX > areaY) {
			System.out.println("Triângulo X maior do que Y.");
		}
		else {
			System.out.println("Triângulo Y maior do que X.");
		}
		scan.close();

	}
	
}


