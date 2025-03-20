package POB.exercicios4;

import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.Scanner;

// Faça um programa utilizando listas que leia o nome e a altura de 50 pessoas e ao final escreva o nome e a altura das pessoas com mais de 1,70 metros.


public class questao1 {
    public static void main(String[] args) {
        ArrayList<String> nomes = new ArrayList<>();
        ArrayList<Double> alturas = new ArrayList<>();
        Scanner ler = new Scanner(System.in);
        DecimalFormat df = new DecimalFormat("#.00");

        for (int i = 0; i < 51; i++) {
            System.out.printf("Digite o nome: ");
            String nome = ler.next();
            System.out.printf("Digite a altura: ");
            double altura = ler.nextDouble();

            nomes.add(nome);
            alturas.add(altura);
        }

        for (int i = 0; i < alturas.size(); i++) {
            if (alturas.get(i) > 1.7) {
                System.out.println("Nome: " + nomes.get(i));
                System.out.println("Altura: " + df.format(alturas.get(i)) + "m");
            }
        }

        ler.close();
    }
}