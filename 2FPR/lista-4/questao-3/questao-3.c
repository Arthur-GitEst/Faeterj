//Desenvolver uma função que gere uma matriz  Mn×n, nos moldes do exemplo apresentado a  seguir (que consiste em uma matriz de ordem  5) 
#include <stdio.h>
#include <stdlib.h>


void gerarMatriz (int n, int mat[n][n]) {
  int i, j;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      mat[i][j] = i+j+1;
    }
  }
}

void printarMatriz (int n, int mat[n][n]) {
  int i, j;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      printf("%d ", mat[i][j]);
    }
  printf("\n");
  }
}

void main () {
  int n;
  printf("Quantas linhas e colunas: ");
  scanf("%d", &n);

  int matriz[n][n];

  gerarMatriz(n, matriz);
  printarMatriz(n, matriz);
}