#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct lista {
    int *vNos;
    int qtNos;
};

typedef struct lista tLista; 

int ehSublista(tLista *l1, tLista *l2, int pos) {
    int i;

    for (i = 0; i < l1->qtNos; i++) {
        if (l2->vNos[pos + i] != l1->vNos[i]) {
            return 0;
        }
    }

    return 1;
}

void removerSublista(tLista *l1, tLista *l2) {
    int i;

    for (i = 0; i < l2->qtNos; i++) {
        if (ehSublista(l1, l2, i)) {
            int j, cont;
            for (j = i, cont = 0; cont < l1->qtNos; j++) {
                memcpy(&l2->vNos[j], &l2->vNos[j+1], (l2->qtNos - j - 1) * (sizeof(int)));
                l2->qtNos--;
            }
        }
    }
}