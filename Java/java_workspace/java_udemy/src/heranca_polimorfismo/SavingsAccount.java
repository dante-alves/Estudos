package heranca_polimorfismo;

public final class SavingsAccount extends Account{

	private double interestRate;
	
	public SavingsAccount() {
		super();
	}

	public SavingsAccount(int number, String holder, double balance, double interestRate) {
		super(number, holder, balance);
		this.interestRate = interestRate;
	}

	public double getInterestRate() {
		return interestRate;
	}

	public void setInterestRate(double interestRate) {
		this.interestRate = interestRate;
	}
	
	@Override
	public final void withdraw(double amount) { // o final no método impede que o método possa ser sobreposto por uma subclasse de SavingsAccount
		balance -= amount;
	}
	
	public void updateBalance() {
		balance += balance * interestRate;
	}
}
