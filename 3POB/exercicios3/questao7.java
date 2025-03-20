package POB.exercicios3;

import java.util.Scanner;

// Faça um programa que leia vários números inteiros e ao final escreva o maior.

public class questao7 {
    public static void main (String[] args) {
        Scanner ler = new Scanner(System.in);

        String continuar = "";
        int maior = Integer.MIN_VALUE;

        do {
            System.out.printf("Insira um numero: ");
            int num = ler.nextInt();

            if (num > maior) {
                maior = num;
            }

            System.out.printf("Deseja continuar? (S ou N) ");
            continuar = ler.next().toUpperCase();
        } while (continuar.equals("S"));

        System.out.println("Maior numero: " + maior);

        ler.close();
    } 
}
