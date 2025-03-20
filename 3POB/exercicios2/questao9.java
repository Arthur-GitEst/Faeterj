package POB.exercicios2;

import java.util.Scanner;

// Dado três valores X,Y,Z, verificar se eles podem ser o comprimento dos lados de um triângulo e, se forem, verificar se é um triângulo, equilátero, isósceles ou escaleno. Se eles não formarem um triângulo, escreverem uma mensagem. Obs: O comprimento de cada lado de um triângulo é menor do que a soma dos comprimentos dos outros dois lados; chama-se triângulo equilátero ao triângulo que tem os comprimentos dos três lados iguais; chama-se triângulo isósceles ao triângulo que tem os comprimentos de dois lados iguais. Portanto, todo triângulo equilátero é também isósceles; chama-se triângulo escaleno ao triângulo que tem os comprimentos dos três lados diferentes.

public class questao9 {
    public static void main(String[] args) {
        Scanner ler = new Scanner(System.in);

        System.out.print("Valor de x: ");
        int x = ler.nextInt();
        System.out.print("Valor de y: ");
        int y = ler.nextInt();
        System.out.print("Valor de z: ");
        int z = ler.nextInt();

        if ((x < 0 || y < 0 || z < 0) || (x >= y + z || y >= x + z || z >= y + x)) {
            System.out.println("Não é um triângulo.");
        } else if (x == y && y == z) {
            System.out.println("O triângulo é equilátero.");
        } else if ((x == y && y != z) || (y == z && z != x) || (z == x && x != y)) {
            System.out.println("O triângulo é isósceles.");
        } else {
            System.out.println("O triângulo é escaleno.");
        }

        ler.close();
    }
}
