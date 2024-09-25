package POB.exercicios3;

import java.util.Scanner;

//Elabore um programa que leia o sexo de um número indeterminado de pessoas. Ao final escreva a quantidade de pessoas cadastradas e o total de pessoas  de cada sexo.

public class questao4 {
    public static void main (String[] args) {
        Scanner ler = new Scanner(System.in);

        int total = 0;
        int totalM = 0;
        int totalF = 0;
        String continuar = "";

        do {
            System.out.print("Insira o sexo da pessoa (M ou F): ");
            char sexo = ler.next().toUpperCase().charAt(0);

            if (sexo == 'M') {
                totalM++;
            } else if (sexo == 'F') {
                totalF++;
            } else {
                System.out.println("Valor invalido");
                continue;
            }

            total++;

            System.out.println("Deseja continuar? (S ou N)");
            continuar = ler.next().toUpperCase();
        } while (continuar.equals("S"));

        System.out.println(total + " pessoas cadastradas");
        System.out.println(totalF + " pessoas do sexo feminino");
        System.out.println(totalM + " pessoas do sexo masculino");

        ler.close();
    }
}
