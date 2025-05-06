package introducao_poo;

public class Student {
	
	String name;
	
	double grade1;
	double grade2;
	double grade3;
	
	public double finalGrade() {
		
		return grade1 + grade2 + grade3;
	}
	
	public double missingPoints() {
		if (finalGrade() < 60.00) {
			return 60.00 - finalGrade();			
		}
		
		return 0;
	}
	
	public String toString() {
		
		return "FINAL GRADE = "
				+ String.format("%.2f\n", finalGrade())
				+ ((missingPoints() == 0) ?  "PASS" : ( String.format("FAILED\nMISSING %.2f POINTS", missingPoints())));
	}
}
