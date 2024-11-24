#include <stdio.h>
#include <stdlib.h>
#include "arvoreB.h"

struct noArvB {
    int chave[MAX + 1], nchaves;
    struct noArvB *filhos[MAX + 1];
};

struct noArvB *criaNo(int chave, struct noArvB *filho) {
    struct noArvB *novoNo;
    novoNo = (struct noArvB *)malloc(sizeof(struct noArvB));
    novoNo->chave[1] = chave;
    novoNo->nchaves = 1;
    novoNo->filhos[0] = raiz;
    novoNo->filhos[1] = filho;
    return novoNo;
}

void insereNoNo(int chave, int pos, struct noArvB *no, struct noArvB *filho) {
  int j = no->nchaves;
  while (j > pos) {
    no->chave[j + 1] = no->chave[j];
    no->filhos[j + 1] = no->filhos[j];
    j--;
  }
  no->chave[j + 1] = chave;
  no->filhos[j + 1] = filho;
  no->nchaves++;
}

void split(int chave, int *pval, int pos, struct noArvB *no, struct noArvB *filho, struct noArvB **novoNo) {
    int meio, j;

    if (pos > MIN)
        meio = MIN + 1;
    else
        meio = MIN;

    *novoNo = (struct noArvB *)malloc(sizeof(struct noArvB));
    j = meio + 1;
    while (j <= MAX) {
        (*novoNo)->chave[j - meio] = no->chave[j];
        (*novoNo)->filhos[j - meio] = no->filhos[j];
        j++;
    }
    no->nchaves = meio;
    (*novoNo)->nchaves = MAX - meio;

    if (pos <= MIN) {
        insereNoNo(chave, pos, no, filho);
    } else {
        insereNoNo(chave, pos - meio, *novoNo, filho);
    }
    *pval = no->chave[no->nchaves];
    (*novoNo)->filhos[0] = no->filhos[no->nchaves];
    no->nchaves--;
}

int alterarValorNoNo(int chave, int *pval, struct noArvB *no, struct noArvB **filho) {
    int pos;
    if (!no) {
        *pval = chave;
        *filho = NULL;
        return 1;
    }

    if (chave < no->chave[1]) {
        pos = 0;
    } else {
        for (pos = no->nchaves;
        (chave < no->chave[pos] && pos > 1); pos--)
        ;
        if (chave == no->chave[pos]) {
        printf("Duplicatas nao permitidas\n");
        return 0;
        }
    }
    if (alterarValorNoNo(chave, pval, no->filhos[pos], filho)) {
        if (no->nchaves < MAX) {
        insereNoNo(*pval, pos, no, *filho);
        } else {
        split(*pval, pval, pos, no, *filho, filho);
        return 1;
        }
    }
    return 0;
}

void insere(int chave) {
    int st, i;
    struct noArvB *filho;

    st = alterarValorNoNo(chave, &i, raiz, &filho);
    if (st)
    raiz = criaNo(i, filho);
}

void copiarSucessor(struct noArvB *no, int pos) {
    struct noArvB *novoNo;
    novoNo = no->filhos[pos];

    for (; novoNo->filhos[0] != NULL;)
    novoNo = novoNo->filhos[0];
    no->chave[pos] = novoNo->chave[1];
}

void removeValor(struct noArvB *no, int pos) {
    int i = pos + 1;
    while (i <= no->nchaves) {
        no->chave[i - 1] = no->chave[i];
        no->filhos[i - 1] = no->filhos[i];
        i++;
    }
    no->nchaves--;
}

void girarDireita(struct noArvB *no, int pos) {
    struct noArvB *auxNo = no->filhos[pos];
    int j = auxNo->nchaves;

    while (j > 0) {
        auxNo->chave[j + 1] = auxNo->chave[j];
        auxNo->filhos[j + 1] = auxNo->filhos[j];
    }
    auxNo->chave[1] = no->chave[pos];
    auxNo->filhos[1] = auxNo->filhos[0];
    auxNo->nchaves++;

    auxNo = no->filhos[pos - 1];
    no->chave[pos] = auxNo->chave[auxNo->nchaves];
    no->filhos[pos] = auxNo->filhos[auxNo->nchaves];
    auxNo->nchaves--;
    return;
}

void girarEsquerda(struct noArvB *no, int pos) {
    int j = 1;
    struct noArvB *auxNo = no->filhos[pos - 1];

    auxNo->nchaves++;
    auxNo->chave[auxNo->nchaves] = no->chave[pos];
    auxNo->filhos[auxNo->nchaves] = no->filhos[pos]->filhos[0];

    auxNo = no->filhos[pos];
    no->chave[pos] = auxNo->chave[1];
    auxNo->filhos[0] = auxNo->filhos[1];
    auxNo->nchaves--;

    while (j <= auxNo->nchaves) {
        auxNo->chave[j] = auxNo->chave[j + 1];
        auxNo->filhos[j] = auxNo->filhos[j + 1];
        j++;
    }
    return;
}

void merge(struct noArvB *no, int pos) {
    int j = 1;
    struct noArvB *auxNo1 = no->filhos[pos], *auxNo2 = no->filhos[pos - 1];

    auxNo2->nchaves++;
    auxNo2->chave[auxNo2->nchaves] = no->chave[pos];
    auxNo2->filhos[auxNo2->nchaves] = no->filhos[0];

    while (j <= auxNo1->nchaves) {
        auxNo2->nchaves++;
        auxNo2->chave[auxNo2->nchaves] = auxNo1->chave[j];
        auxNo2->filhos[auxNo2->nchaves] = auxNo1->filhos[j];
        j++;
    }

    j = pos;
    while (j < no->nchaves) {
        no->chave[j] = no->chave[j + 1];
        no->filhos[j] = no->filhos[j + 1];
        j++;
    }
    no->nchaves--;
    free(auxNo1);
}

void ajustaNo(struct noArvB *no, int pos) {
    if (!pos) {
        if (no->filhos[1]->nchaves > MIN) {
        girarEsquerda(no, 1);
        } else {
        merge(no, 1);
        }
    } else {
        if (no->nchaves != pos) {
        if (no->filhos[pos - 1]->nchaves > MIN) {
            girarDireita(no, pos);
        } else {
            if (no->filhos[pos + 1]->nchaves > MIN) {
            girarEsquerda(no, pos + 1);
            } else {
            merge(no, pos);
            }
        }
        } else {
        if (no->filhos[pos - 1]->nchaves > MIN)
            girarDireita(no, pos);
        else
            merge(no, pos);
        }
    }
}

int removeValorDoNo(int chave, struct noArvB *no) {
    int pos, st = 0;
    if (no) {
        if (chave < no->chave[1]) {
        pos = 0;
        st = 0;
        } else {
        for (pos = no->nchaves; (chave < no->chave[pos] && pos > 1); pos--)
            ;
        if (chave == no->chave[pos]) {
            st = 1;
        } else {
            st = 0;
        }
        }
        if (st) {
        if (no->filhos[pos - 1]) {
            copiarSucessor(no, pos);
            st = removeValorDoNo(no->chave[pos], no->filhos[pos]);
            if (st == 0) {
            printf("Valor nao encontrado\n");
            }
        } else {
            removeValor(no, pos);
        }
        } else {
        st = removeValorDoNo(chave, no->filhos[pos]);
        }
        if (no->filhos[pos]) {
        if (no->filhos[pos]->nchaves < MIN)
            ajustaNo(no, pos);
        }
    }
    return st;
}

void remover (int chave, struct noArvB *no) {
    struct noArvB *auxNo;
    if (!removeValorDoNo(chave, no)) {
        printf("Valor nao encontrado.\n");
        return;
    } else {
        if (no->nchaves == 0) {
        auxNo = no;
        no = no->filhos[0];
        free(auxNo);
        }
    }
    raiz = no;
    return;
}

void busca(int chave, int *pos, struct noArvB *no) {
    if (!no) {
        return;
    }

    if (chave < no->chave[1]) {
        *pos = 0;
    } else {
        for (*pos = no->nchaves;
        (chave < no->chave[*pos] && *pos > 1); (*pos)--)
        ;
        if (chave == no->chave[*pos]) {
        printf("%d se ennchavesra na arvore.", chave);
        return;
        }
    }
    busca(chave, pos, no->filhos[*pos]);
    return;
}

void percorre(struct noArvB *no) {
    int i;
    if (no) {
        for (i = 0; i < no->nchaves; i++) {
        percorre(no->filhos[i]);
        printf("%d ", no->chave[i + 1]);
        }
        percorre(no->filhos[i]);
    }
}