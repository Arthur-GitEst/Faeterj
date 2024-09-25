package POB.exercicios3;

import java.util.Scanner;

// Elabore um programa que leia a idade de diversas pessoas e ao final informe: o total de pessoas cadastradas, a porcentagem de pessoas com idade inferior a 18 anos, a porcentagem de pessoas com idade igual ou superior a 18 anos.

public class questao6 {
    public static void main (String[] args) {
        Scanner ler = new Scanner(System.in);

        int total = 0;
        int menoresIdade = 0;
        int maioresIdade = 0;
        String continuar = "";

        do {
            System.out.printf("Insira a idade: ");
            int idade = ler.nextInt();

            if (idade < 18) {
                menoresIdade++;
            } else {
                maioresIdade++;
            }

            total++;

            System.out.printf("Deseja continuar? (S ou N): ");
            continuar = ler.next().toUpperCase();
        } while (continuar.equals("S"));

        System.out.println(total + " pessoas estao cadastradas.");
        System.out.println(menoresIdade + " pessoas sao menores de idade.");
        System.out.println(maioresIdade + " pessoas sao maiores de idade.");

        ler.close();
    }
}
