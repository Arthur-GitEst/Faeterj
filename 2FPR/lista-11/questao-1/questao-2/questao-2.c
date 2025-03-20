// Dada uma fila F, do tipo TLista, implementar uma função que remova de F todos os divisores do número
// inteiro N e, ao final, retorne a quantidade de remoções realizadas.
// Notas: i. as regras de manipulação de uma fila clássica devem ser respeitadas; ii. Caso alguma
// estrutura auxiliar seja necessária, esta deverá ser uma fila ou uma pilha.

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *prox;
} TNo;

typedef struct {
    TNo *direita, *esquerda;
} TLista;

int enfilar (TLista *F, int num);
int desenfilar (TLista *F);
int removerDivisores (TLista *F, int N);

int main () {
    TLista F;
    F.esquerda = NULL;
    F.direita = NULL;
    int remocoes;

    enfilar(&F, 2);
    enfilar(&F, 6);
    enfilar(&F, 9);
    enfilar(&F, 14);
    enfilar(&F, 16);
    enfilar(&F, 23);
    enfilar(&F, 27);

    remocoes = removerDivisores(&F, 2);

    printf("\nForam removidos %d divisores.\n", remocoes);

    return 0;
}

int removerDivisores (TLista *F, int N) {
    TLista aux;
    aux.esquerda = NULL;
    aux.direita = NULL;
    int cont = 0, valor;

    while (F->esquerda != NULL) {
        valor = desenfilar(F);
        if ((valor % N) == 0) {
            cont++;
        } else {
            enfilar(&aux, valor);
        }
    }

    while(aux.esquerda != NULL) {
        enfilar(F, desenfilar(&aux));
    }
    return cont;
}

int enfilar (TLista *F, int num) {
    TNo *novo = (TNo*)malloc(sizeof(TNo));
    if (!novo) {
        return 0;
    } else {
        novo->valor = num;
        novo->prox = NULL;
        if (F->direita == NULL) {
            F->direita = novo;
            F->esquerda = novo;
        }
        F->direita->prox = novo;
        F->direita = novo;
    }
}

int desenfilar (TLista *F) {
    TNo *aux = F->esquerda;
    int valor = aux->valor;
    if (!F->esquerda) {
        return -1;
    } else {
        F->esquerda = F->esquerda->prox;
        if (F->esquerda == NULL) {
            F->direita = NULL;
        }
        free(aux);
        return valor;
    }
}