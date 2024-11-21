package POB.exercicios2;

import java.util.Scanner;

// Faça um programa para solicitar o nome e as duas notas e um aluno. Calcular sua média e informá-la. Se ela for inferior a 7, escrever "Reprovado”; caso contrário escrever "Aprovado".

public class questao3 {
    public static void main(String[] args) {
        Scanner ler = new Scanner(System.in);
    
        System.out.print("Digite seu nome: ");
        String nome = ler.next();

        System.out.println("");

        System.out.print("Nota AV1: ");
        int av1 = ler.nextInt();

        System.out.println("");

        System.out.print("Nota AV2: ");
        int av2 = ler.nextInt();

        System.out.println("");

        double media = (av1 + av2) / 2;

        if (media < 7) {
            System.out.println("Reprovado");
        } else {
            System.out.println("Aprovado");
        }

        ler.close();
    }
}
