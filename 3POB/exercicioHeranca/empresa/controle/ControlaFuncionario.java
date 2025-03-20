package POB.exercicioHeranca.empresa.controle;

import java.util.ArrayList;
import java.util.Scanner;

import POB.exercicioHeranca.empresa.dominio.Vendas;

public class ControlaFuncionario {
    public static void main(String[] args) {
        Scanner ler = new Scanner(System.in);
        ArrayList<Vendas> funcionarios = new ArrayList<>(); 

        boolean continuar = true;

        while (continuar) {
            System.out.println("\nEscolha uma Opção:");
            System.out.println("1. Adicionar Funcionário");
            System.out.println("2. Sair");
            System.out.print("Opção: ");
            int opcao = ler.nextInt();
            ler.nextLine();

            if (opcao == 1) {
                System.out.print("Nome: ");
                String nome = ler.nextLine();
                System.out.print("Matrícula: ");
                String matricula = ler.nextLine();
                System.out.print("CPF: ");
                String cpf = ler.nextLine();
                System.out.print("Salário: ");
                float salario = ler.nextFloat();
                System.out.print("Gratificação: ");
                float gratificacao = ler.nextFloat();
                System.out.print("Participação de lucros (em %): ");
                float participacaoLucros = ler.nextFloat();
                ler.nextLine();

                Vendas v = new Vendas(nome, matricula, cpf, salario, gratificacao, participacaoLucros);
                funcionarios.add(v);
            } else if (opcao == 2) {
                continuar = false;
            } else {
                System.out.println("Opção Inválida.");
            }
        }

        ler.close();

        System.err.println("Relatório de Funcionários: ");
        System.out.println();
        for (Vendas f : funcionarios) {
            f.mostrarInfo();
            System.out.println();
        }
    }
}
