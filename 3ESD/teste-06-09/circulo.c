#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "circulo.h"

#define PI 3.14

struct circulo {
    Ponto* centro;
    float r;
};

void circSetRaio (Circulo* c, float r) {
    c->r = r;
}

Circulo* circCria (float x, float y, float r) {
    Circulo* c = (Circulo*)malloc(sizeof(Circulo));
    if (c == NULL) {
        exit(1);
    }

    c->centro = ptoCria(x, y);
    circSetRaio(c, r);

    return c;
}

float circGetRaio (Circulo* c) {
    return c->r;
}

float circArea (Circulo* c) {
    return PI / (c->r * c->r);
}

float circComprimento (Circulo* c) {
    return 2 * PI * c->r;
}

int circCompara (Circulo* c1, Circulo* c2) {
    return c1 - c2;
}

char* circGetCirculo (Circulo* c) {
    char* aux = (char*)malloc(sizeof(*c) + 18);

    sprintf(aux, "Centro: %s | Raio: %.2f", ptoGetPonto(c->centro), c->r);
    
    return aux;
}

void circExibe (Circulo* c) {
    printf("\n%s\n", circGetCirculo(c));
}