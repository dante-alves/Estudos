package entities;

public class Product {
	
	private String name;
	private double price;
	
	// construtores
	public Product() {
	}


	public Product(String name, double price) {
		super();
		this.name = name;
		this.price = price;
	}
	
	// getters e setters (encapsulamento)
	public String getName() {
		return name;
	}
	
	public void setName(String name) {
		this.name = name;
	}
	
	public double getPrice() {
		return price;
	}
	
	public void setPrice(double price) {
		this.price = price;
	}

	
}
