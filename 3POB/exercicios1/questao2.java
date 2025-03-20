package POB.exercicios1;

import java.text.DecimalFormat;
import java.util.Scanner;

public class questao2 {
    public static void main (String[] args) {
        Scanner ler = new Scanner(System.in);
        DecimalFormat df = new DecimalFormat("0.00");

        System.out.print("Digite a temperatura em Farenheit: ");
        double tempF = ler.nextDouble();

        double tempC = 5.0 / 9.0 * (tempF - 32);
        
        System.out.println("A temperatura em Celsis e igual a: " + df.format(tempC));

        ler.close();
    }
}
