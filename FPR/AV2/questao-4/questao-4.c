#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *prox;
} TNo;

typedef TNo* TLista;

TLista questao04 (TLista L, int pos, int quant, int passo);
int inserir (TLista *L, int num);
void exibir(TLista L);

int main () {
    TLista L = NULL;

    inserir(&L, 10);
    inserir(&L, 20);
    inserir(&L, 30);
    inserir(&L, 40);
    inserir(&L, 50);
    inserir(&L, 60);
    inserir(&L, 70);
    inserir(&L, 80);
    inserir(&L, 90);
    inserir(&L, 100);
    inserir(&L, 110);
    inserir(&L, 120);

    TLista nova = questao04(L, 4, 4, 3);

    exibir(nova);

    return 0;
}

TLista questao04 (TLista L, int pos, int quant, int passo) {
    TLista aux = L, novaL = NULL, novoNo;
    int cont = 1, passoCont = 1;

    while (cont < pos) {
        aux = aux->prox;
        cont++;
    }

    inserir(&novaL, aux->valor);
    aux = aux->prox;

    if (!aux) {
        return novaL;
    } else {
        cont = 1;
        while ((aux) && (cont < quant)) {
            if (passoCont == passo) {
                inserir(&novaL, aux->valor);
                aux = aux->prox;
                passoCont = 1;
                cont++;
            } else {
                aux = aux->prox;
                passoCont++;
            }
        }
        return novaL;
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
