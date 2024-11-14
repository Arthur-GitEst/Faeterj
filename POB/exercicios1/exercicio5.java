package POB.exercicios1;

import java.util.Scanner;

// Elabore um programa para solicitar o nome de uma equipe de futebol, a quantidade de derrotas, empates e vitórias obtidas por ela no campeonato. Calcular e informar: a quantidade de pontos ganhos e a quantidade de pontos perdidos.

public class exercicio5 {
    public static void main(String[] args) {
        Scanner ler = new Scanner(System.in);

        System.out.print("Nome do time: ");
        String nomeTime = ler.next();
        
        System.out.println("");

        System.out.print("Vitórias: ");
        int vitorias = ler.nextInt();
        System.out.print("Empates: ");
        int empates = ler.nextInt();
        System.out.print("Derrotas: ");
        int derrotas = ler.nextInt();

        System.out.println("");

        System.out.println("Pontos:");
        System.out.println("Vitória: 3");
        System.out.println("Empate: 0");
        System.out.println("Derrota: -3");

        System.out.println("");

        int pontosGanhos = vitorias * 3;
        System.out.print("Pontos ganhos pelo time " + nomeTime + ": " + pontosGanhos);

        System.out.println("");

        int pontosPerdidos = derrotas * 3;
        System.out.print("Pontos perdidos pelo time " + nomeTime + ": " + pontosPerdidos);

        System.out.println("");

        ler.close();
    }
}
