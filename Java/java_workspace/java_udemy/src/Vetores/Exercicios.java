package Vetores;

import java.util.Locale;
import java.util.Scanner;

import entities.Product;

public class Exercicios {

	public static void main(String[] args) {
		Locale.setDefault(Locale.US);	
		
		Exercicios.example02();
	}
	
	public static void example01() {
		
		Scanner scan = new Scanner(System.in);
		
		System.out.print("How many persons do you want to know the height? ");
		int n = scan.nextInt();
		
		double[] height = new double[n];
		double mediumHeight = 0;
		
		for (int i = 0; i < n; i++) {
			System.out.printf("%dº height: ", i+1);
			height[i] = scan.nextDouble();
			mediumHeight += height[i];
		}
		
		 mediumHeight /= n;
		 
		 
		 for (int i = 0; i < n; i++) {
				System.out.printf("%dº height: %.2f\n", i+1, height[i]);
		}
		 System.out.printf("\nMedium Height: %.2f\n", mediumHeight);
		
		scan.close();
	}
	
	public static void example02() {
		Scanner sc = new Scanner(System.in);
		
		System.out.print("How many products? ");
		int n = sc.nextInt();
		
		
		Product[] product = new Product[n];
		
		for (int i = 0; i < n; i++) {
			sc.nextLine();
			System.out.print("Product name: ");
			String name = sc.nextLine();
			
			System.out.print("Product price: ");
			double price = sc.nextDouble();
			
			product[i] = new Product(name, price);
		}
		
		double averagePrice = 0;
		
		for (int i = 0; i < n; i++) {
			averagePrice += product[i].getPrice();
		}
		
		averagePrice /= n;
		
		System.out.printf("\nAVERAGE PRICE: %.2f\n", averagePrice);
		
		sc.close();
	}

}
