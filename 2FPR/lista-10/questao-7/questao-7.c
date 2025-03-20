// Desenvolver uma função que insira um número inteiro N na i-ésima posição de uma lista
// encadeada L.
// Observação: caso a posição i informada seja inválida, a função deverá retornar o valor 0; caso
// contrário, o retorno será igual a 1.

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *prox;
} TNo;

typedef TNo* TLista;

int inserirNaPosicao (TLista *L, int posicao, int num);
int inserir (TLista *L, int num);
void exibir(TLista L);

int main () {
    TLista L1 = NULL, L2 = NULL;

    inserir(&L1, 10);
    inserir(&L1, 20);
    inserir(&L1, 30);

    exibir(L1);

    if (inserirNaPosicao(&L1, 3, 40)) {
        printf("\nValor Inserido.\n");
    } else {
        printf("\nValor nao pode ser inserido.\n");
    }

    exibir(L1);
    
    return 0;
}

int inserirNaPosicao (TLista *L, int posicao, int num) {
    TLista novo, aux1, aux2 = *L;
    int cont = 1;

    if (posicao < 1) {
        return 0;
    } else {
        if (posicao == 1) {
            novo = (TLista) malloc (sizeof(TNo));

            if (!novo) {
                return 0;
            } else {
                novo->valor = num;
                novo->prox = *L;
                *L = novo;
            }
        } else {
            if (!(*L)) {
                return 0;
            } else {
                aux1 = *L;
                aux2 = aux1->prox;

                while (aux2 && (cont < posicao - 1)) {
                    cont++;
                    aux1 = aux2;
                    aux2 = aux2->prox;
                }

                if (cont == posicao - 1) {
                    novo = (TLista) malloc (sizeof(TNo));

                    if (!novo) {
                        return 0;
                    } else {
                        novo->valor = num;
                        novo->prox = aux2;
                        aux1->prox = novo;
                    }
                } else {
                    return 0;
                }
            }
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
        printf("\n");
        while (aux) {
            printf("%d ", aux->valor);
            aux = aux->prox;
        }
        printf("\n");
    }
}