package POB.exercicios4;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

// Faça um programa utilizando listas que leia 9 números inteiros. Ao final o programa deve informar o maior número, a quantidade de vezes que ele ocorre e em quais posições da lista.


public class questao8 {
    public static void main(String[] args) {
        Scanner ler = new Scanner(System.in);
        ArrayList<Integer> numeros = new ArrayList<>();
        ArrayList<Integer> posicoes = new ArrayList<>();

        int maior = Integer.MIN_VALUE;
        int cont = 0;
    
        for (int i = 0; i < 9; i++) {
            System.out.print("Digite um numero: ");
            int numero = ler.nextInt();

            numeros.add(numero);

            if (numero > maior) {
                maior = numero;
                cont = 1;
            } else if (numero == maior) {
                cont++;
            }
        }

        for (int i = 0; i < numeros.size(); i++) {
            if (numeros.get(i) == maior) {
                posicoes.add(i + 1);
            }
        }

        System.out.println("Maior Numero: " + maior);
        System.out.println("Quantidade: " + cont);
        System.out.println("Posições: " + posicoes);

        ler.close();
    }
}
