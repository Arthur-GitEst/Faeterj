package POB.ProjetoAV2.view;

import java.util.Scanner;

import POB.ProjetoAV2.controller.FuncionarioController;
import POB.ProjetoAV2.model.*;

public class FuncionarioView {
    private final FuncionarioController controller = new FuncionarioController();
    private Scanner scanner = new Scanner(System.in);

    public void menu() {
        controller.carregarDados();
        int opcao;
        do {
            System.out.println("\n1. Cadastrar Funcionário");
            System.out.println("2. Listar Funcionários");
            System.out.println("3. Atualizar Funcionário");
            System.out.println("4. Remover Funcionário");
            System.out.println("5. Sair");
            System.out.print("Escolha uma opção: ");
            opcao = scanner.nextInt();
            scanner.nextLine();

            switch (opcao) {
                case 1 -> cadastrarFuncionario();
                case 2 -> controller.listarFuncionarios();
                case 3 -> atualizarFuncionario();
                case 4 -> removerFuncionario();
                case 5 -> System.out.println("Programa Encerrado.");
                default -> System.out.println("Opção inválida.");
            }
        } while (opcao != 5);
    }

    private void cadastrarFuncionario() {
        System.out.println("\nQual tipo de funcionário?");
        System.out.println("1. Desenvolvedor");
        System.out.println("2. Gerente");
        System.out.println("3. Treinador");
        System.out.println("4. Gerente Desenvolvedor");
        System.out.print("Selecione uma opção: ");
        int tipo = scanner.nextInt();
        scanner.nextLine();

        System.out.print("\nNome: ");
        String nome = scanner.nextLine();
        System.out.print("Salário: ");
        double salario = scanner.nextDouble();

        Funcionario funcionario;
        switch (tipo) {
            case 1 -> funcionario = new Desenvolvedor(nome, salario);
            case 2 -> funcionario = new Gerente(nome, salario);
            case 3 -> funcionario = new Treinador(nome, salario);
            case 4 -> funcionario = new GerenteDesenvolvedor(nome, salario);
            default -> funcionario = null;
        }

        if (funcionario != null) {
            controller.adicionarFuncionario(funcionario);
            System.out.println("Funcionário cadastrado com sucesso.");
        } else {
            System.out.println("Tipo inválido.");
        }
    }

    private void atualizarFuncionario() {
        System.out.print("\nNome atual: ");
        String nomeAtual = scanner.nextLine();
        System.out.print("Novo nome: ");
        String nomeNovo = scanner.nextLine();
        System.out.print("Novo salário: ");
        double salario = scanner.nextDouble();

        controller.atualizarFuncionario(nomeAtual, nomeNovo, salario);
        System.out.println("Funcionário atualizado.");
    }

    private void removerFuncionario() {
        System.out.print("\nNome: ");
        String nome= scanner.nextLine();

        controller.removerFuncionario(nome);
        System.out.println("Funcionário removido.");
    }
}
