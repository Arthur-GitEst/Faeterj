#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

struct no {
    int valor;
    tNo *prox;
};

struct fila {
    tNo *front;
    tNo *rear;
};

Fila *criaFila () {
    Fila *novaFila = (Fila*)malloc(sizeof(Fila));
    tNo *dummy = (tNo*)malloc(sizeof(tNo));

    novaFila->front = novaFila->rear = dummy;

    return novaFila;
}

tNo *criaNo (int valor) {
    tNo *novoNo = (tNo*)malloc(sizeof(tNo));

    novoNo->valor = valor;
    novoNo->prox = NULL;

    return novoNo;
}

int enfileirar (Fila *f, int dado) {
    tNo *novoNo = criaNo(dado);

    if (!novoNo) {
        return 0;
    }

    if (filaVazia(f)) {
        f->rear = novoNo;
        f->front->prox = novoNo;
    } else {
        f->rear->prox = novoNo;
        f->rear = novoNo;
    }

    return 1;
}

int desenfileirar(Fila *f) {
    tNo *aux = f->front;

    if (filaVazia(f)) {
        return 0;
    } else {
        f->front->prox = aux->prox;
        free(aux);
    }

    return 1;

}

int mostrafila(Fila *f) {
    if (filaVazia(f)) {
        return 0;
    } else {
        tNo *aux = f->front->prox;
        
        while (aux != f->rear) {
            printf("%d\n", aux->valor);
            aux = aux->prox;
        }
        printf("\n");
    }

    return 1;
}

void liberaFila(Fila *f) {

    while (!filaVazia(f)) {
        desenfileirar(f);
    }
}

int filaVazia(Fila *f) {
    return (f->front == f->rear);
}