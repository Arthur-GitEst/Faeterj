package POB.exercicios2;

import java.util.Scanner;

// Crie um programa para solicitar o ano atual e o ano de nascimento de uma pessoa. Calcular sua idade aproximada e informá-la. Se sua idade for inferior a 16 anos, escrever a mensagem "Não pode votar"; caso contrário, emitir a mensagem "É eleitor".

public class questao2 {
    public static void main(String[] args) {
        Scanner ler = new Scanner(System.in);
    
        System.out.print("Ano atual: ");
        int anoAtual = ler.nextInt();

        System.out.println("");

        System.out.print("Ano de nascimento: ");
        int anoNasci = ler.nextInt();

        int idade = anoAtual - anoNasci;

        if (idade < 16) {
            System.out.println("Não pode votar");
        } else {
            System.out.println("É eleitor");
        }

        ler.close();
    }
}
