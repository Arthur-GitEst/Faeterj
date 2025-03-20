package POB.exercicios2;

import java.util.Scanner;

// Faça um programa que leia dois números e mostre qual o maior dos dois. O programa deve informar caso sejam iguais. 

public class questao5 {
    public static void main(String[] args) {
        Scanner ler = new Scanner(System.in);

        System.out.print("Digite um numero: ");
        int numX = ler.nextInt();
        System.out.print("Digite outro numero: ");
        int numY = ler.nextInt();

        if (numX == numY) {
            System.out.println("Os numeros são iguais.");
        } else if (numX > numY) {
            System.out.println(numX + " é maior");
        } else {
            System.out.println(numY + " é maior");
        }

        ler.close();
    }
}
