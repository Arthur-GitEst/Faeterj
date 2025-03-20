// Implementar uma função que, dadas duas listas dinâmicas do tipo TLista, verifique se estas são
// iguais; isto é, contêm os mesmos elementos, na mesma ordem.

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *prox;
} TNo;

typedef TNo* TLista;

int compararListas(TLista lista1, TLista lista2);
int inserir (TLista *L, int num);
void exibir(TLista L);

int main () {
    TLista L1 = NULL, L2 = NULL;

    inserir(&L1, 10);
    inserir(&L1, 20);
    inserir(&L1, 30);
    
    inserir(&L2, 10);
    inserir(&L2, 20);
    inserir(&L2, 30);

    exibir(L1);
    exibir(L2);

    if (compararListas(L1, L2)) {
        printf("\nAs listas sao iguais.\n");
    } else {
        printf("\nAs listas nao sao iguais.\n");
    }

    return 0;
}

int compararListas(TLista lista1, TLista lista2) {
    TLista aux1 = lista1, aux2 = lista2;

    while (aux1 && aux2) {
        if (aux1->valor != aux2->valor) {
            return 0;
        } else {
            aux1 = aux1->prox;
            aux2 = aux2->prox;
        }
    }
    return 1;
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