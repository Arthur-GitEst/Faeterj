#include "TADData.h"
#include "TADUnidade.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct unidade {
  Data *fabricacao;
  int lote;
};

/* x Criar, liberar,exibir
x get para cada atributo
 set para cada atributo
 Idade : retorna o número de dias entre a data alvo e a data de fabricação
 Saber se uma unidade “é menor” que outra: se foi fabricado há menos tempo que o
outro (menor idade). Caso os dois produtos tenham a mesma idade, considerar o lote
Ex P1  fabricado em 12/12/2019 lote 3
P2  fabricado em 1/12/2019 lote 5
P3  fabricado em 1/12/2019 lote 2
P1 < P2  True
P2<P3  False
 getUnidade: retorna uma string com os valores */


tUnidade* uni_cria (int dia,int mes, int ano, int lote){
    tUnidade* u = (tUnidade*) malloc(sizeof(tUnidade));
    if (u == NULL) {
        printf("Memória insuficiente!\n");
        exit(1);
    }
   u->fabricacao = data_cria(dia, mes, ano);
   u->lote = lote;
} 

void uni_libera (tUnidade* u){
    data_libera(u->fabricacao);
    free(u);
}

void uni_exibe(tUnidade* u){
    printf("\nData de Fabricação: %s \n Lote: %i \n)", data_getData(u->fabricacao), lote);
}

char* uni_getUnidade(tUnidade* unidade){
    char* unidade = (char*)malloc(sizeof(*unidade) + 33);
    if (unidade== NULL) {
      printf("Memória insuficiente!\n");
      exit(1);
    }
    sprintf(unidade, " Data de Fabricação: %s | Lote: %i )", data_getData(unidade->fabricacao), lote);
    return unidade;
}

char* uni_getFabricacao(tUnidade* fabricacao){
    char* fabricacao = (char*)malloc(sizeof(*fabricacao) + 23);
    if (fabricacao== NULL) {
      printf("Memória insuficiente!\n");
      exit(1);
    }
    sprintf(fabricacao," Data de Fabricação: %s )", data_getData(fabricacao->fabricacao));
    return fabricacao;
}

char* uni_getLote(tUnidade* lote){
    char* lote = (char*)malloc(sizeof(*lote) + 9);
    if (lote== NULL) {
      printf("Memória insuficiente!\n");
      exit(1);
    }
    sprintf(lote," Lote: %i )", lote);
    return lote;
}

int uni_