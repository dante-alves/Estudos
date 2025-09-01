package try_catch;

import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.time.format.DateTimeParseException;
import java.util.Locale;
import java.util.Scanner;

public class Program {

	public static void main(String[] args) {
//		Scanner sc = new Scanner(System.in);
//		
//		try {
//			int teste = sc.nextInt();	
//		}
//		catch (InputMismatchException e) {
//			System.out.println("Invalid input!");
//		}
//		
//		sc.close();
		
		ex02();
	}
	
	public static void ex01() {
		Locale.setDefault(Locale.US);
		Scanner sc = new Scanner(System.in);
		DateTimeFormatter fmt01 = DateTimeFormatter.ofPattern("dd/MM/yyyy");
		boolean repeat = true;
		
		while(repeat == true) {
			try {
				System.out.print("Room number: ");
				int roomNumber = sc.nextInt();
				sc.nextLine();
				
				System.out.print("Check-in date (DD/MM/YYYY): ");
				LocalDate checkin = LocalDate.parse(sc.nextLine(), fmt01);
				
				System.out.print("Check-out date (DD/MM/YYYY): ");
				LocalDate checkout = LocalDate.parse(sc.nextLine(), fmt01);
				
				Reservation reservation = new Reservation(roomNumber, checkin, checkout);
				
				System.out.println(reservation);
		
				System.out.println("Enter data to update the reservation:");
				System.out.print("Check-in date (DD/MM/YYYY): ");
				checkin = LocalDate.parse(sc.nextLine(), fmt01);
				
				System.out.print("Check-out date (DD/MM/YYYY): ");
				checkout = LocalDate.parse(sc.nextLine(), fmt01);
				
				reservation.updateDates(checkin, checkout);
				
				System.out.println(reservation);
				
				repeat = false;
			}
			catch (DateTimeParseException e) {
				System.out.println("Invalid date format.");
			}
			catch (DomainException e) {
				System.out.println("Error in reservation: " + e.getMessage());
			}
			catch (RuntimeException e) {
				System.out.println("Unexpected error.");
				sc.nextLine();
			}
		}
		sc.close();
	}
	
	public static void ex02() {
		Locale.setDefault(Locale.US);
		Scanner sc = new Scanner(System.in);
		
		try {
			System.out.println("Enter Account Data");
			System.out.print("Number: ");
			int number = sc.nextInt();
			sc.nextLine();
			
			System.out.print("Holder: ");
			String holder = sc.nextLine();
			
			System.out.print("Initial balance: ");
			double balance = sc.nextDouble();
			
			System.out.print("Withdraw limit: ");
			double withdrawLimit = sc.nextDouble();
			
			Account account = new Account(number, holder, balance, withdrawLimit);
			
			System.out.print("\nEnter amount for withdraw: ");
			double amount = sc.nextDouble();
			sc.nextLine();
			
			account.withdraw(amount);
			
			System.out.println("New balance: " + account.getBalance());
		}
		catch (DomainException e) {
			System.out.println(e.getMessage());
		}
		catch (RuntimeException e) {
			System.out.println("Unexpected error!");
		}
		sc.close();
	}

}
