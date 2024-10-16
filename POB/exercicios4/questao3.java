package POB.exercicios4;

import java.util.ArrayList;
import java.util.Scanner;

import javax.swing.text.Style;

// Faça um programa usando listas que armazene o código, o nome e o telefone de 100 pessoas. O programa deve permitir que o usuário faça uma consulta dos dados de uma pessoa a partir de seu código. Esta consulta pode ser repetida se o usuário desejar, caso contrário, o programa deve ser encerrado.

public class questao3 {
    public static void main(String[] args) {
        ArrayList<Integer> codigos = new ArrayList<>();
        ArrayList<String> nomes = new ArrayList<>();
        ArrayList<Integer> telefones = new ArrayList<>();
        Scanner ler = new Scanner(System.in);

        for (int i = 0; i < 101; i++) {
            System.out.printf("Digite o codigo: ");
            int codigo = ler.nextInt();
            System.out.printf("Digite o nome: ");
            String nome = ler.next();
            System.out.printf("Digite o telefone: ");
            int telefone = ler.nextInt();

            codigos.add(codigo);
            nomes.add(nome);
            telefones.add(telefone);
        }

        boolean continuar = true;

        while (continuar) {
            System.err.print("Digite o codigo a ser procurado: ");
            int codigoBusca = ler.nextInt();
            int i;

            for (i = 0; (codigos.get(i) != codigoBusca) && (i < codigos.size()); i++);

            if (i == codigos.size()) {
                System.out.println("Codigo nao existe.");
            } else {
                System.out.println("Codigo: " + codigos.get(i));
                System.out.println("Nome: " + nomes.get(i));
                System.out.println("Telefone: " + codigos.get(i));
            }

            System.out.println("Gostaria de continuar: ");
            
        }
    }
}
