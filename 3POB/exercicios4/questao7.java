package POB.exercicios4;

import java.util.ArrayList;
import java.util.Scanner;

// Construa um programa que armazene números inteiros em uma lista de 10 posições, calcule o quadrado de cada elemento armazenado nesta lista e armazene o resultado em uma outra lista. Ao final os dados da segunda lista devem ser exibidos.

public class questao7 {
    public static void main(String[] args) {
        Scanner ler = new Scanner(System.in);
        ArrayList<Integer> numeros = new ArrayList<>();
        ArrayList<Integer> quadrados = new ArrayList<>();

        for (int i = 0; i < 10; i++) {
            System.out.print("Digite um numero: ");
            int numero = ler.nextInt();

            numeros.add(numero);
        }

        for (int num : numeros) {
            quadrados.add(num * num);
        }

        System.out.println("Nova lista: " + quadrados);

        ler.close();
    }
}
