typedef struct circulo Circulo;
#include "ponto.h"

Circulo* circCria (float x, float y, float r); 

void circSetRaio (Circulo* c, float r);

float circGetRaio (Circulo* c); 

float circArea (Circulo* c); 

float circComprimento (Circulo* c);

int circCompara (Circulo* c1, Circulo* c2); 

char* circGetCirculo (Circulo* c);

void circExibe (Circulo* c);

