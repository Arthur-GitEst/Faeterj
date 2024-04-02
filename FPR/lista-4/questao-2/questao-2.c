//Desenvolver uma função que, dada uma matriz  Mm×n, determine se um número X se encontra  na linha L da matriz.

int encontrarNumero (int l, int c, int mat[l][c], int valor) {
  int i, j;
  for (i = 0; i < l; i++) {
    for (j = 0; j < c; j++) {
      if (mat[i][j] == valor) {
        return (i + 1);
      }
    }
  }
}

void main () {
  int numero, posicao;
  int matriz[3][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
  };

  printf("Insira um numero de 1 a 9: ");
  scanf("%d", &numero);
  posicao = encontrarNumero(3, 3, matriz, numero);
  printf("O numero esta na linha %d", posicao);
  return 0;
}