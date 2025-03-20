package POB.exercicios2;

import java.util.Scanner;

// Faça um programa que leia o código, a quantidade, o preço unitário e a forma de pagamento (1 - Dinheiro, 2 - Cheque, 3 - Cartão débito, 4 - Cartão crédito) de um produto. Pagamentos em dinheiro recebem um desconto de 10%, em cartão de débito 5%, em cartão de crédito 3%  e em cheque 2%. O programa deve informar o valor do desconto e o valor final a pagar.

public class questao8 {
    public static void main(String[] args) {
        Scanner ler = new Scanner(System.in);

        System.out.print("Insira o código: ");
        int codigo = ler.nextInt();
        System.out.print("Insira a quantidade: ");
        int quantidade = ler.nextInt();
        System.out.print("Insira a preço unitário: ");
        int preco = ler.nextInt();

        int opcao;
        double desconto;
        double novoPreco;

        do {
            System.out.println("\n");
            System.out.println("Escolha a forma de pagamento.");
            System.out.println("1 - Dinheiro");
            System.out.println("2 - Cheque");
            System.out.println("3 - Débito");
            System.out.println("4 - Crédito");
            System.out.println("0 - Cancelar");
            System.out.print("Escolha uma opção: ");
            opcao = ler.nextInt();

            switch (opcao) {
                case 1:
                    desconto = preco * 0.1;
                    novoPreco = preco - desconto;
                    System.out.println("Desconto: " + (desconto * quantidade));
                    System.out.println("Valor final: " + (novoPreco * quantidade));
                    opcao = 0;
                    break;
                case 2:
                    desconto = preco * 0.02;
                    novoPreco = preco - desconto;
                    System.out.println("Desconto: " + (desconto * quantidade));
                    System.out.println("Valor final: " + (novoPreco * quantidade));
                    opcao = 0;
                    break;
                case 3:
                    desconto = preco * 0.05;
                    novoPreco = preco - desconto;
                    System.out.println("Desconto: " + (desconto * quantidade));
                    System.out.println("Valor final: " + (novoPreco * quantidade));
                    opcao = 0;
                    break;
                case 4:
                    desconto = preco * 0.03;
                    novoPreco = preco - desconto;
                    System.out.println("Desconto: " + (desconto * quantidade));
                    System.out.println("Valor final: " + (novoPreco * quantidade));
                    opcao = 0;
                    break;
                default:
                    System.out.println("Opção Inválida");
                    break;
            }
        } while (opcao != 0);

        ler.close();
    }
}
