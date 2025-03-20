// Dada uma matriz MLxC, onde L e C são constantes, desenvolver uma função que verifique se os elementos da matriz estão
// ordenados de forma crescente. Para isto, as seguintes regras devem ser atendidas:
// a. Os elementos de cada linha devem estar ordenados crescentemente (ou seja, cada elemento será maior ou igual
// àquele da mesma linha, porém da coluna anterior – caso exista);
// b. O primeiro elemento de cada linha deve ser maior ou igual ao último da linha anterior (caso exista).
// Caso a matriz M atenda aos critérios definidos, o valor 1 deverá ser retornado pela função; caso contrário, 0.

#include <stdio.h>

int verificarMatriz (int l, int c, int mat[l][c]) {
    int i, j;
    for (i = 0; i < (l - 1); i++) {
        for (j = 0; j < (c - 1); j++) {
            if (mat[i][j] > mat[i][j+1]) {
                return 0;
            }
        }
        if (mat[i][j] > mat[i+1][0]) {
            return 0;
        }
    }
    for (j = 0; j < (c - 1); j++) {
        if (mat[i][j] > mat[i][j+1]) {
                return 0;
            }
    }
    return 1;
}

int main () {
    int matriz[4][4] = {
        1, 2, 3, 4,
        4, 6, 7, 8,
        9, 10, 10, 12,
        13, 14, 14, 15
    };
    if (verificarMatriz(4, 4, matriz)) {
        printf("Atende as regras\n");
    } else {
        printf("Não atende as regras\n");
    }
}