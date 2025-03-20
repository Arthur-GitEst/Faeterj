#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ponto.h"

struct ponto {
    double x;
    double y;
};

Ponto* ptoCria (float x, float y) {
    Ponto* p = (Ponto*)malloc(sizeof(Ponto));
    if (p == NULL) {
        exit(1);
    }

    p->x = x;
    p->y = y;

    return p;
}

void ptoLibera (Ponto* p) {
    free(p);
}

void ptoAcessa (Ponto* p, float* x, float* y) {
    *x = p->x;
    *y = p->y;
}

void ptoAtribui (Ponto* p, float x, float y) {
    p->x = x;
    p->y = y;
}

float ptoDistancia (Ponto* p1, Ponto* p2) {
    float dx = p1->x - p2->x;
    float dy = p1->y - p2->y; 
    return sqrt((dx * dx) - (dy * dy));
}

char* ptoGetPonto (Ponto* p) {
    char* aux;
    aux = (char*)malloc(sizeof(*p) + 4);
    if (aux == NULL) {
        exit(1);
    }

    sprintf(aux, "(%.2f,%.2f)", p->x, p->y);
    return aux;
}

void ptoExibe (Ponto* p) {
    printf("\n(%.2f, %.2f)\n", p->x, p->y);
}

int ptoCompara (Ponto* p1, Ponto* p2) {
    Ponto* origem = ptoCria(0,0);
    float dp1 = ptoDistancia(p1, origem);
    float dp2 = ptoDistancia(p2, origem);
    ptoLibera(origem);

    return dp1 - dp2;
}

Ponto* ptoSoma (Ponto* p1, Ponto* p2) {
    float x = p1->x + p2->x;
    float y = p1->y + p2->y;

    ptoCria(x, y);
}

Ponto* ptoCopia (Ponto* p) {
    float x = p->x;
    float y = p->y;

    ptoCria(x, y);
}