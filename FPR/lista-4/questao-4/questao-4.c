//Fazer uma função que, dada uma matriz Mn×n,  determine se ela é simétrica. 
#include <stdio.h>

int verficarSimetria (int l, int c, int mat[l][c]) {
  int i, j;
  for (i = 0; i < l; i++) {
    for (j = 0; j < c; j++) {
      if (mat[i][j] != mat[j][i]) {
        return 0;
      }
    }
  }
  return 1;
}

void main () {
  int matriz[3][3] = {
    {2, 4, 6},
    {4, 4, 4},
    {6, 4, 6}
  };
  int resultado = verficarSimetria(3, 3, matriz);
  if (resultado) {
    printf("E simetrica");
  } else {
    printf("Nao e simetrica");
  }
}