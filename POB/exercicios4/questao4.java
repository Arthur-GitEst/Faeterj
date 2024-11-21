package POB.exercicios4;

import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.Scanner;

// Construa um programa usando listas que leia o nome e a nota de 10 alunos e ao final escreva: a nota média da turma; o nome e a nota dos alunos com resultados superiores a nota média da turma.

public class questao4 {
    public static void main(String[] args) {
        Scanner ler = new Scanner(System.in);
        DecimalFormat df = new DecimalFormat("#.00");
        ArrayList<String> nomes = new ArrayList<>();
        ArrayList<Double> notas = new ArrayList<>();
        
        double soma = 0;

        for (int i = 0; i < 10; i++) {
            System.out.printf("Digite o nome: ");
            String nome = ler.next();
            System.out.printf("Digite a nota: ");
            Double nota = ler.nextDouble();

            nomes.add(nome);
            notas.add(nota);
            soma += nota;
        }

        double media = soma / 10;
        System.out.println("Média da turma: " + df.format(media));

        for (double nota : notas) {
            if (nota > media) {
                int index = notas.indexOf(nota);
                System.out.println("Nome: " + nomes.get(index) + "; Nota: " + df.format(notas.get(index)));
            }
        }

        ler.close();
    }
}
