package BitCount;

public class BitCounting {

	public static String binaryConversion(int n) {
	    
	    if (n == 0)
	    	return "0";
	    if (n == 1)
	    	return "1";

		return binaryConversion(n/2) + String.valueOf(n%2);
	}
	
	public static int countBits2(String binary, int i) {
		
		if (i >= binary.length())
			return 0;
		
		int bits = (binary.charAt(i) == '1') ? 1 : 0;
		
		return bits += countBits2(binary, i + 1);
	}
}
