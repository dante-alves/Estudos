package estruturas_repetitivas;
import java.util.Scanner;


public class exercicios04 {

	public static void main(String[] args) {
		exercicios04.ex04();
	}
	
	private static void ex01() {
		Scanner scan = new Scanner(System.in);
		int X;
		
		do {			
			System.out.print("Digite um valor maior que 1 e menor que 1000: ");
			X = scan.nextInt();
		} while (X < 1 || X > 1000);
		
		for (int i = 1; i <= X; i+=2) {
			System.out.println(i);
		}
		
		scan.close();
	}
	
	private static void ex02() {
		Scanner scan = new Scanner(System.in);
		int N, X, in, out;
		in = out = 0;
		
		System.out.println("Quantos valores quer ler? ");
		N = scan.nextInt();
		
		for (int i = 1; i <= N; i++) {
			System.out.print("\nDigite um valor: ");
			X = scan.nextInt();
			
			if (X >= 10 && X <= 20) {
				in++;
				continue;
			}
			out++;
		}
		
		System.out.println(in + " in");
		System.out.println(out + " out");
		scan.close();
	}
	
	private static void ex03() {
		Scanner scan = new Scanner(System.in);
		int N;
		float[] vet = new float[3];
		
		
		System.out.print("Quantos testes quer fazer? ");
		N = scan.nextInt();
		float[] mediaPond = new float[N];
		
		for (int i = 0; i < N; i++) {
			System.out.print("\nInsira 3 valores: ");
			vet[0] = scan.nextFloat();
			vet[1] = scan.nextFloat();
			vet[2] = scan.nextFloat();
			mediaPond[i] = ((vet[0] * 2) + (vet[1] * 3) + (vet[2] * 5)) / 10;
		}
		
		for (int i = 0; i < N; i++) {
			System.out.println(mediaPond[i]);
		}
		
		scan.close();
	}
	
	private static void ex04() {
		Scanner scan = new Scanner(System.in);
		float n1, n2;
		
		System.out.println("Quantos pares? ");
		int N = scan.nextInt();
		
		float[] divisao = new float[N];
		
		for (int i = 0; i < N; i++) {
			System.out.println("Digite dois números a serem divididos");
			n1 = scan.nextFloat();
			n2 = scan.nextFloat();
			
			if (n2 == 0) {
				divisao[i] = -1;
				continue;
			}
			
			divisao[i] = n1 / n2;
		}
		
		for (int i = 0; i < N; i++) {
			if(divisao[i] == -1) {
				System.out.println("divisao impossivel");
				continue;
			}
			System.out.println(divisao[i]);
		}
;	}
}
