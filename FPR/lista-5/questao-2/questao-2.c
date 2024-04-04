// Dada uma matriz MLxC, onde L e C são constantes, desenvolver uma função que “troque” os elementos de duas colunas
// c1 e c2, respeitadas as seguintes regras:

// a. A troca só será possível se as colunas c1 e c2 existirem na matriz. Caso existam, a troca será realizada e o valor 1
// retornado pela função; por outro lado, 0 será retornado se uma ou as duas colunas forem inválidas;

// b. Após a troca, a coluna c2 conterá exatamente os elementos originais da coluna c1, na mesma ordem. Porém, os
// valores da coluna c1 serão os originais da c2, na ordem inversa.

#include <stdio.h>
#include <string.h>

void trocarMatrizes (int c1, int c2, int l, int c, int mat[l][c]) {
    int i, j, aux1, aux2 = mat[0][c1];
    for (i = 0, j = (l - 1); i < l; i++, j--) {
        aux1 = mat[i][c2];
        aux2 = mat[i][c1];
        mat[i][c2] = aux2;
        mat[j][c1] = aux1;
    }
}

void preencherMatriz (int l, int c, int mat[l][c]) {
    int i, j;
    srand(time(NULL));
    for (i = 0; i < l; i++) {
        for (j = 0; j < c; j++) {
            mat[i][j] = rand() % 10;
        }
    }
}

void printarMatriz (int l, int c, int mat[l][c]) {
    int i, j;
    for (i = 0; i < l; i++) {
        for (j = 0; j < c; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

int main () {
    int c1 = 1, c2 = 3, l = 6, c = 5, matriz[l][c];
    preencherMatriz(l, c, matriz);
    printarMatriz(l, c, matriz);
    trocarMatrizes(c1, c2, l, c, matriz);
    printf("\n");
    printarMatriz(l, c, matriz);
}