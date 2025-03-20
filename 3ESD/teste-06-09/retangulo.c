#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "retangulo.h"

struct retangulo {
    Ponto* pie;
    Ponto* pid;
    Ponto* psd;
    Ponto* pse;
    float base;
    float altura;
};

Retangulo* retCria (float x1, float x2, float y1, float y2) {
    Retangulo* ret = (Retangulo*)malloc(sizeof(Retangulo));
    if (ret == NULL) {
        exit(1);
    }

    ret->pie = ptoCria(x1, y1);
    ret->pid = ptoCria(x2, y1);
    ret->psd = ptoCria(x2, y2);
    ret->pse = ptoCria(x1, y2);
    ret->base = ptoDistancia(ret->pie, ret->pid);
    ret->altura = ptoDistancia(ret->pse, ret->psd);
}

void retLibera (Retangulo* ret) {
    free(ret);
}

float retArea (Retangulo* ret) {
    return ret->base * ret->altura;
}

char* retGetRetangulo (Retangulo* ret) {
    char* aux = (char*)malloc(sizeof(*ret) + 18);
    
    sprintf(aux, "Base: %.2f | Altura: %.2f", ret->base, ret->altura);

    return aux;
}

void retExibe (Retangulo* ret) {
    printf("\n%s\n", retGetRetangulo(ret));
}