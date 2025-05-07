package Vetores;

import java.util.Locale;
import java.util.Scanner;

import entities.Person;
import entities.Product;
import entities.Rent;

public class Exercicios {

	public static void main(String[] args) {
		Locale.setDefault(Locale.US);	
		
		Exercicios.exPensionato();
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
		
		double sum = 0;
		
		for (int i = 0; i < product.length; i++) {
			sum += product[i].getPrice();
		}
		
		double averagePrice = sum/product.length;
		
		System.out.printf("\nAVERAGE PRICE: %.2f\n", averagePrice);
		
		sc.close();
	}
	
	public static void exProblemaAlturas() {
		Scanner sc = new Scanner(System.in);
		
		System.out.print("How many persons? ");
		int n = sc.nextInt();
		
		Person[] person = new Person[n];
		
		double heightSum = 0;
		int lessThan16 = 0;
		
		for(int i = 0; i < person.length; i++) {
			sc.nextLine();
			
			System.out.printf("%d person data:\n", i+1);
			System.out.print("Name: ");
			String name = sc.nextLine();
			
			System.out.print("Age: ");
			int age = sc.nextInt();
			
			if(age < 16) lessThan16++;
			
			System.out.print("Height: ");
			double height = sc.nextDouble();
			
			heightSum += height;
			
			person[i] = new Person(name, age, height);
		}
		
		double avgHeight = heightSum/person.length;
		
		
		System.out.printf("\nAverage Height: %.2f\n", avgHeight);
		
		System.out.println(lessThan16);
		
		double agePercent = ((double)lessThan16 / person.length) * 100;
		
		if (lessThan16 > 0) {
			
			
			System.out.printf("Persons with less than 16 years: %.1f%%\n", agePercent);
			
			for (int i = 0; i < person.length; i++) {
				if (person[i].getAge() < 16) {
					System.out.println(person[i].getName());
				}
			}
		}
		
		sc.close();
	}
	
	public static void exPensionato() {
		Scanner sc = new Scanner(System.in);
		final int TOTAL_ROOMS = 10;
		
		Rent[] rent = new Rent[TOTAL_ROOMS];
		
		
		System.out.print("How many rooms will be rented? ");
		int rentedRooms = sc.nextInt();
		
		for (int i = 0; i < rentedRooms; i++) {
			System.out.printf("\nRent %d#:\n", i+1);
			sc.nextLine();
			
			System.out.print("Name: ");
			String name = sc.nextLine();
			
			System.out.print("Email: ");
			String email = sc.nextLine();
			
			System.out.print("Room (0 - 9): ");
			int room = sc.nextInt();
			
			rent[room] = new Rent(name, email);
		}
		
		System.out.println("\nBusy rooms:");
		for (int i = 0; i < rent.length; i++) {
			if(rent[i] != null)
				System.out.println(i + ": " + rent[i]);
		}
		
		sc.close();
	}

}
