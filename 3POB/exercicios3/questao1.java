package POB.exercicios3;

import java.text.DecimalFormat;
import java.util.Scanner;

//Faça um programa que leia o preço de 10 produtos. Ao final escreva o somatório dos preços.

public class questao1 {
    public static void main (String[] args) {
        Scanner ler = new Scanner(System.in);
        DecimalFormat df = new DecimalFormat("#.00");

        System.out.println("Insira 10 valores:");

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

        System.out.println("Somatorio igual a: " + df.format(soma));

        ler.close();
    }
}

