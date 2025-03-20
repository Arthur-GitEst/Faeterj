package POB.exercicios3;

import java.util.Scanner;

// Crie um programa que leia a altura de um número indeterminado de pessoas. Ao final o programa deve informar o total de pessoas cadastradas, a quantidade de pessoas com altura inferior a 1,60 metros; a quantidade de pessoas com altura entre 1,60 metros e 1,80 metros e a quantidade de pessoas com altura superior a 1,80 metros.


public class questao5 {
    public static void main (String[] args) {
        Scanner ler = new Scanner(System.in); 

        int total = 0;
        int totalInferior = 0;
        int totalEntre = 0;
        int totalSuperior = 0;
        String continuar = "";

        do {
            System.out.printf("Digite a altura da pessoa em metros: ");
            double altura = ler.nextDouble();

            if (altura < 1.60) {
                totalInferior++;
            } else if (altura >= 1.60 && altura <= 1.80) {
                totalEntre++;
            } else {
                totalSuperior++;
            }

            total++;

            System.out.println("Gostaria de continuar? (S ou N)");
            continuar = ler.next().toUpperCase();
        } while (continuar.equals("S"));

        System.out.println("Pessoas cadastradas: " + total);
        System.out.println("Pessoas abaixo de 1,60m: " + totalInferior);
        System.out.println("Pessoas entre 1,60m e 1,80m: " + totalEntre);
        System.out.println("Pessoas acima de 1,80m: " + totalSuperior);

        ler.close();
    }
}
