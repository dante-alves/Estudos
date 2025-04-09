package tutorial;

public class Break_Continue {

	public static void main(String[] args) {
		// caso do break
		for (int i = 0; i < 10; i++) {
			
			if (i == 4) break; // o break para o loop
			
			System.out.println(i);
		}
		
		System.out.println();
		
		// caso do continue
		for (int i = 0; i < 10; i ++) { 
			
			if (i == 4) continue; // o continue só quebra aquele caso -> vai pular o 4
			
			System.out.println(i);
		}
		
		System.out.println();
		
		// usando um continue em um while
		int c = 0;
		while (c < 10) {
			
			if (c == 4) {
				c++; // tem que incrementar logo, se não vai dar um loop infinito de continue, pois c vai continuar sendo 4
				continue;
			}
			System.out.println(c);
			c++;
		}
	}

}
