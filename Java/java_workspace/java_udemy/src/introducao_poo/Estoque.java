package introducao_poo;

import java.util.Locale;
import java.util.Scanner;

import entities.Product;

public class Estoque {

	public static void main(String[] args) {
		
		
		Locale.setDefault(Locale.US);
		Scanner scan = new Scanner(System.in);
		
		
		System.out.println("Enter product data:");
		System.out.print("Name: ");
		String name = scan.nextLine();
		
		System.out.print("Price: ");
		double price = scan.nextDouble();
		
		System.out.print("Quantity in stock: ");
		int quantity = scan.nextInt();
		
		Product a = new Product(name, price, quantity);
		
		System.out.println("Product data: " + a); // aqui utiliza o método toString()
		
		System.out.print("Enter the number of products to be added in stock: ");
		
		int quant = scan.nextInt();
		
		a.addProducts(quant);
		
		System.out.println("\nUpdated data: " + a);
		
		System.out.print("Enter the number of products to be removed in stock: ");
		
		quant = scan.nextInt();
		
		a.removeProducts(quant);
		
		System.out.println("\nUpdated data: " + a);
		
		
		scan.close();
	}
	
}
