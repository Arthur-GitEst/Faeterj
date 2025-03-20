//Fazer uma função que, dada uma matriz Mn×n,  determine se ela é simétrica. 
#include <stdio.h>

int verficarSimetria (int n, int mat[n][n]) {
  int i, j;
  for (i = 0; i < n-1; i++) {
    for (j = i+1; j < n; j++) {
      if (mat[i][j] != mat[j][i]) {
        return 0;
      }
    }
  }
  return 1;
}

void preencherMatrizSimetrica (int n, int mat[n][n]) {
  int i, j;
  srand(time(NULL));
  for (i = 0; i < n-1; i++) {
    for (j = i; j < n; j++)
    {
      mat[i][j] = mat[j][i] = rand() % 100;
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
  int matriz[5][5];
  preencherMatrizSimetrica(5, matriz);
  int resultado = verficarSimetria(5, matriz);
  printarMatriz(4, matriz);
  if (resultado) {
    printf("É simetrica\n");
  } else {
    printf("Não É simetrica\n");
  }
}