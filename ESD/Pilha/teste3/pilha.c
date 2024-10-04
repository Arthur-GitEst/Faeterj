#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

struct no {
    int valor;
    tNo *prox;
};

struct pilha {
    tNo *topo;
};

Pilha *criaPilha () {
    Pilha *novaPilha = (Pilha*)malloc(sizeof(Pilha));

    novaPilha->topo = NULL;

    return novaPilha;
}

tNo *criaNo (int valor) {
    tNo *novoNo = (tNo*)malloc(sizeof(tNo));

    novoNo->valor = valor;
    novoNo->prox = NULL;

    return novoNo;
}

int push(Pilha *p, int dado) {
    tNo *novoNo = criaNo(dado);

    if (!novoNo) {
        return 0;
    }

    novoNo->prox = p->topo;
    p->topo = novoNo;

    return 1;
}

int pop(Pilha *p, int *dado) {
    *dado = p->topo->valor;
    tNo *aux;
    
    aux = p->topo;
    p->topo = p->topo->prox;
    free(aux);

    return 0;
}

void exibePilha(Pilha *p) {
    tNo *aux = p->topo;
    while (aux != NULL) {
        printf("%d\n", aux->valor);
        aux = aux->prox;
    }
}



