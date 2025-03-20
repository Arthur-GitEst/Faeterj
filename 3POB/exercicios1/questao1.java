package POB.exercicios1;
import java.util.Scanner;
import java.text.DecimalFormat;

public class questao1 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        DecimalFormat df = new DecimalFormat("0.00");

        System.out.print("Digite a matrícula do primeiro empregado: ");
        int matricula1 = scanner.nextInt();
        System.out.print("Digite o salário do primeiro empregado: ");
        double salario1 = scanner.nextDouble();

        System.out.print("Digite a matrícula do segundo empregado: ");
        int matricula2 = scanner.nextInt();
        System.out.print("Digite o salário do segundo empregado: ");
        double salario2 = scanner.nextDouble();

        double desconto = salario1 * 0.05;
        double acrescimo = salario2 * 0.09;

        double salarioFinal1 = salario1 - desconto;
        double salarioFinal2 = salario2 + acrescimo;

        System.out.println("Valor do desconto do primeiro empregado: " + df.format(desconto));
        System.out.println("Valor do acréscimo do segundo empregado: " + df.format(acrescimo));
        System.out.println("Salário final do primeiro empregado: " + df.format(salarioFinal1));
        System.out.println("Salário final do segundo empregado: " + df.format(salarioFinal2));

        scanner.close();
    }
}