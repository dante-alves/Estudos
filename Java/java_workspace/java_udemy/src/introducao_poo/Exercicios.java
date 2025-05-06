package introducao_poo;

import java.util.Locale;
import java.util.Scanner;

import util.CurrencyConverter;

public class Exercicios {

	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		
		exFixacao();
		
	}
	
	public static void ex01() {
		Scanner scan = new Scanner(System.in);
		
		Rectangle rectangle = new Rectangle();
		
		System.out.print("Enter rectangle width and height: ");
		
		rectangle.width = scan.nextDouble();
		rectangle.height = scan.nextDouble();
		
		System.out.println(rectangle); // utilizei o toString
		
		scan.close();
	}
	
	public static void ex02() {
		Scanner scan = new Scanner(System.in);
		
		Employee employee = new Employee();
		
		System.out.print("Name: ");
		employee.name = scan.nextLine();
		
		System.out.print("Gross Salary: ");
		employee.grossSalary = scan.nextDouble();
		
		System.out.print("Tax: ");
		employee.tax = scan.nextDouble();
		
		System.out.println("Employee: " + employee);
		
		System.out.print("Which percentage to increase salary? ");
		double percentage = scan.nextDouble();
		
		employee.increaseSalary(percentage);
		
		System.out.println("Updated data: " + employee);
		
		scan.close();
	}
	
	public static void ex03() {
		Scanner scan = new Scanner(System.in);
		
		Student student = new Student();
		
		System.out.print("Name: ");
		student.name = scan.nextLine();
		
		System.out.print("Grade 1: ");
		student.grade1 = scan.nextDouble();
		
		System.out.print("Grade 2: ");
		student.grade2 = scan.nextDouble();
		
		System.out.print("Grade 3: ");
		student.grade3 = scan.nextDouble();
		
		
		System.out.println(student);
		
		scan.close();
	}

	public static void exFixacao() {
		Scanner scan = new Scanner(System.in);
		
		System.out.print("What is the dollar price? ");
		double dollarPrice = scan.nextDouble();
		
		System.out.print("How many dollars will be bought? ");
		double dollarsBought = scan.nextDouble();
		
		System.out.printf("Amount to be paid in reais = %.2f\n", CurrencyConverter.convertWithIOF(dollarPrice, dollarsBought));
		
		scan.close();
	}
}
