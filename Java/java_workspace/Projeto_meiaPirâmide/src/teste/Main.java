package teste;
import java.util.Scanner;



public class Main {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int tam, totalLinhas, indiceValoresAleatorios;
		
		System.out.print("Digite números variados, separados por espaço: ");
		
		 String valoresTexto = scan.nextLine(); 
//		String valoresTexto = "9 98 41 76 5 2 8";
		
		tam = contarTamanho(valoresTexto); // calculando o tamanho do vetor
		
		ResultadoPiramide resultados = calcularPiramide(tam);
		
		if (resultados.tamanhoCorrigido != tam) {
			tam = resultados.tamanhoCorrigido;
		}
		
		totalLinhas = resultados.totalLinhas;
		
		int[] vet = converterVetor(valoresTexto, tam); // transformando em vetor de inteiros
		
		imprimirPiramide(vet, tam, totalLinhas);
		
	}
	
	private static class ResultadoPiramide {
		int totalLinhas;
		int tamanhoCorrigido;
		
		ResultadoPiramide(int totalLinhas, int tamanhoCorrigido) {
			this.totalLinhas = totalLinhas;
			this.tamanhoCorrigido = tamanhoCorrigido;
		}
	}
	
	private static ResultadoPiramide calcularPiramide(int tam) {
		int i = 0;
		
		int linha = 1, qtdLinha;

		while(i + linha <= tam) { 
			
			for (qtdLinha = 1; qtdLinha <= linha; qtdLinha++) {
				i++;
			}
			
			linha++; 
		}
		
		
		int contador = 0;
		
		if (i < tam) {
			System.out.println("\nPirâmide incompleta... modificando o tamanho do vetor.");
			while (i < tam) {
				i++;
				contador++;
			}
			
			tam += (linha - contador);
		}
		
		return new ResultadoPiramide(linha, tam);
	}
	// método para contar o tamanho do vetor que será criado
	private static int contarTamanho(String texto) {
		int i = 0, tam = 0;
		
		// vai até o final da string
		while(i < texto.length()) {
			if(texto.charAt(i) == ' ') // se tiver um espaço, adiciona +1 ao tamanho --> o método charAt serve para verificar o caractere no índice indicado, como pode ser feito diretamente em C
				tam++;
			
			i++;
		}
		
		tam++; // adiciona +1 ao tamanho para os casos de só ter 1 número ou para contabilizar o último valor, já que não tem espaço após ele.
		
		
		return tam;
	}
	
	
	// método para converter a String em vetor de int
	private static int[] converterVetor(String texto, int tam) {
		int i;
		
		String[] valores = texto.split(" "); // dividir cada valor num array de Strings, se tiver "5 10 15", vai ficar {"5", "10", "15}
		
		/* o .split(String) utiliza como argumento uma string que vai delimitar a expressão regular que vai dividir cada valor.
		   nesse caso, é o espaço " ".
		*/
		
		int[] vet = new int[tam]; // inicializando o tamanho do vetor que vai armazenar os valores
		
		
		for (i = 0; i < valores.length; i++)
			vet[i] = Integer.parseInt(valores[i]);
		
		while (i < tam) {
			vet[i] = (int)(Math.random() * 101);
			i++;
		}
		
		return vet;
	}
	
	
	private static void imprimirPiramide(int[] vet, int tam, int totalLinhas) {
		int i = 0, j = 0, menor, soma = 0;
		
		System.out.println("\n-----------------");
		System.out.println("-- PIRÂMIDE --");
		
		int linha = 1;

		int[] menoresValores = new int[totalLinhas];
		
		for (linha = 1; linha <= totalLinhas; linha++) { // repetir o código até onde for possível criar linhas com um número a mais a cada linha
			
			menor = vet[i]; // menor recebe o primeiro valor de cada linha

			for (int qtdLinha = 1; qtdLinha <= linha; qtdLinha++) {
				System.out.printf("%2d ", vet[i]);
				// verificação de cada valor da linha para descobrir o menor
				if (vet[i] < menor)
					menor = vet[i];
				i++;
			}
			
			menoresValores[j++] = menor;
			soma += menor; // soma o menor número da linha à variável soma
			
			System.out.println();
		}

		
		System.out.println("-----------------");
		
		System.out.print("Menores valores de cada linha: [");
		

		for (i = 0; i < totalLinhas - 1; i++) {
			System.out.print(menoresValores[i]+", ");
		}
		
		System.out.println(menoresValores[i]+"]");
		
		System.out.println("\nSoma dos menores valores de cada linha: " + soma);
	}
}



