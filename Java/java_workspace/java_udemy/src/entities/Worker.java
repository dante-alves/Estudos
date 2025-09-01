package entities;

import java.util.ArrayList;
import java.util.List;

public class Worker {
	private String name;
	private WorkerLevel level;
	private Double baseSalary;
	
	private Department department;
	
	private List<HourContract> contracts = new ArrayList<>();
	
	public Worker() {
	}
	
	public Worker(String name, WorkerLevel level, double baseSalary, Department department) {
		super();
		this.name = name;
		this.level = level;
		this.baseSalary = baseSalary;
		this.department = department;
	}

	@Override
	public String toString() {
		return "Worker [name=" + name + ", level=" + level + ", baseSalary=" + baseSalary + ", department=" + department.getName()
				+ ", contracts=[" + showContracts() + "]";
	}

	public String showContracts() {
		String contractsList = "";
		
		for(HourContract contract: contracts) {
			contractsList += "\nDate: " + contract.getDate() 
						+ ", Value per Hour: " + contract.getValuePerHour() 
						+ ", Duration (hours): " + contract.getHours();
		}
		
		return contractsList;
	}
	public String getName() {
		return name;
	}

	public Department getDepartment() {
		return department;
	}

	public void setDepartment(Department department) {
		this.department = department;
	}

	public List<HourContract> getContracts() {
		return contracts;
	}

	public void setContracts(List<HourContract> contracts) {
		this.contracts = contracts;
	}

	public void setName(String name) {
		this.name = name;
	}

	public WorkerLevel getLevel() {
		return level;
	}

	public void setLevel(WorkerLevel level) {
		this.level = level;
	}

	public Double getBaseSalary() {
		return baseSalary;
	}

	public void setBaseSalary(Double baseSalary) {
		this.baseSalary = baseSalary;
	}
	
	public void addContract(HourContract contract) {
		contracts.add(contract);
	}
	
	public void removeContract(HourContract contract) {
		contracts.remove(contract);
	}
	
	public double income(int year, int month) {
		
		double sum = baseSalary;
		
		for (HourContract contract: contracts) {
			if (contract.getMonth() == month && contract.getYear() == year)
				sum += contract.totalValue();
		}
		
		return sum;
	}
}
