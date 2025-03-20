package POB.exercicioHeranca.fabrica.controle;

import java.util.ArrayList;
import java.util.Scanner;

import POB.exercicioHeranca.fabrica.dominio.Cliente;
import POB.exercicioHeranca.fabrica.dominio.PessoaFisica;
import POB.exercicioHeranca.fabrica.dominio.PessoaJuridica;

public class ControlaCliente {
    public static void main(String[] args) {
        Scanner ler = new Scanner(System.in);
        ArrayList<Cliente> clientes = new ArrayList<>(); 

        boolean continuar = true;

        while (continuar) {
            System.out.println("\nEscolha o tipo de Cliente:");
            System.out.println("1. Pessoa Fisica");
            System.out.println("2. Pessoa Juridica");
            System.out.println("3. Sair");
            System.out.print("Opção: ");
            int opcao = ler.nextInt();
            ler.nextLine();

            if (opcao == 1) {
                System.out.print("Nome: ");
                String nome = ler.nextLine();
                System.out.print("CPF: ");
                String cpf = ler.nextLine();
                System.out.print("Endereço: ");
                String endereco = ler.nextLine();
                System.out.print("Telefone: ");
                String telefone = ler.nextLine();
                ler.nextLine();

                PessoaFisica pf = new PessoaFisica(nome, cpf, endereco, telefone);
                clientes.add(pf);
            } else if (opcao == 2) {
                System.out.print("CNPJ: ");
                String cnpj = ler.nextLine();
                System.out.print("Razão Social: ");
                String razaoSocial = ler.nextLine();
                System.out.print("Endereço: ");
                String endereco = ler.nextLine();
                System.out.print("Telefone: ");
                String telefone = ler.nextLine();
                ler.nextLine();

                PessoaJuridica pj = new PessoaJuridica(cnpj, razaoSocial, endereco, telefone);
                clientes.add(pj);
            } else if (opcao == 3) {
                continuar = false;
            } else {
                System.out.println("Opção Inválida.");
            }
        }

        ler.close();

        System.err.println("Relatório de Clientes: ");
        System.out.println();
        for (Cliente c : clientes) {
            c.mostrarInfo();
            System.out.println();
        }
    }
}
