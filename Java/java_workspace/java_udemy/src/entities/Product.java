package entities;

public class Product {
	
	private String name;
	private double price;
	private int quantity;
	
	// construtores
	public Product() {
		
	}
	
	public Product(String name, double price, int quantity) {
		super();
		this.name = name;
		this.price = price;
		this.quantity = quantity;
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
	
	public int getQuantity() {
		return quantity;
	}

	// métodos criados
	public double totalValueinStock() {
		
		return price * quantity;
	}
	
	public void addProducts(int quantity) {
		
		this.quantity += quantity;
	}
	

	public void removeProducts(int quantity) {
		
		if ((this.quantity - quantity) < 0) {
			System.out.println("Quantidade atual menor do que a desejada a ser removida. Removendo " + this.quantity + " unidades...");
			this.quantity = 0;
			
			return;
		}
		
		this.quantity -= quantity;
	}
	
	// transformar a identificação do objeto em string.
	public String toString() {
		return name
				+ ", $"
				+ String.format("%.2f", price)
				+ ", "
				+ quantity 
				+ " units, Total: $"
				+ String.format("%.2f", totalValueinStock());
	}
	
}
