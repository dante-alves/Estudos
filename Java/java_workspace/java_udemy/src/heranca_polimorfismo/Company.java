package heranca_polimorfismo;

public class Company extends TaxPayer{
	private int numberOfEmployees;

	public Company() {
	}
	
	
	


	public Company(String name, double anualIncome, int numberOfEmployees) {
		super(name, anualIncome);
		this.numberOfEmployees = numberOfEmployees;
	}





	public int getNumberOfEmployees() {
		return numberOfEmployees;
	}


	public void setNumberOfEmployees(int numberOfEmployees) {
		this.numberOfEmployees = numberOfEmployees;
	}


	@Override
	public double tax() {
		
		if (numberOfEmployees > 10) 
			return super.getAnualIncome() * 0.14;
		
		return super.getAnualIncome() * 0.16;
	}
}
