package POB.exercicios3;

// A conversão de graus Farenheit para graus centígrados é obtida por : C = 5/9 * (F -32). Faça um programa que calcule e escreva uma tabela de centígrados em função de graus Farenheit, que variam de 100 a 150 de 1 em 1.

public class questao9 {
    public static void main (String[] args) {     
        for (int i = 100; i < 151; i++) {
            double resultado = (5 * (i - 32)) / 9;
            System.out.println(i + "°F: " + Math.round(resultado) + "ºC");
        }
    }
}
