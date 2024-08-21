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

void exibir (char **vNomes, int quant) {
    int i;

    for (i = 0; i < quant; i++) {
        printf("%s\n", vNomes[i]);
    }
}