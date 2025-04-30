package construtores_sobrecarga_encapsulamento;

import java.util.Locale;
import java.util.Scanner;

import entities.Product;

public class Construtores {
	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		Scanner scan = new Scanner(System.in);
		
		System.out.print("Enter product data:\nName: ");
		
		String name = scan.nextLine();
		
		System.out.print("Price: ");
		double price = scan.nextDouble();
		
		System.out.print("Quantity in stock: ");
		int quantity = scan.nextInt();
		
		Product product = new Product(name, price, quantity);

		System.out.println(product);
		
		System.out.print("Enter the number of products to be added in stock: ");
		
		int quant = scan.nextInt();
		
		product.addProducts(quant);
		
		System.out.println("\nUpdated data: " + product);
		
		System.out.print("Enter the number of products to be removed in stock: ");
		
		quant = scan.nextInt();
		
		product.removeProducts(quant);
		
		System.out.println("\nUpdated data: " + product);
		
		// testando setters e getters
		product.setName("Computer");
		product.setPrice(960.0);
		
		System.out.println("New data: " + product);
		
		scan.close();
	}
}
