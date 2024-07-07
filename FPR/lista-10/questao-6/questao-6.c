//Desenvolver uma função que, dada uma lista L1, crie uma nova lista L2, cópia de L1.

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *prox;
} TNo;

typedef TNo* TLista;

void copiarLista (TLista lista1, TLista *lista2);
int inserir (TLista *L, int num);
void exibir(TLista L);

int main () {
    TLista L1 = NULL, L2 = NULL;

    inserir(&L1, 10);
    inserir(&L1, 20);
    inserir(&L1, 30);

    exibir(L1);

    copiarLista(L1, &L2);

    exibir(L2);
    
    return 0;
}

void copiarLista (TLista lista1, TLista *lista2) {
    TLista aux1 = lista1, aux2;

    if (!lista1) {
        printf("\nLista Vazia");
    } else {
        while (aux1) {
            aux2 = (TLista) malloc (sizeof(TNo));
            aux2->valor = aux1->valor;
            aux2->prox = *lista2;
            *lista2 = aux2;
            aux1 = aux1->prox;
        }
    }
}

int inserir (TLista *L, int num) {
    TLista aux;

    aux = (TLista) malloc (sizeof(TNo));

    if (!aux) {
        return 0;
    } else {
        aux->valor = num;
        aux->prox = *L;
        *L = aux;
        return 1;
    }
}

void exibir(TLista L) {
    TLista aux = L;

    if (!L) {
        printf("\nLista Vazia\n");
    } else {
        while (aux) {
            printf("%d ", aux->valor);
            aux = aux->prox;
        }
        printf("\n");
    }
}