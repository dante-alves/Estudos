package introducao_poo;

import java.util.Locale;
import java.util.Scanner;

public class TrianguloSemObjeto {

	public static void main(String[] args) {
		
		Locale.setDefault(Locale.US);
		Scanner scan = new Scanner(System.in);
		
		double xA, xB, xC, yA, yB, yC;
		
		System.out.print("Insira as medidas do triângulo X: ");
		xA = scan.nextDouble();
		xB = scan.nextDouble();
		xC = scan.nextDouble();
		
		double p = (xA + xB + xC) / 2.0;
		double areaX = Math.sqrt(p * (p - xA) * (p - xB) * (p - xC));
		
		
		System.out.print("Insira as medidas do triângulo Y: ");
		yA = scan.nextDouble();
		yB = scan.nextDouble();
		yC = scan.nextDouble();
		
		p = (yA + yB + yC) / 2.0;
		double areaY = Math.sqrt(p * (p - yA) * (p - yB) * (p - yC));
		
		
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
