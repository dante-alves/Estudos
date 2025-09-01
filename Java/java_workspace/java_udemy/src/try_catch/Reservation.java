package try_catch;

import java.time.LocalDate;
import java.time.temporal.ChronoUnit;
import try_catch.DomainException;
public class Reservation {
	private int roomNumber;
	private LocalDate checkin;
	private LocalDate checkout;
	
	public Reservation() {
	}
	
	public Reservation(int roomNumber, LocalDate checkin, LocalDate checkout) {
		LocalDate now = LocalDate.now();
		if (checkin.isBefore(now) || checkout.isBefore(now)) 
			throw new DomainException("Reservation dates for update must be future dates.");
		if (!checkout.isAfter(checkin))
			throw new DomainException("Check-out date must be after check-in date.");
		this.roomNumber = roomNumber;
		this.checkin = checkin;
		this.checkout = checkout;
	}

	public int getRoomNumber() {
		return roomNumber;
	}

	public void setRoomNumber(int roomNumber) {
		this.roomNumber = roomNumber;
	}

	public LocalDate getCheckin() {
		return checkin;
	}

	public LocalDate getCheckout() {
		return checkout;
	}
	
	public int duration() {
		return (int)ChronoUnit.DAYS.between(checkin, checkout);
	}
	
	public void updateDates(LocalDate checkin, LocalDate checkout) {
		LocalDate now = LocalDate.now();
		if (checkin.isBefore(now) || checkout.isBefore(now)) 
			throw new DomainException("Reservation dates for update must be future dates.");
		if (!checkout.isAfter(checkin))
			throw new DomainException("Check-out date must be after check-in date.");
		
		this.checkin = checkin;
		this.checkout = checkout;
	}
	
	@Override
	public String toString() {
		return "Reservation: Room " + roomNumber + ", check-in: " + checkin + ", check-out: " + checkout + ", " + duration() + " nights\n";
	}
}
