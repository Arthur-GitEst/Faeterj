package POB.exercicios2;

import java.util.Scanner;

// Crie um programa para ler o valor do salário mínimo, o nome e o salário bruto de um empregado. Se o seu salário for menor que um salário mínimo descontar 2%; se for igual, descontar 5%, e se for superior, descontar 8%. Informar o valor do desconto e o salário líquido.

public class questao6 {
    public static void main(String[] args) {
        Scanner ler = new Scanner(System.in);

        System.out.print("Nome: ");
        String nome = ler.next();
        System.out.print("Salário mínimo: ");
        double salarioMin = ler.nextDouble();
        System.out.print("Salário Bruto: ");
        double salarioBruto = ler.nextDouble();

        double desconto;
        double salarioLiq;

        if (salarioBruto == salarioMin) {
            desconto = salarioBruto * 0.05; 
            salarioLiq = salarioBruto - desconto;
        } else if (salarioBruto < salarioMin) {
            desconto = salarioBruto * 0.02;
            salarioLiq = salarioBruto - desconto;
        } else {
            desconto = salarioBruto * 0.08;
            salarioLiq = salarioBruto - desconto;
        }

        System.out.println("Desconto: " + desconto);
        System.out.println("Salário Líquido: " + salarioLiq);

        ler.close();
    }
}
