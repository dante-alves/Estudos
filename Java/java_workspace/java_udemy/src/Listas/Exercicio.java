package Listas;

import java.util.ArrayList;
import java.util.List;
import java.util.Locale;
import java.util.Scanner;

import entities.Employee;

public class Exercicio {

	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		Scanner sc = new Scanner(System.in);
		
		List<Employee> list = new ArrayList<Employee>();
		
		
		
		char opc;
		int i = 1;
		
		do {
			System.out.printf("\nEmployee #%d\n", i);
			System.out.print("Id: ");
			int id = sc.nextInt();
			
			sc.nextLine();
			
			System.out.print("Name: ");
			String name = sc.nextLine();
			
			
			System.out.print("Salary: ");
			double salary = sc.nextDouble();
			
			
			list.add(new Employee(id, name, salary));
			
			System.out.print("Register another employee [y%/n]?");
			opc = sc.next().charAt(0);
			i++;
		} while(opc == 'y');
		
		System.out.print("Enter the employee id that will have salary increase: ");
		int id = sc.nextInt();
		
		boolean found = false;
		int index = 0;
		
		//Employee emp = list.stream().filter(x -> x.getId() == id).findFirst().orElse(null);
		for (i = 0; i < list.size(); i++) {
			if (list.get(i).getId() == id) {
				found = true;
				index = i;
				break;
			}
		}
		
		if (found == false) {
			System.out.println("Id not found.");
		}
		else {
			System.out.print("Enter the percentage: ");
			double percentage = sc.nextDouble();
			
			list.get(index).salaryIncrease(percentage);
		}
		
		System.out.println("\nList of employees: ");
		for (Employee employee : list) {
			System.out.println(employee);
		}
		
	}

}
