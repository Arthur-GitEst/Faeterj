package POB.exercicios2;

import java.util.Scanner;

//Faça um programa para solicitar o nome e a idade de uma pessoa. Se sua idade for menor que 18 anos, escrever a mensagem: "É menor".

public class exercicio1 {
    public static void main(String[] args) {
        Scanner ler = new Scanner(System.in);
    
        System.out.print("Digite sua idade: ");
        int idade = ler.nextInt();

        if (idade < 18) {
            System.out.println("É menor");
        } else {
            System.out.println("É maior");
        }

        ler.close();
    }
}
