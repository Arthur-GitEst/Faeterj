#include <stdio.h> 
#include "arvoreB.h"

int main() {

  insere(8);
  insere(9);
  insere(10);
  insere(11);
  insere(15);
  insere(16);
  insere(17);
  insere(18);
  insere(20);
  insere(23);

  percorre(raiz);

  remover (20, raiz);
  printf("\n");
  percorre(raiz);
}