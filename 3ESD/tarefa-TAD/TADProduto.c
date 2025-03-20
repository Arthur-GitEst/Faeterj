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
    tUnidade* unidades;
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

    sprintf(auxid, "Id: %s", prd->identificacao);

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
    char* auxPreco = (char*)malloc(sizeof(tProduto) + 8);
    if (auxPreco == NULL) {
        printf("\nMemoria Insuficiente\n");
        exit(1);
    }

    sprintf(auxPreco, "Preco: %.2f", prd->preco);

    return auxPreco;
}

char* prd_getQuant (tProduto* prd) {
    char* auxQuant = (char*)malloc(sizeof(tProduto) + 13);
    if (auxQuant == NULL) {
        printf("\nMemoria Insuficiente\n");
        exit(1);
    }

    sprintf(auxQuant, "Quantidade: %d", prd->quant);

    return auxQuant;
}

void prd_setId (tProduto* prd, char* novoId) {
    prd->identificacao = (char*)malloc(strlen(novoId) + 1);
    if (prd->identificacao == NULL) {
        printf("\nMemoria Insuficiente\n");
        exit(1);
    }

    strcpy(prd->identificacao, novoId);
}

void prd_setCodigo (tProduto* prd, char* novoCodigo) {
    prd->codigoBarras = (char*)malloc(strlen(novoCodigo) + 1);
    if (prd->codigoBarras == NULL) {
        printf("\nMemoria Insuficiente\n");
        exit(1);
    }

    strcpy(prd->codigoBarras, novoCodigo);
}

void prd_setPreco (tProduto* prd, float novoPreco) {
    prd->preco = novoPreco;
}

void prd_setQuant (tProduto* prd, int novaQuant) {
    prd->quant = novaQuant;
}

void prd_exibeProduto (tProduto* prd) {
    printf("\n%s\n", prd_getProduto);
}

void prd_exibeID (tProduto* prd) {
    printf("\n%s\n", prd_getId);
}

void prd_exibeCodigo (tProduto* prd) {
    printf("\n%s\n", prd_getCodigo);
}

void prd_exibePreco (tProduto* prd) {
    printf("\n%s\n", prd_getPreco);
}

void prd_exibeQuant (tProduto* prd) {
    printf("\n%s\n", prd_getQuant);
}

int prd_semelhante (tProduto* prd1, tProduto* prd2) {
    if (strcmp(prd1->identificacao, prd2->identificacao) == 0) {
        return 1;
    } else {
        return 0;
    }
}

void prd_reajuste (tProduto* prd, float valor) {
    float valorReajuste = prd->preco * (valor / 100);
    prd_setPreco(prd, valorReajuste);
}