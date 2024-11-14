package POB.exercicios1;

import java.text.DecimalFormat;
import java.util.Scanner;

// O camelô Zé da banca vende diariamente, games, calculadoras e canetas. Faça um programa para solicitar o total de
// games, o total de calculadoras   e o  total de canetas vendidas ao término do dia. O programa deve solicitar também o
// preço de cada um dos produtos e ao final calcular e informar o total do faturamento com cada produto e o faturamento total.

public class exercicio4 {
    public static void main(String[] args) {
        Scanner ler = new Scanner(System.in);
        DecimalFormat df = new DecimalFormat("#.00");

        System.out.print("Games vendidos: ");
        int totalGames = ler.nextInt();
        System.out.print("Calculadoras vendidas: ");
        int totalCalc = ler.nextInt();
        System.out.print("Canetas vendidas: ");
        int totalCanetas = ler.nextInt();

        System.out.print("Preço do game: R$");
        double precoGames = ler.nextDouble();
        System.out.print("Preço da calculadora: R$");
        double precoCalc = ler.nextDouble();
        System.out.print("Preço da caneta: R$");
        double precoCanetas = ler.nextDouble();

        double faturamentoGames = totalGames * precoGames;
        System.out.println("Faturamento de games: R$" + df.format(faturamentoGames));
        double faturamentoCalc = totalCalc * precoCalc;
        System.out.println("Faturamento de calculadoras: R$" + df.format(faturamentoCalc));
        double faturamentoCanetas = totalCanetas * precoCanetas;
        System.out.println("Faturamento de canetas: R$" + df.format(faturamentoCanetas));

        double faturamentoTotal = faturamentoCalc + faturamentoCanetas + faturamentoGames;
        System.out.println("Faturamento total: R$" + df.format(faturamentoTotal));
        
        ler.close();
    }
}
