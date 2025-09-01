package enumerações;

import java.time.Instant;
import java.time.LocalDate;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.Locale;
import java.util.Scanner;

import entities.Client;
import entities.Comment;
import entities.Department;
import entities.HourContract;
import entities.Order;
import entities.OrderItem;
import entities.OrderStatus;
import entities.Post;
import entities.Product;
import entities.Worker;
import entities.WorkerLevel;

public class main {

	public static void main(String[] args) {
//		Order order = new Order(1080, new Date(), OrderStatus.PENDING_PAYMENT);
//
//		System.out.println(order);
//		
//		OrderStatus o1 = OrderStatus.DELIVERED;
//		OrderStatus o2 = OrderStatus.valueOf("DELIVERED"); // passando string para enum
//		
//		System.out.println("o1 = " + o1 + " o2 = " + o2);
		main.ex03();
	}

	public static void ex01() {
		Scanner sc = new Scanner(System.in);
		
		System.out.print("Enter department's name: ");
		Department tempDep = new Department(sc.nextLine());
		
		System.out.println("Enter worker data:");
		System.out.print("Name: ");
		String name = sc.nextLine();
		
		System.out.print("Level: ");
		WorkerLevel level = WorkerLevel.valueOf(sc.nextLine());
		
		System.out.println("Base salary: ");
		double baseSalary = sc.nextDouble();
		
		Worker worker = new Worker(name, level, baseSalary, tempDep);
		
		System.out.println(worker);
		
		System.out.print("How many contracts to this worker? ");
		int n = sc.nextInt();
		
		DateTimeFormatter fmt01 = DateTimeFormatter.ofPattern("dd/MM/yyyy"); // formatar a leitura da data
		
		for (int i = 0; i < n; i++) {
			sc.nextLine();
			
			System.out.println("Enter contract #" + (i+1) + " data");
			System.out.print("Date (DD/MM/YYYY): ");
			LocalDate date = LocalDate.parse(sc.nextLine(), fmt01);
			
			System.out.print("Value per hour: ");
			double value = sc.nextDouble();
			
			System.out.print("Duration (hours): ");
			int hours = sc.nextInt();
			
			worker.addContract(new HourContract(date, value, hours));
		}
		
		System.out.println(worker);
		sc.nextLine();
		
		System.out.print("Enter month and year to calculate income (MM/YYYY): ");
		String input = sc.nextLine();
		
		String[] parts = input.split("/");
		
		int month = Integer.parseInt(parts[0]);
		int year = Integer.parseInt(parts[1]);
		
		System.out.println("Name: " + worker.getName() 
						+ "\nDepartment: " + worker.getDepartment().getName() 
						+ "\nIncome for " + input + ": " + worker.income(year, month));
		
		sc.close();
	}
	
	public static void ex02() {
		Locale.setDefault(Locale.US);
		
		Post p1 = new Post(Instant.parse("2018-06-21T13:05:44Z"), "Traveling to New Zealand", "I'm going to visit this wonderful country!", 12);
		p1.addComment(new Comment("Have a nice trip"));
		p1.addComment(new Comment("Wow that's aweseome!"));
		
		Post p2 = new Post(Instant.parse("2018-07-28T23:14:19Z"), "Good night guys", "See you tomorrow", 5);
		p2.addComment(new Comment("Good night"));
		p2.addComment(new Comment("May the Force be with you"));
		
		System.out.println(p1);
		
		System.out.println(p2);
	}
	
	public static void ex03() {
		Locale.setDefault(Locale.US);
		Scanner sc = new Scanner(System.in);
		
		System.out.println("Enter client data:");
		System.out.print("Name: ");
		String name = sc.nextLine();
		
		System.out.print("Email: ");
		String email = sc.nextLine();
		
		DateTimeFormatter fmt01 = DateTimeFormatter.ofPattern("dd/MM/yyyy");
		System.out.print("Birth Date(DD/MM/YYYY): ");
		LocalDate date = LocalDate.parse(sc.nextLine(), fmt01);
		
		
		Client newClient = new Client(name, email, date);
		
		System.out.println("Enter order data:");
		System.out.print("Status: ");
		OrderStatus status = OrderStatus.valueOf(sc.nextLine());
		
		LocalDateTime orderMoment = LocalDateTime.now();
		
		Order order = new Order(1, orderMoment, status, newClient);

		System.out.print("How many items to this order? ");
		int itemsQuantity = sc.nextInt();
		sc.nextLine();
		
		
		for (int i = 0; i < itemsQuantity; i++) {
			System.out.println("Enter #" + (i+1) + " item data:");
			System.out.print("Product name: ");
			String productName = sc.nextLine();
			
			System.out.print("Product price: ");
			double productPrice = sc.nextDouble();
			sc.nextLine();
			
			System.out.print("Product Quantity: ");
			int productQuantity = sc.nextInt();
			sc.nextLine();
			
			Product product = new Product(productName, productPrice);
			
			order.addItem(new OrderItem(productQuantity, product.getPrice(), product));
		}
		
		
		System.out.println(order);
		
		sc.close();
	}
}
