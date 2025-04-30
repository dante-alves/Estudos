package introducao_poo;

public class Employee {
	
	String name;
	double grossSalary;
	double tax;
	
	public double netSalary() {
		
		return grossSalary - tax;
	}
	
	public void increaseSalary(double percentage) {
		
		grossSalary += (grossSalary * percentage/100);
	}
	
	public String toString() {
		
		return name
				+ String.format(", $%.2f", netSalary());
	}
}
