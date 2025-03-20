//Faça uma função que, dada uma matriz Mm×n de  reais, gere a matriz Mt, sua transposta. 

void gerarTransposta (float mat[3][3], float transp[3][3]) {
  int i, j;
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      transp[j][i] = mat[i][j];
    }
  }
}

// 7 8 9  ||  7 4 1
// 4 5 6  ||  8 5 2
// 1 2 3  ||  9 6 3

void printarMatriz (float transp[3][3]) {
  int i, j;
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      printf("%0.f ", transp[i][j]);
    }
    printf("\n");
  }
}

void main () {
  float matriz[3][3] = {
    {7, 8, 9},
    {4, 5, 6},
    {1, 2, 3}
  };
  float transposta[3][3];
  gerarTransposta (matriz, transposta);
  printarMatriz(transposta);
}