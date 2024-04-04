// Considerando a existência de uma matriz de inteiros M, de ordem N (ou seja, o no de linhas e o no de colunas são iguais a
// N), onde N é uma constante, desenvolver uma função que retorne 1 se a seguinte regra for atendida por M (caso contrário,
// o valor 0 deverá ser retornado):

// * A soma dos elementos da diagonal principal deve ser igual à soma dos elementos que estão acima desta
// diagonal, assim como à soma dos elementos abaixo da diagonal.

#include <stdio.h>

int verificarMatriz (int n, int mat[n][n]) {
    int i, j, somaCima = 0, somaBaixo = 0, somaDiag = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i == j) {
                somaDiag += mat[i][j];
            } else
            if (i < j) {
                somaCima += mat[i][j];
            } else {
                somaBaixo += mat[i][j];
            }
        }
    }
    if (somaDiag == somaCima && somaDiag == somaBaixo) {
        return 1;
    } else {
        return 0;
    }
}

void preencherMatriz (int n, int mat[n][n]) {
    int i, j;
    srand(time(NULL));
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            mat[i][j] = rand() % 10;
        }
    }
}

int main () {
    int n = 3;
    int matriz[3][3] = {
        2, 2, 2,
        2, 2, 2,
        2, 2, 2,
    };
    // preencherMatriz(n, matriz);
    int resultado = verificarMatriz(n, matriz);
    if (resultado) {
        printf("Atende a regra\n");
    } else {
        printf("Não atende a regra\n");
    }
}