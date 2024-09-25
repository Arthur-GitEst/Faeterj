package POB.exercicios3;

import java.text.DecimalFormat;
import java.util.Scanner;

//Faça um programa que leia a idade de 10 pessoas. Ao final escreva a média das idades.

public class questao3 {
    public static void main (String[] args) {
        Scanner ler = new Scanner(System.in);
        DecimalFormat df = new DecimalFormat("#.00");

        System.out.println("Insira 10 idades:");

        double v1 = ler.nextDouble();
        double v2 = ler.nextDouble();
        double v3 = ler.nextDouble();
        double v4 = ler.nextDouble();
        double v5 = ler.nextDouble();
        double v6 = ler.nextDouble();
        double v7 = ler.nextDouble();
        double v8 = ler.nextDouble();
        double v9 = ler.nextDouble();
        double v10 = ler.nextDouble();

        double soma = v1 + v2 + v3 + v4 + v5 + v6 + v7 + v8 + v9 + v10;

        System.out.println("Media das idades igual a: " + df.format(soma / 10));

        ler.close();
    }
}
