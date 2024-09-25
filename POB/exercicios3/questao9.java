package POB.exercicios3;

import java.text.DecimalFormat;

// A conversão de graus Farenheit para graus centígrados é obtida por : C = 5/9 * (F -32). Faça um programa que calcule e escreva uma tabela de centígrados em função de graus Farenheit, que variam de 100 a 150 de 1 em 1.

public class questao9 {
    public static void main (String[] args) {
        DecimalFormat df = new DecimalFormat("#.00");
        
        for (int i = 100; i < 151; i++) {
            System.out.println(i + "°F: " + df(i / 9));
        }
    }
}
