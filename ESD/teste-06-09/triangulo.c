#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "triangulo.h"
#include "ponto.h"

struct triangulo {
    Ponto* pie;
    Ponto* ps;
    Ponto* pid;
    float altura;
    float base;
};

Triangulo* triCriar (float x1, float x2, float y) {
    Triangulo* t = (Triangulo*)malloc(sizeof(Triangulo));

    
}