package POB.exercicios3;

//Faça um programa que calcule e escreva no vídeo o somatório dos números inteiros de 1 até 50.

public class questao2 {
    public static void main (String[] args) {
        int soma = 0;

        for (int i = 0; i < 50; i++) {
            soma += i;
        }
        
        System.out.println("Somatorio igual a: "+ soma);
    }
}
