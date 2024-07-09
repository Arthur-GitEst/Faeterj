//Arthur Queiroz Esterqui de Barros
//Implementação do Trabalho da AV2 sobre Listas Encadeadas em Tabela Hash

#include <stdio.h>
#include <stdlib.h>

#define TAM 10

typedef struct No {
    int valor;
    struct No *prox;
} TNo;

typedef TNo* TLista;
typedef TLista TTabela[TAM];

int remover (TTabela tabela, int numero);
int alterar (TTabela tabela, int antigo, int novo);
int inserir (TTabela tabela, int numero);
int buscar (TTabela tabela, int numero);
void exibir (TTabela tabela);
int determinarLista (int valor);

int main () {
    TTabela tabela;
    int i;

    for (i = 0; i < TAM; i++) {
        tabela[i] = NULL;
    }

    if (inserir(tabela, 99)) {
        printf("\nNumero 99 inserido\n");
    } else {
        printf("\nNumero 99 ja existe\n");
    }
    if (inserir(tabela, 45)) {
        printf("\nNumero 45 inserido\n");
    } else {
        printf("\nNumero 45 ja existe\n");
    }
    if (inserir(tabela, 67)) {
        printf("\nNumero 67 inserido\n");
    } else {
        printf("\nNumero 67 ja existe\n");
    }
    if (inserir(tabela, 77)) {
        printf("\nNumero 77 inserido\n");
    } else {
        printf("\nNumero 77 ja existe\n");
    }
    if (inserir(tabela, 77)) {
        printf("\nNumero 77 inserido\n");
    } else {
        printf("\nNumero 77 ja existe\n");
    }

    alterar(tabela, 67, 89);

    exibir(tabela);

    if (buscar(tabela, 77)) {
        printf("\nNumero 77 Encontrado.\n");
    } else {
        printf("\nNumero 77 nao Encontrado.\n");
    }

    if (remover(tabela, 45)) {
        printf("\nNumero 45 removido com sucesso\n");
    } else {
        printf("\nNumero 45 nao encontrado\n");
    }
    if (remover(tabela, 22)) {
        printf("\nNumero 22 removido com sucesso\n");
    } else {
        printf("\nNumero 22 nao encontrado\n");
    }

    exibir(tabela);

    return 0;
}

int remover (TTabela tabela, int numero) {
    int indice = determinarLista(numero);
    TLista aux = tabela[indice], auxAnterior = NULL;

    //Percorrendo a lista
    while (aux) {
        //Encontrando o valor a ser removido
        if (aux->valor == numero) {
            if (!auxAnterior) {
                tabela[indice] = aux->prox;
            } else {
                auxAnterior = aux->prox;
            }
            //Removendo o valor
            free(aux);
            return 1;
        }
    }
    //Valor não encontrado
    return 0;
}

int alterar (TTabela tabela, int antigo, int novo) {
    int indiceA = determinarLista(antigo), indiceN = determinarLista(novo);
    TLista auxA = tabela[indiceA], auxN = tabela[indiceN], auxAnterior = NULL; 

    //Procurando valor novo para evitar repetições
    while (auxN) {
        if(auxN->valor == novo) {
            //O valor já existe na tabela
            return 0;
        } else {
            auxN = auxN->prox;
        }
    }

    //Procurando valor antigo
    while (auxA) {
        if (auxA->valor == antigo) {
            if (!auxAnterior) {
                tabela[indiceA] = auxA->prox;
            } else {
                auxAnterior->prox = auxA->prox;
            }
            //Substituindo valor antigo pelo novo
            free(auxA);
            inserir(tabela, novo);
            return 1;
        }
        auxAnterior = auxA;
        auxA = auxA->prox;
    }
    //Valor antigo não encontrado
    return 0;
}

int inserir (TTabela tabela, int numero) {
    int indice = determinarLista(numero);
    TLista novo, *lista = &tabela[indice], aux;

    //Verificando se o valor já existe na tabela
    aux = *lista;
    while (aux) {
        if (aux->valor == numero) {
            //O valor já existe na tabela
            return 0; 
        }
        aux = aux->prox;
    }

    novo = (TLista) malloc (sizeof(TNo));
    if (!novo) {
        //Memória não pode ser alocada
        return 0; 
    } else {
        //Inserindo o novo nó na lista
        novo->valor = numero;  
        novo->prox = *lista; 
        *lista = novo;
    }
    return 1;
}

int buscar (TTabela tabela, int numero) {
    int indice = determinarLista(numero);
    TLista aux = tabela[indice];

    //Percorrendo a lista
    while (aux) {
        if (aux->valor == numero) {
            //Valor encontrado
            return 1;
        }
    }
    //Valor não encontrado
    return 0;
}

void exibir (TTabela tabela) {
    int cont;
    TLista aux;
    printf("\n");
    //Percorrendo a tabela
    for (int i = 0; i < TAM; i++) { 
        aux = tabela[i];
        printf("Lista %d: ", i);
        if (!aux) {
            printf("Vazia");
        }
        //Percorrendo a lista
        cont = 0;
        while (aux) {
            if (cont == 0) {
                printf("%d ", aux->valor);
                aux = aux->prox;
                cont++;
            } else {
                printf("- %d ", aux->valor);
                aux = aux->prox;
            }
        }
        printf("\n");
    }
}

int determinarLista (int valor) {
    return valor % 10;
}