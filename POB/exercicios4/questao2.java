package POB.exercicios4;

import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.Scanner;

// Elabore um programa usando listas que leia a matrícula e o salário bruto de 100 empregados. Os dados devem ser armazenados em listas. O programa deve descontar 11% do salário bruto de cada empregado e ao final escrever: a matrícula, o salário bruto, o desconto e o salário líquido de cada empregado.

public class questao2 {
    public static void main(String[] args) {
        ArrayList<Integer> matriculas = new ArrayList<>();
        ArrayList<Double> salarios = new ArrayList<>();
        Scanner ler = new Scanner(System.in);
        DecimalFormat df = new DecimalFormat("#.00");

        for (int i = 0; i < 101; i++) {
            System.out.printf("Digite a matricula: ");
            int matricula = ler.nextInt();
            System.out.printf("Digite o salario bruto: ");
            double salarioBruto = ler.nextDouble();

            matriculas.add(matricula);
            salarios.add(salarioBruto);
        }

        for (int i : matriculas) {
            double desconto = salarios.get(i) * 0.11;
            double salarioLiqui = salarios.get(i) + desconto;

            System.out.println("Matricula: " + matriculas.get(i));
            System.out.println("Salario Bruto: " + df.format(salarios.get(i)));
            System.out.println("Desconto: " + df.format(desconto));
            System.out.println("Salario Liquido: " + df.format(salarioLiqui));
        }

        ler.close();
    }
}
