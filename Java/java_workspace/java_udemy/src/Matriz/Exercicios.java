package Matriz;

import java.util.Locale;
import java.util.Scanner;

public class Exercicios {

	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		
		Exercicios.ex02();
		
	}
	
	public static void ex01() {
		Scanner sc = new Scanner(System.in);
		int m, n;
		
		System.out.print("Insira a quantidade de linhas: ");
		m = sc.nextInt();
		
		System.out.print("Insira a quantidade de colunas: ");
		n = sc.nextInt();
		
		int[][] mat = new int[m][n];
		
//		for (int[] linha : mat) {
//			for (int coluna : linha) {
//				System.out.print("\nInsira o valor: ");
//				coluna = sc.nextInt();
//			}
//		}
		
				
		for (int i = 0; i < mat.length; i++) {
			for (int j = 0; j < mat[i].length; j++) {
				System.out.printf("Insira o valor em (%d, %d): ", i, j);
				mat[i][j] = sc.nextInt();
			}
		}
		
		System.out.print("Qual valor quer achar?: ");
		int x = sc.nextInt();
		
		for (int i = 0; i < mat.length; i++) {
			for (int j = 0; j < mat[i].length; j++) {
				if (mat[i][j] == x) {
					System.out.printf("\nPosição: %d, %d", i, j);
					
					if (j > 0) 
						System.out.printf("\nEsquerda: %d", mat[i][j-1]);
					if (i > 0) 
						System.out.printf("\nAcima: %d", mat[i-1][j]);
					if (j < mat[i].length - 1)
						System.out.printf("\nDireita: %d", mat[i][j+1]);
					if (i < mat.length)
						System.out.printf("\nAbaixo: %d", mat[i+1][j]);
						
			}
		}
			}
		sc.close();
	}
	
	public static void ex02() {
		Scanner sc = new Scanner(System.in);
		
		System.out.print("Tamanho da matriz: ");
		int n = sc.nextInt();
		
		
		int[][] mat = new int[n][n];
		
		
		
		for (int l = 0; l < mat.length; l++) {
			for (int c = 0; c < mat[l].length; c++) {
				mat[l][c] = sc.nextInt();
			}
		}
		
		System.out.println("Diagonal principal:");
		for (int l = 0; l < mat.length; l++) {
			System.out.print(mat[l][l] + " ");
		}
		
		System.out.println("\nValores negativos:");
		for (int[] row : mat) {
			for (int col : row) {
				if (col < 0)
					System.out.print(col + " ");
			}
		}
		sc.close();
		
	}

}
