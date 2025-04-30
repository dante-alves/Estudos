package construtores_sobrecarga_encapsulamento;

import java.util.Locale;
import java.util.Scanner;

import entities.Account;

public class ExercicioAccount {

	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		
		Scanner scan = new Scanner(System.in);
		
		double value;
		System.out.print("Enter account number: ");
		int number = scan.nextInt();
		
		scan.nextLine();
		System.out.print("Enter account holder: ");
		String name = scan.nextLine();
		
		Account account;
		
		System.out.print("Is there an initial deposit (y/n)? ");
		char option = scan.next().charAt(0); // ler somente o primeiro caractere
		
		if (option == 'y') {
			System.out.print("Enter initial deposit value: ");
			 value = scan.nextDouble();
			account = new Account(number, name, value);
		}
		else {
			account = new Account(number, name);
		}
		
		
		System.out.println("Account data:\n" + account);
		
		System.out.print("Enter a deposit value: ");
		value = scan.nextDouble();
		account.deposit(value);
		
		System.out.println("\nUpdated account data:\n" + account);
		
		System.out.print("Enter a withdraw value: ");
		value = scan.nextDouble();
		account.withdraw(value);
		
		System.out.println("\nUpdated account data:\n" + account);
		scan.close();

	}

}
