package heranca_polimorfismo;

public class Product {
	private String name;
	private double price;
	
	public Product() {
	}
	
	public Product(String name, double price) {
		super();
		this.name = name;
		this.price = price;
	}

	public double getPrice() {
		return price;
	}

	public void setPrice(double price) {
		this.price = price;
	}

	public String getName() {
		return name;
	}
	
	public String priceTag() {
		return name + " $ " + price; 
	}
	
	
}
