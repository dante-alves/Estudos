package Listas;

import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

public class Lista {

	public static void main(String[] args) {
		// não aceita tipos primitivos, tem que usar a wrapper class
		List<String> list = new ArrayList<>(); //ArrayList é uma ótima classe para instanciar a interface List
		
		list.add("Maria");
		list.add("Jorge Borel");
		list.add("Pecilga");
		list.add("Tico");
		list.add("Teco");
		list.add(2, "Globglobgobgalab");
		list.add("Gobu");
		
		System.out.println("Tamanho: " + list.size());
		
		System.out.println("\nLista:");
		for (String name : list) {
			System.out.println(name);
		}
		
		list.remove("Maria"); // remover por valor
		list.remove(0); // remover por índice
		
		
		
		System.out.println("\nLista:");
		for (String name : list) {
			System.out.println(name);
		}
		
		list.removeIf(x -> x.charAt(0) == 'T'); // função lambda chamada predicado para encontrar o caractere na primeira posição
		
		System.out.println("\nLista:");
		for (String name : list) {
			System.out.println(name);
		}
		
		System.out.println("\nIndex of Pecilga: " + list.indexOf("Pecilga"));
		
		// Criando outra lista pra filtrar elementos
		List<String> result = list.stream().filter(x -> x.charAt(0) == 'G').collect(Collectors.toList()); 
		
		System.out.println("\nLista extra: ");
		for (String name : result) {
			System.out.println(name);
		}
		
		// retornando o primeiro elemento da lista que começa com 'G'
		String name = list.stream().filter(x -> x.charAt(0) == 'G').findFirst().orElse(null);
		System.out.println(name);
	}

}
