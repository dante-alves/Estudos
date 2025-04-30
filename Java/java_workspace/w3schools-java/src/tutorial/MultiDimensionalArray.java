package tutorial;

public class MultiDimensionalArray {

	public static void main(String[] args) {
		int[][] matriz = {{1, 2, 3}, {4, 5, 6}};
		
		System.out.println(matriz[0][1]);
		
		// como inicializar a matriz
		int[][] matriz2 = new int[3][]; // poderia colocar new int[3][2]
		
//		matriz2[0] = new int[4];
//		matriz2[1] = new int[2];
//		matriz2[2] = new int[3];
		// o mesmo que -> matriz2 = {{0, 0, 0, 0}, {0, 0}, {0, 0, 0}};
		
		System.out.println("\nPrintando usando um for:");
		for (int i = 0; i < matriz2.length; i++) {
			for (int j = 0; j < matriz2[i].length; j++) {
				
				matriz2[i][j] = (int)(Math.random() * 101); // atribuindo valores aleatórios
				System.out.println(matriz2[i][j]);
			}
		}
		
		System.out.println("\nPrintando usando um for-each:");
		for (int[] linha : matriz2) {
			for (int i : linha) {
				System.out.println(i);
			}
		}
		
	}

}
