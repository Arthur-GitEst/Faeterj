import java.text.DecimalFormat;
import java.util.Scanner;

public class Aula1 {
    public static void main(String[] args) {
        Scanner ler = new Scanner(System.in);
        DecimalFormat formatar = new DecimalFormat("#.00");

        // System.out.println("Insira um valor: ");
        // int v1 = ler.nextInt();
        // System.out.println("Insira outro valor: ");
        // int v2 = ler.nextInt();

        // int r = v1 + v2;

        // System.out.println("Resultado: " + r);

        // System.out.println("Insira seu nome:");
        // String nome = ler.nextLine();
        // System.out.println("Insira seu sobrenome");
        // String sobrenome = ler.nextLine();

        // String nomeCompleto = nome + " " + sobrenome;

        // System.out.println(nomeCompleto);

        System.out.println("Vitórias:");
        int v = ler.nextInt();
        System.out.println("Derrotas:");
        int d = ler.nextInt();
        System.out.println("Empates:");
        int e = ler.nextInt();

        int pg = v * 3 + e;
        int pp = (d * 3) + (e * 2);

        int jogos = v + d + e;
        double apr = (pg / (jogos * 3.0)) * 100;

        System.out.println("Pontos Ganhos: " + pg);

        System.out.println("Pontos Perdidos: " + pp);

        System.out.println("Aproveitamento: " + formatar.format(apr) + "%");

        ler.close();
    }    
}
