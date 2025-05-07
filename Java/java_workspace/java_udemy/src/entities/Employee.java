package entities;

public class Employee {
	private int id;
	private String name;
	private double salary;
	
	public Employee(int id, String name, double salary) {
		this.id = id;
		this.name = name;
		this.salary = salary;
	}

	public int getId() {
		return id;
	}

	public void setId(int id) {
		this.id = id;
	}

	public double getSalary() {
		return salary;
	}

	public void setSalary(double salary) {
		this.salary = salary;
	}

	public String getName() {
		return name;
	}
	
	public void salaryIncrease(double percentage) {
		salary += salary * (percentage/100);
	}
	
	public String toString() {
		return id
				+ ", "
				+ name
				+ " "
				+ salary;
	}
}
