package entities;

public class Account {
	
	private final double TAX = 5.0; 
	private int number;
	private String name;
	private double balance;
	
	public Account(int number, String name, double balance) {
		this.number = number;
		this.name = name;
		this.balance = balance;
	}
	
	public Account(int number, String name) {
		this.number = number;
		this.name = name;
	}
	
	public void setName(String name) {
		this.name = name;
	}
	
	public String getName() {
		return name;
	}
	
	public int getNumber() {
		return number;
	}
	
	public double getBalance() {
		return balance;
	}
	
	public void deposit(double value) {
		balance += value;
	}
	
	public void withdraw(double value) {
		balance -= value + 5.0;
	}
	
	
	public String toString() {
		
		return "Account "
				+ number
				+ ", Holder: "
				+ name
				+ ", Balance: $"
				+ String.format("%.2f\n", balance);
	}
}
