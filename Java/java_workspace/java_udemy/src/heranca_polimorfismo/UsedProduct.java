package heranca_polimorfismo;

import java.time.LocalDate;
import java.time.format.DateTimeFormatter;

public class UsedProduct extends Product{
	private static DateTimeFormatter dateFormatter = DateTimeFormatter.ofPattern("dd/MM/yyyy");
	private LocalDate manufactureDate;
	
	public UsedProduct() {
	}

	public UsedProduct(String name, double price, LocalDate manufactureDate) {
		super(name, price);
		this.manufactureDate = manufactureDate;
	}

	public LocalDate getManufactureDate() {
		return manufactureDate;
	}

	public void setManufactureDate(LocalDate manufactureDate) {
		this.manufactureDate = manufactureDate;
	}
	
	public String priceTag() {
		return super.getName() + " $ " + super.getPrice() + " (Manufacture date: " + dateFormatter.format(manufactureDate) + ")";
	}
	
}
