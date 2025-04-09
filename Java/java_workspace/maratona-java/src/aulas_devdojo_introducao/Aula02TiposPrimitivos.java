package aulas_devdojo_introducao;

public class Aula02TiposPrimitivos {

	public static void main(String[] args) {
		
		// casting
		int numero = (int)10000000000L; // força a variável a receber um valor maior do que ela suporta -> vai quebrar os bits
		float f = 85.2f;
		double d = 97.3d;
		long numerao = (long)55.38; // vira 55
		boolean teste = 10 != 10.0;
		System.out.println(teste);
	}

}

