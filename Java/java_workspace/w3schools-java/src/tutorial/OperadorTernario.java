package tutorial;

public class OperadorTernario {

	public static void main(String[] args) {
		int num = 10;
		String resultado = (num > 15) ? "Meu pau" : "Minhas bolas";
		
		System.out.println(resultado);
		
		boolean teste = true;
		
		if (!(teste = false)) {
			System.out.println("énis");
		}
	}

	
}
