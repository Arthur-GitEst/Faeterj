package POB.exercicios3;

import java.text.DecimalFormat;
import java.util.Random;

// Crie um programa que leia o nome e a altura de 10 pessoas e ao final escreva: a altura média do grupo, o nome e a altura da pessoa mais alta.

public class questao8 {
    public static void main (String[] args) {
        DecimalFormat df = new DecimalFormat("#.00");
        Random rand = new Random();

        int quant = 10;
        double soma = 0;
        double maior = Double.MIN_VALUE;

        for (int i = 0; i < quant; i++) {
            double altura = 1 + rand.nextDouble();

            if (altura > maior) {
                maior = altura;
            }

            soma += altura;
        }

        double media = soma/quant;

        System.out.println("Media das alturas: " + df.format(media));
        System.out.println("Maior altura: " + df.format(maior));
    }
}
