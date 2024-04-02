//Desenvolver uma função que gere uma matriz  Mn×n, nos moldes do exemplo apresentado a  seguir (que consiste em uma matriz de ordem  5) 
#include <stdio.h>
#include <stdlib.h>


void gerarMatriz (int l, int c, int mat[l][c]) {
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

void main () {
  int linhas, colunas;
  printf("Quantas linhas: ");
  scanf("%d", &linhas);
  printf("Quantas colunas: ");
  scanf("%d", &colunas);

  int matriz[linhas][colunas];

  gerarMatriz(linhas, colunas, matriz);
  printarMatriz(linhas, colunas, matriz);
}