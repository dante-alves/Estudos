package tutorial;

public class Arrays {

	public static void main(String[] args) {
		String[] cars = {"Palio", "Fiat", "Gol Bola"};
		for (String car : cars) {
			System.out.println(car);
		}
		
		System.out.println(cars[0]);
		
		
		int[] numeros = {4, 0, 0, 2, 8, 9, 2, 2};
		for (int numero : numeros) {
			System.out.println(numero);
		}
		
		
		
		System.out.println("Tamanho do array: "+numeros.length);
		
//		for (int i = 0; i < numeros.length; i++) {
//			System.out.println(numeros[i]);
//		}
//		
		
		// COMO INICIALIZAR O ARRAY COM UM TAMANHO?
		int[] numeros2 = new int[5]; // array de 5 posições
		String[] nomes = new String[3]; // array de 3 posições
		
		for (int i = 0; i < numeros2.length;i++) {
			numeros2[i] = i;
			System.out.println(numeros2[i]);
		}
	}

}
