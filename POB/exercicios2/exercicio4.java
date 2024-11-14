package POB.exercicios2;

import java.text.DecimalFormat;
import java.util.Scanner;

// Elabore um programa para solicitar o nome, o sexo e o salário bruto de um empregado. Se o seu sexo for masculino, descontar 5% de seu salário; caso contrário, descontar 3%. Informar o valor do desconto e o salário líquido.

public class exercicio4 {
    public static void main(String[] args) {
        Scanner ler = new Scanner(System.in);
        DecimalFormat df = new DecimalFormat("#.00");
    
        System.out.print("Nome: ");
        String nome = ler.next();

        System.out.println("");

        System.out.print("Gênero (M ou F): ");
        String genero = ler.next().toUpperCase();

        System.out.println("");

        System.out.print("Salário Bruto: ");
        double salario = ler.nextDouble();

        System.out.println("");

        if (genero.equals("M")) {
            double desconto = salario * 0.05;
            double salarioLiquido = salario - desconto;
            System.out.println("Desconto: " + df.format(desconto));
            System.out.println("Salário Líquido: R$" + df.format(salarioLiquido));
        } else {
            double desconto = salario * 0.03;
            double salarioLiquido = salario - desconto;
            System.out.println("Desconto: " + df.format(desconto));
            System.out.println("Salário Líquido: R$" + df.format(salarioLiquido));
        }

        ler.close();
    }
}
