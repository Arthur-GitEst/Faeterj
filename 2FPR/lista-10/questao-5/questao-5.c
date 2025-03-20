//Implementar uma função que, dadas duas listas dinâmicas do tipo TLista, verifique se elas
// possuem os mesmos elementos, independente da ordem na qual apareçam.

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *prox;
} TNo;

typedef TNo* TLista;

int compararListas (TLista lista1, TLista lista2);
int verificarIguais (TLista listaA, TLista listaB);
int buscar (TLista L, int num);
int inserir (TLista *L, int num);
void exibir (TLista L);


int main () {
    TLista L1 = NULL, L2 = NULL;

    inserir(&L1, 10);
    inserir(&L1, 30);
    inserir(&L1, 20);
    
    inserir(&L2, 20);
    inserir(&L2, 10);
    inserir(&L2, 30);

    exibir(L1);
    exibir(L2);

    if (compararListas(L1, L2) == 1) {
        printf("\nAs listas possuem elementos iguais.");
    } else {
        printf("\nAs listas nao possuem elementos iguais.");
    }

    return 0;
}

int compararListas (TLista lista1, TLista lista2) {
    return verificarIguais(lista1, lista2) && verificarIguais(lista2, lista1);
}

int verificarIguais (TLista listaA, TLista listaB) {
    TLista auxA = listaA;

    while (auxA) {
        if (buscar(listaB, auxA->valor) == 0) {
            return 0;
        } else {
            auxA = auxA->prox;
        }
    }
    return 1;
}

int buscar (TLista L, int num) {
    TLista aux = L;

    while(aux) {
        if (aux->valor == num) {
            return 1;
        } else {
            aux = aux->prox;
        }
    }
    return 0;
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
