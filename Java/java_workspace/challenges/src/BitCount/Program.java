package BitCount;

public class Program {

	public static void main(String[] args) {
		System.out.println(BitCounting.countBits(5));
		System.out.println(BitCounting.countBits(1234));
		String teste = BitCounting.binaryConversion(1234);
		System.out.println(BitCounting.countBits2(teste, 0));
	}

}
