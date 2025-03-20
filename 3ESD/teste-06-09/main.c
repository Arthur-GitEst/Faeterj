#include <stdio.h>
#include "ponto.h"
#include "circulo.h"
#include "retangulo.h"

int main () {
    Retangulo* ret1 = retCria (3, 6, 5, 7);
    Circulo* c1 = circCria(10, 2, 4);

    retExibe(ret1);

    return 0;
}