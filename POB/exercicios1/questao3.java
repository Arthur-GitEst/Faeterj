package POB.exercicios1;

import java.text.DecimalFormat;
import java.util.Scanner;

public class questao3 {
    public static void main (String[] args) {
        Scanner ler = new Scanner(System.in);
        DecimalFormat df = new DecimalFormat("0.00");

        System.out.print("Insira o codigo da turma: ");
        int codigo = ler.nextInt();

        System.out.print("Insira a quantidade de alunos do sexo masculino: ");
        int quantM = ler.nextInt();

        System.out.print("Insira a quantidade de alunos do sexo feminino: ");
        int quantF = ler.nextInt();

        System.out.print("Insira a quantidade de alunos aprovados: ");
        int quantA = ler.nextInt();

        int total = quantM + quantF;
        int quantR = total - quantA;

        double pQuantM = (quantM * 100.0) / total;
        double pQuantF = (quantF * 100.0) / total;
        double pQuantR = (quantR * 100.0) / total;

        System.out.println(df.format(pQuantM) + "% dos alunos sao do sexo masculino");
        System.out.println(df.format(pQuantF) + "% dos alunos sao do sexo feminino");
        System.out.println(df.format(pQuantR) + "% dos alunos foram reprovados");
        System.out.println("Existem " + total + " alunos nessa turma");

        ler.close();
    }
}