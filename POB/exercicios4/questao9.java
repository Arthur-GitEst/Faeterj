package POB.exercicios4;

import java.util.ArrayList;
import java.util.Scanner;

// Elabore um programa que contenha três listas de 10 posições A, B e C. O objetivo do programa é armazenar números nas listas A e B e fazer com que a lista C receba a soma dos elementos correspondentes de A e B. Ao final o programa deve exibir no vídeo o conteúdo da lista C.

public class questao9 {
    public static void main(String[] args) {
        Scanner ler = new Scanner(System.in);
        ArrayList<Integer> listaA = new ArrayList<>();
        ArrayList<Integer> listaB = new ArrayList<>();
        ArrayList<Integer> listaC = new ArrayList<>();

        System.out.println("Preencher lista A:");
        for (int i = 0; i < 10; i++) {
            System.out.print("Digite um numero: ");
            int numero = ler.nextInt();

            listaA.add(numero);
        }

        System.out.println("\nPreencher lista B:");
        for (int i = 0; i < 10; i++) {
            System.out.print("Digite um numero: ");
            int numero = ler.nextInt();

            listaB.add(numero);
        }

        for (int i = 0; i < listaA.size(); i++) {
            int elemento = listaA.get(i) + listaB.get(i);
            listaC.add(elemento);
        }

        System.out.println("Lista C: " + listaC);

        ler.close();
    }
}
