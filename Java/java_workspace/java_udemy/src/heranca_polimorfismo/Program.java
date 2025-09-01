package heranca_polimorfismo;

import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;
import java.util.List;
import java.util.Locale;
import java.util.Scanner;

public class Program {

	public static void main(String[] args) {
//		Account acc = new Account(1001, "Alex", 0.0);
//		BusinessAccount bacc = new BusinessAccount(1002, "Maria", 0.0, 500.0);
//		
//		// UPCASTING
//		
//		Account acc1 = bacc;
//		Account acc2 = new BusinessAccount(1003, "Bob", 0.0, 200.0);
//		Account acc3 = new SavingsAccount(1004, "Ana", 0.0, 0.01);
//		
//		// DOWNCASTING
//		
//		BusinessAccount acc4 = (BusinessAccount)acc2;
//		acc4.loan(100.0);
//		
//		// BusinessAccount acc5 = (BusinessAccount)acc3; ----> Nesse caso só vai dar erro quando executar o programa
//		
//		// como impedir o erro
//		if (acc3 instanceof BusinessAccount) {
//			BusinessAccount acc5 = (BusinessAccount)acc3;
//			acc5.loan(200.0);
//			System.out.println("Loan!");
//		}
//		
//		if (acc3 instanceof SavingsAccount) {
//			SavingsAccount acc5 = (SavingsAccount)acc3;
//			acc5.updateBalance();
//			System.out.println("Update!");
//		}
//		
//		// POLIMORFISMO
//		Account x = new Account(1020, "Dante", 1000.0);
//		Account y = new SavingsAccount(1023, "Maria", 1000.0, 0.1);
//		
//		x.withdraw(50.0);
//		y.withdraw(50.0);
//		
//		System.out.println(x.getBalance());
//		System.out.println(y.getBalance());
		Program.ex03();
	}
	
	public static void ex01() {
		Locale.setDefault(Locale.US);
		Scanner sc = new Scanner(System.in);
		
		System.out.print("Enter the number of employees: ");
		int n = sc.nextInt();
		sc.nextLine();
		
		List<Employee> list = new ArrayList<>();
		
		for(int i = 0; i < n; i++) {
			System.out.println("\033[1mEmployee #" + (i+1) +" data:\033[0m");
			System.out.print("Outsourced (y/n)? ");
			String answer = sc.nextLine();
			
			System.out.print("Name: ");		
			String name = sc.nextLine();
			System.out.print("Hours: ");
			int hours = sc.nextInt();
			sc.nextLine();
			
			System.out.print("Value per hour: ");
			double valuePerHour = sc.nextDouble();
			sc.nextLine();
			double additionalCharge;
			
			if(answer.charAt(0) == 'y') {
				System.out.print("Additional charge: ");
				additionalCharge = sc.nextDouble();
				sc.nextLine();
				
				list.add(new OutsourcedEmployee(name, hours, valuePerHour, additionalCharge));
			}
			else
				list.add(new Employee(name, hours, valuePerHour));
			
		}
		
		// PAYMENTS
		System.out.println("\nPAYMENTS:");
		
		for (Employee employee : list) 
			System.out.println(employee.getName() + " - $ " + employee.payment());
		
		sc.close();
	}
	
	public static void ex02() {
		Locale.setDefault(Locale.US);
		Scanner sc = new Scanner(System.in);
		
		System.out.print("Enter the number of products: ");
		int n = sc.nextInt();
		sc.nextLine();
		
		List<Product> products = new ArrayList<>();
		
		for (int i = 1; i <= n; i++) {
			System.out.println("Product #" + i +" data:");
			
			products.add(getProductData());
			}
		
		System.out.println("\nPRICE TAGS:");
		for (Product p : products) {
			System.out.println(p.priceTag());
		}
		
		sc.close();
			
	}
	public static Product getProductData() {
		Locale.setDefault(Locale.US);
		Scanner sc = new Scanner(System.in);
		
		System.out.print("Common, used or imported (c/u/i)? ");
		char ch = sc.next().charAt(0);
		sc.nextLine();
		
		System.out.print("Name: ");
		String name = sc.nextLine();
		
		System.out.print("Price: ");
		double price = sc.nextDouble();
		sc.nextLine();
		
		if (ch == 'u') {
			System.out.print("Manufacture date (DD/MM/YYYY): ");
			DateTimeFormatter fmt01 = DateTimeFormatter.ofPattern("dd/MM/yyyy");
			LocalDate date  = LocalDate.parse(sc.nextLine(), fmt01);
			
			return new UsedProduct(name, price, date);
		}
		
		if (ch == 'i') {
			System.out.print("Customs fee: ");
			double customsFee = sc.nextDouble();
			sc.nextLine();
			return new ImportedProduct(name, price, customsFee);
		}
		
		return new Product(name, price);
	}
	
	public static void ex03() {
		Locale.setDefault(Locale.US);
		Scanner sc = new Scanner(System.in);
		
		List<TaxPayer> list = new ArrayList<>();
		
		System.out.print("Enter the number of tax players: ");
		int n = sc.nextInt();
		
		
		for (int i = 1; i <= n; i++) {
			System.out.printf("Tax payer #%d data:\n", i);
			System.out.print("Individual or company (i/c)? ");
			char type = sc.next().charAt(0);
			sc.nextLine();
			
			System.out.print("Name: ");
			String name = sc.nextLine();
			
			System.out.print("Anual income: ");
			double anualIncome = sc.nextDouble();
			sc.nextLine();
			
			if (type == 'i') {
				System.out.print("Health expenditures: ");
				double healthExpenditures = sc.nextDouble();
				sc.nextLine();
				
				list.add(new Individual(name, anualIncome, healthExpenditures));
			}
			
			else {
				System.out.print("Number of employees: ");
				int numberOfEmployees = sc.nextInt();
				sc.nextLine();
				
				list.add(new Company(name, anualIncome, numberOfEmployees));
			}
		}
		
		System.out.println("\nTAXES PAID:");
		for (TaxPayer payer : list) {
			System.out.println(payer);
		}
		
		double total = 0;
		for (TaxPayer payer : list) {
			total += payer.tax();
		}
		
		System.out.println("TOTAL TAXES: $ " + total);
		sc.close();
	}

}
