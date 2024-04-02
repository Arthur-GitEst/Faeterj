//Implementar uma função que, dada uma matriz  Mm×n, gere um vetor V de tamanho n, onde  cada elemento do vetor consiste na soma dos  elementos de uma coluna de M. Ou seja, o  elemento V[0] consiste na soma dos elementos  da primeira coluna de M, o elemento V[1]  consiste na soma dos elementos da segunda  coluna de M, e assim por diante. 

#include <stdio.h>

void somarColunas (int l, int c, int mat[l][c], int vet[c]) {
  int i, j;
  for (j = 0; j < c; j++) {
    int soma = 0;
    for (i = 0; i < l; i++) {
      soma += mat[i][j];
    }
    vet[j] = soma;
  }
}

void printarVetor (int c, int vet[c]) {
  int i;
  for (i = 0; i < c; i++) {
    printf("%d ", vet[i]);
  }
}

void main () {
  int matriz[3][3] = {
    {2, 4, 6},
    {2, 4, 6},
    {2, 4, 6},
  };
  int vetor[3];
  somarColunas (3, 3, matriz, vetor);
  printarVetor (3, vetor);
}