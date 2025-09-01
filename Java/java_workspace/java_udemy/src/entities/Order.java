package entities;

import java.time.LocalDateTime;
import java.time.ZoneOffset;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;
import java.util.List;

public class Order {
	private static DateTimeFormatter date_timeFormatter = DateTimeFormatter.ofPattern("dd/MM/yyyy HH:mm:ss").withZone(ZoneOffset.UTC);
	private static DateTimeFormatter dateFormatter = DateTimeFormatter.ofPattern("dd/MM/yyyy");
	private Integer id;
	private LocalDateTime moment;
	private OrderStatus status;

	private Client client;
	private List<OrderItem> items = new ArrayList<>();
	
	public Order() {
	}

	public Order(int id, LocalDateTime moment, OrderStatus status, Client client) {
		super();
		this.id = id;
		this.moment = moment;
		this.status = status;
		
		this.client = client;
	}

	public int getId() {
		return id;
	}

	public void setId(int id) {
		this.id = id;
	}

	public LocalDateTime getMoment() {
		return moment;
	}

	public void setMoment(LocalDateTime moment) {
		this.moment = moment;
	}

	public OrderStatus getStatus() {
		return status;
	}

	public void setStatus(OrderStatus status) {
		this.status = status;
	}

	@Override
	public String toString() {
		StringBuilder sb = new StringBuilder();
		sb.append("\nORDER SUMMARY:");
		sb.append("\nOrder moment: " + date_timeFormatter.format(moment));
		sb.append("\nOrder status: " + status);
		sb.append("\nClient: " + client.getName() + " (" + dateFormatter.format(client.getBirthDate()) + ") - " + client.getEmail());
		sb.append("\nOrder items:");
		for (OrderItem item : items) {
			sb.append(item.getProduct().getName() + ", $" + item.getPrice() + ", Quantity: " + item.getQuantity() + ", Subtotal: $" + item.subTotal() + "\n");
		}
		
		sb.append("Total price: $" + this.total());
		
		return sb.toString();
	}
	
	
	public void addItem(OrderItem item) {
		items.add(item);
	}
	
	public void removeItem(OrderItem item) {
		items.remove(item);
	}
	
	public double total() {
		double total = 0;
		
		for (OrderItem item : items) {
			total += item.subTotal();
		}
		
		return total; 
	}
}
