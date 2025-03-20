#include <stdio.h>
#include "arvoreBEstrela.h"
#include <stdlib.h>
#include <time.h>
int uniqueRandom(int size);

int main(int argc, const char * argv[]) {
    bt_payload entry, *found;
    BTHANDLE tree = bt_create("teste", 64);
    srand(time(NULL));
	uniqueRandom(100);
    /* Insere 100 entradas aleatórias */
    for (int i = 0; i < 100; i++) {
        entry.key = uniqueRandom(0);
        entry.value = i;
        bt_put(tree, entry);
    }
    /* Busca 100 entradas aleatórias */
    for (int i = 0; i < 100; i++) {
        found = bt_get(tree, i);
        if (found) {
            printf("Chave: %u\n Valor: %u\n\n", found->key, found->value);
        }
    }
    return 0;
}

/* Se |size| for > 0, a função gerará um vetor estático com |size| elementos. Em chamadas subsequentes, |size| deve ser 0 e a função retornará um número aleatório único no intervalo de 0 a |size|. */

int uniqueRandom(int size) {
    int i, n;
    static int numNums = 0;
    static int *numArr = NULL;
    if (size > 0) {
        numArr = malloc (sizeof(int) * size);
        for (i = 0; i  < size; i++) numArr[i] = i;
        numNums = size;
        return 0;
    }
    if (numNums == 0)  /* Nenhum número restante */
        return 0;
    
    n = rand() % numNums;
    i = numArr[n];
    numArr[n] = numArr[numNums-1];
    numNums--;
    if (numNums == 0) {  /*Libera a memória de numArr quando não há mais números únicos */
        free (numArr);
        numArr = 0;
    }
    return i;
}