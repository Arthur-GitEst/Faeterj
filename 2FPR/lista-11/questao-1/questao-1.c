// Desenvolver uma função que remova todos os elementos de uma pilha P do tipo TLista e retorne a
// quantidade de elementos que existiam em P.
// Nota: as regras de manipulação de uma pilha clássica devem ser respeitadas.

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *prox;
} TNo;

typedef struct {
    TNo *topo;
} TLista;

int desempilhar (TLista *pilha);
int empilhar (TLista *pilha, int num);
int contarRemocoes (TLista *pilha);
int topo (TLista *pilha);
// void exibir(TLista L);

int main () {
    TLista pilha;
    pilha.topo = NULL;
    int remocoes;

    empilhar(&pilha, 10);
    topo(&pilha);
    empilhar(&pilha, 20);
    topo(&pilha);
    empilhar(&pilha, 30);
    topo(&pilha);

    remocoes = contarRemocoes(&pilha);

    printf("\nForam removidos %d elementos.", remocoes);

    return 0;
}

int desempilhar (TLista *pilha) {
    if (!pilha->topo) {
        //Pilha Vazia
        return 0;
    } else {
        TNo *aux = pilha->topo;
        pilha->topo = pilha->topo->prox;
        free(aux);
        return 1;
    }
}

int empilhar (TLista *pilha, int num) {
    TNo *novo = (TNo*)malloc(sizeof(TNo));
    
    if (!novo) {
        return 0;
    } else {
        novo->valor = num;
        novo->prox = pilha->topo;
        pilha->topo = novo;
        return 1;
    }
}

int contarRemocoes (TLista *pilha) {
    int cont = 0;
    if (!pilha->topo) {
        return 0;
    } else {
        while (pilha->topo) {
            desempilhar(pilha);
            cont++;
        }
        return cont;
    }
}

int topo (TLista *pilha) {
    int valor = pilha->topo->valor;
    if (!pilha->topo) {
        return 0;
    } else {
        printf("\nValor do Topo: %d\n", valor);
        return 1;
    }
}

// void exibir(TLista L) {
//     TLista aux = L;

//     if (!L) {
//         printf("\nLista Vazia\n");
//     } else {
//         while (aux) {
//             printf("%d ", aux->valor);
//             aux = aux->prox;
//         }
//         printf("\n");
//     }
// }