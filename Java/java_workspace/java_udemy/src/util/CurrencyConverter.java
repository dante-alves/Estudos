package util;

public class CurrencyConverter {
	public static double IOF = 0.06;
	
	public static double convertWithIOF(double dollarPrice, double dollarsBought) {
		double reais = dollarPrice * dollarsBought;
		return reais + (reais * IOF);
	}
}
