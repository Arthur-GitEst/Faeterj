#include <stdio.h>
#include <stdlib.h>
#include "TADArvore.h"

struct arvore {
    int valor;
    tArvore *esq, *dir;
};

NotArvore *criarNoArvore(tArvore *esq, tArvore *dir, int valor) {
    NotArvore *arv = (NotArvore*)malloc(sizeof(NotArvore));

    arv->esq = esq;
    arv->dir = dir;
    arv->valor = valor;

    return arv;
}

void percorrerArvore(tArvore *raiz) {
    if (raiz->esq != NULL) {
        percorrerArvore(raiz->esq);
    }

    printf("%d ", raiz->valor);

    if (raiz->dir != NULL) {
        percorrerArvore(raiz->dir);
    }
}



