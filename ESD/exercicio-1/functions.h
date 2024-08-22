#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void preencherEstatico (char *vNomes[], int quant) {
    char nome[100];
    int i, tam;

    for (i = 0; i < quant; i++) {
        scanf("%s", nome);
        tam = strlen(nome) + 1;
        vNomes[i] = (char*)malloc(tam);
        strcpy(vNomes[i], nome);
    }
}

void preencherDinamico (char **vNomes, int quant) {
  char nome[100];
  int i, tam;

  for (i = 0; i < quant; i++) {
    printf("Digite um nome: ");
    scanf("%s", nome);
    tam = strlen(nome) + 1;
    vNomes[i] = (char*)malloc(tam);
    strcpy(vNomes[i], nome);
  }
}

void trocar (char **n1, char **n2) {
  char *temp = *n1;
  *n1 = *n2;
  *n2 = temp;
}

void ordenar (char **Vnomes, int quant) {
  int i, j, aux;

  for (i = 0; i < quant - 1; i++) {
    aux = 0;
    for (j = 0; j < quant - i - 1; j++) {
      if (strcmp(Vnomes[j], Vnomes[j+1]) > 0) {
        trocar(&Vnomes[j], &Vnomes[j+1]);
        aux = 1;
      }
    }
    if (aux == 0) {
      break;
    }
  }
}

void exibir (char **vNomes, int quant) {
    int i;

    printf("\n");
    for (i = 0; i < quant; i++) {
        printf("%s\n", vNomes[i]);
    }
}