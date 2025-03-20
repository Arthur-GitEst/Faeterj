typedef struct retangulo Retangulo;
#include "ponto.h"

Retangulo* retCria (float x1, float x2, float y1, float y2);

void retLibera (Retangulo* ret);

float retArea (Retangulo* ret);

char* retGetRetangulo (Retangulo* ret);

void retExibe (Retangulo* ret);
