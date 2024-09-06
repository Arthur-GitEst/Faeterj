#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "TADProduto.h"

struct produto {
    char* identificacao;
    char* codigoBarras;
    float preco;
    int quant;
    // tUnidade* unidades;
};

tProduto* prd_criar (char* id, char* codigo, float preco) {
    tProduto* prd = (tProduto*)malloc(sizeof(tProduto));
    if (prd == NULL) {
        printf("\nMemoria Insuficiente\n");
        exit(1);
    }

    int quant = 0;
    prd->identificacao = (char*)malloc(sizeof(id) + 1);
    strcpy(prd->identificacao, id);
    prd->codigoBarras = (char*)malloc(sizeof(codigo) + 1);
    strcpy(prd->codigoBarras, codigo);
    prd->preco = preco;
    prd->quant = quant;

    return prd;
}

void prd_libera (tProduto* prd) {
    free(prd);
}

char* prd_getProduto (tProduto* prd) {
    char* aux = (char*)malloc(sizeof(tProduto) + 50);
    if (aux == NULL) {
        printf("\nMemoria Insuficiente\n");
        exit(1);
    }

    sprintf(aux, "Id: %s | Codigo: %s | Preco: %.2f | Quantidade: %d"), prd->identificacao, prd->codigoBarras, prd->preco, prd->quant;

    return aux;
}

char* prd_getId (tProduto* prd) {
    char* auxid = (char*)malloc(sizeof(tProduto) + 5);
    if (auxid == NULL) {
        printf("\nMemoria Insuficiente\n");
        exit(1);
    }

    sprintf(auxid, "Id: %s", prd-> identificacao);

    return auxid;
}

char* prd_getCodigo (tProduto* prd) {
    char* auxCodigo = (char*)malloc(sizeof(tProduto) + 9);
    if (auxCodigo == NULL) {
        printf("\nMemoria Insuficiente\n");
        exit(1);
    }

    sprintf(auxCodigo, "Codigo: %s", prd->codigoBarras);

    return auxCodigo;
}

char* prd_getPreco (tProduto* prd) {
    char* auxPreco = (char*)malloc(sizeof(tProduto) + 9);
    if (auxPreco == NULL) {
        printf("\nMemoria Insuficiente\n");
        exit(1);
    }

    sprintf(auxPreco, "Preco: %s", prd->preco);

    return auxPreco;
}

char* prd_getQuant (tProduto* prd) {
    char* auxQuant = (char*)malloc(sizeof(tProduto) + 9);
    if (auxQuant == NULL) {
        printf("\nMemoria Insuficiente\n");
        exit(1);
    }

    sprintf(auxQuant, "Preco: %s", prd->quant);

    return auxQuant;
}

// void prd_setId (tProduto* prd, char* );

void prd_exibe (tProduto* prd) {
    printf("\n%s\n", prd_getProduto);
}

int prd_semelhante (tProduto* prd1, tProduto* prd2) {
    if (strcmp(prd1->identificacao, prd2->identificacao) == 0) {
        return 1;
    } else {
        return 0;
    }
}

void prd_reajuste (tProduto* prd, float valor) {
    float valorReajuste = 1 + (valor / 100);
    prd->preco *= valorReajuste;
}