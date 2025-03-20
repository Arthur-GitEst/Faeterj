package POB.exercicios4;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

// Faça um programa utilizando listas que leia 10 números inteiros e ao final escreva estes números na ordem crescente e na ordem decrescente.


public class questao5 {
    public static void main(String[] args) {
        Scanner ler = new Scanner(System.in);
        ArrayList<Integer> numeros = new ArrayList<>();

        for (int i = 0; i < 10; i++) {
            System.out.print("Insira um numero: ");
            int numero = ler.nextInt();
            
            numeros.add(numero);
        }

        Collections.sort(numeros);
        System.out.println("Ordem crescente: " + numeros);

        Collections.sort(numeros, Collections.reverseOrder());
        System.out.println("Ordem Descrescente: " + numeros);

        ler.close();
    }
}
