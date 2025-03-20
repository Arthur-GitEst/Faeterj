// Implementar uma função que crie uma lista encadeada (dinâmica) com os N primeiros termos
// de uma PA (progressão aritmética) de razão R e primeiro termo igual a A1.

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *prox;
} TNo;

typedef TNo* TLista;

void criarLista (TLista *L, int N, int A1, int R);
int inserir (TLista *L, int num);
void exibir(TLista L);

int main () {
    TLista L1 = NULL;
        
    criarLista(&L1, 5, 6, 4);

    exibir(L1);

    return 0;
}

void criarLista (TLista *L, int N, int A1, int R) {
    int ultimo, i;

    ultimo = A1 + (N-1) * R;

    for (i = 1; i < N; i++) {
        inserir(L, ultimo);
        ultimo -= R;
    }

    inserir(L, A1);
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
        printf("\n");
        while (aux) {
            printf("%d ", aux->valor);
            aux = aux->prox;
        }
        printf("\n");
    }
}