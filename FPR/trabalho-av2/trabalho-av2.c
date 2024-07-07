#include <stdio.h>
#include <stdlib.h>

#define TAM 10

typedef struct No {
    int valor;
    struct No *prox;
} TNo;

typedef TNo* TLista;
typedef TLista TTabela[TAM];

int inserir (TTabela tabela, int numero);
void exibir (TTabela tabela);

int main () {
    TTabela tabela;
    int i;

    for (i = 0; i < TAM; i++) {
        tabela[i] = NULL;
    }

    inserir (tabela, 99);
    inserir (tabela, 45);
    inserir (tabela, 77);
    inserir (tabela, 67);

    exibir(tabela);


    return 0;
}

int alterar (TTabela tabela, int antigo, int novo) {
    int indiceA = determinarLista(antigo), indiceN = determinarLista(novo);
    TLista auxA = tabela[indiceA], auxN = tabela[indiceN]; 

    auxA = tab
}

int inserir (TTabela tabela, int numero) {
    int indice = determinarLista(numero);
    TLista novo, *lista = &tabela[indice], aux;

    aux = *lista;
    while (aux) {
        if (aux->valor == numero) {
            return 0; //elemento já existe na lista
        }
        aux = aux->prox;
    }

    novo = (TLista) malloc (sizeof(TNo));
    if (!novo) {
        return 0; //Memória não pode ser alocada
    } else {
        //inserindo o novo nó na lista
        novo->valor = numero;  
        novo->prox = *lista; 
        *lista = novo;
    }
    return 1;
}

void exibir (TTabela tabela) {
    //percorrendo a tabela
    for (int i = 0; i < TAM; i++) { 
        printf("Lista %d: ", i);
        //percorrendo a lista
        while (tabela[i]) {
            printf("%d - ", tabela[i]->valor);
            tabela[i] = tabela[i]->prox;
        }
        printf("NULL\n");
    }
}

int determinarLista (int valor) {
    return valor % 10;
}