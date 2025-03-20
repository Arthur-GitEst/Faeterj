package POB.exercicios2;

import java.util.Scanner;

// Elabore um programa que leia três números diferentes e informe o maior deles.

public class questao7 {
    public static void main(String[] args) {
        Scanner ler = new Scanner(System.in);

        System.out.print("Digite um numero: ");
        int numX = ler.nextInt();
        System.out.print("Digite outro numero: ");
        int numY = ler.nextInt();
        System.out.print("Digite mais um outro numero: ");
        int numZ = ler.nextInt();


        int maior = numX;

        if (numY > maior) {
            maior = numY;
        }

        if (numZ > maior) {
            maior = numZ;
        }

        System.out.println(maior + " é o maior numero.");

        ler.close();
    }
}
