package introducao_poo;

public class Rectangle {
	public double width;
	public double height;
	
	
	public double area() {
		
		return width * height;
	}
	
	public double perimeter() {
		
		return (width * 2) + (height * 2);
	}
	
	public double diagonal() {
		
		return Math.sqrt(Math.pow(width, 2) + Math.pow(height, 2));
	}
	
	public String toString() {
		return "\nAREA = "
				+ String.format("%.2f", area())
				+ "\nPERIMETER = "
				+ String.format("%.2f", perimeter())
				+ "\nDIAGONAL = "
				+ String.format("%.2f", diagonal());
	}
}
