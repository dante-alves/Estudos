package tutorial;

public class ForEachLoop {

	public static void main(String[] args) {
		// um for normal
		for (int i = 0; i < 5; i++) {
			System.out.println(i);
	}
		
		// um for-each
		String[] nomes = {"Dante", "Jorge Borel", "Belzetoth"};
		
		// coloco primeiro nome da variável : nome do array
		for (String nome : nomes) {
			System.out.println(nome);
		}
		
		for (int num = 1; num <= 10; num++) {
			for (int i = 0; i <= 10; i++) {
				System.out.println(num+" X "+i+" = "+ (num * i));
			}
			System.out.println();
		}
	}

}
