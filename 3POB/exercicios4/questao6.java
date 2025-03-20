package POB.exercicios4;

import java.util.ArrayList;
import java.util.Scanner;

// Elabore um programa utilizando listas para armazenar 10 números e ao final escreva a quantidade de números negativos, positivos e nulos.


public class questao6 {
    public static void main(String[] args) {
        Scanner ler = new Scanner(System.in);
        ArrayList<Integer> numeros = new ArrayList<>();

        for (int i = 0; i < 10; i++) {
            System.out.print("Digite um numero: ");
            int numero = ler.nextInt();

            numeros.add(numero);
        }

        int numPos, numNul;
        int numNeg = numPos = numNul = 0;

        for (int num : numeros) {
            if (num == 0) {
                numNul++;
            } else if (num > 0) {
                numPos++;
            } else {
                numNeg++;
            }
        }

        System.out.println("Números Negativos: " + numNeg);
        System.out.println("Números Positivos: " + numPos);
        System.out.println("Números Nulos: " + numNul);

        ler.close();
    }
}
