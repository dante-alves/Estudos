package data_hora;

import java.time.Instant;
import java.time.LocalDate;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

public class main {

	public static void main(String[] args) {
		LocalDate date = LocalDate.now();
		LocalDateTime date_hour = LocalDateTime.now();
		Instant date_hour_gmt = Instant.now();
		
		LocalDate string_to_date = LocalDate.parse("2022-07-20");
		Instant string_to_date_gmt = Instant.parse("2022-07-20T01:30:26Z");
		Instant string_to_date_gmt_timezone = Instant.parse("2022-07-20T01:30:26-03:00");
		
		// formatação customizada -> https://docs.oracle.com/en/java/javase/23/docs/api/java.base/java/time/format/DateTimeFormatter.html
		DateTimeFormatter fmt01 = DateTimeFormatter.ofPattern("dd/MM/yyyy");
		LocalDate formated_date = LocalDate.parse("25/06/2003", fmt01);
		
		// outra forma de passar
		LocalDate date02 = LocalDate.of(2003, 6, 25);
		
		System.out.println(fmt01.format(date)); // uma forma de printar o conteúdo formatado
		System.out.println(formated_date);
		System.out.println(date_hour);
		System.out.println(date_hour_gmt);
		System.out.println(string_to_date);
		System.out.println(string_to_date_gmt);
		System.out.println(string_to_date_gmt_timezone);
		System.out.println(date02);
		
	}

}
