package data_hora;

import java.time.Duration;
import java.time.Instant;
import java.time.LocalDate;
import java.time.LocalDateTime;
import java.time.ZoneId;
import java.time.format.DateTimeFormatter;
import java.time.temporal.ChronoUnit;

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
		DateTimeFormatter fmt04 = DateTimeFormatter.ISO_DATE_TIME; // pode pegar direto um formato próprio da classe
		
		// outra forma de passar
		LocalDate date02 = LocalDate.of(2003, 6, 25);
		
		System.out.println(fmt01.format(date)); // uma forma de printar o conteúdo formatado
		System.out.println(formated_date.format(fmt01)); // outra forma de printar formatado
		System.out.println(date_hour);
		System.out.println(date_hour_gmt);
		System.out.println(string_to_date);
		System.out.println(string_to_date_gmt);
		System.out.println(string_to_date_gmt_timezone);
		System.out.println(date02);
		
		
		System.out.println(ZoneId.getAvailableZoneIds());
		// como passar datas em fuso horários diferentes
		LocalDateTime r1 = LocalDateTime.ofInstant(string_to_date_gmt, ZoneId.systemDefault());
		LocalDateTime r2 = LocalDateTime.ofInstant(string_to_date_gmt_timezone, ZoneId.of("Portugal"));

		System.out.println("r1 = " + r1 + "\nr2 = " + r2);
		
		// como pegar dados separados da data
		System.out.println("data completa = " + date_hour 
							+"\ndia = " + date_hour.getDayOfMonth() 
							+ "\nmês = " + date_hour.getMonthValue() 
							+ "\nano = " + date_hour.getYear()
							+ "\nhour = " + date_hour.getHour()
						  );
		
		// cálculos com datas
		LocalDateTime pastWeek = date_hour.minusDays(7);
		LocalDateTime nextWeek = date_hour.plusDays(7);
		
		System.out.println(pastWeek);
		System.out.println(nextWeek);
		
		Instant d01 = string_to_date_gmt;
		
		Instant pastWeekInstant = d01.minus(7, ChronoUnit.DAYS);
		Instant nextWeekInstant = d01.plus(7, ChronoUnit.DAYS);
		
		System.out.println(pastWeekInstant);
		System.out.println(nextWeekInstant);
		
		Duration t1 = Duration.between(pastWeek, date_hour); // calculando a duração 
		
		System.out.println(t1.toDays());
	}
}
