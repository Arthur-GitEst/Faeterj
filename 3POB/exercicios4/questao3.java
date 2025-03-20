package POB.exercicios4;

import java.util.ArrayList;
import java.util.Scanner;

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

        String continuar;

        do {
            System.out.print("Digite o codigo a ser procurado: ");
            int codigoBusca = ler.nextInt();
            
            if (codigos.contains(codigoBusca)) {
                int index = codigos.indexOf(codigoBusca);
                System.out.println("Código: " + codigos.get(index));
                System.out.println("Nome: " + nomes.get(index));
                System.out.println("Telefone: " + telefones.get(index));
            } else {
                System.out.println("Código inválido.");
            }

            System.out.println("Gostaria de continuar? (S ou N): ");
            continuar = ler.next().toUpperCase(); 
        } while (continuar.equals("S"));

        ler.close();
    }
}
